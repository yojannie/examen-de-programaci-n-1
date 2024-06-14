#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class usuario {
public:
    string nombre;
    string tipo;
    int reciclaje_plasticos;
    int reciclaje_cartones;
    int reciclaje_aluminio;

    usuario(string nombre, string tipo) {
        this->nombre = nombre;
        this->tipo = tipo;
        reciclaje_plasticos = 0;
        reciclaje_cartones = 0;
        reciclaje_aluminio = 0;
    }
    void registrar_reciclaje(string material, int cantidad) {
        if (material == "plasticos") {
            reciclaje_plasticos += cantidad;
        } else if (material == "cartones") {
            reciclaje_cartones += cantidad;
        } else if (material == "aluminio") {
            reciclaje_aluminio += cantidad;
        }
    }
    int obtener_reciclaje_total() {
        return reciclaje_plasticos + reciclaje_cartones + reciclaje_aluminio;
    }
};
void mostrar_estadisticas(vector<usuario>& usuarios) {
    int total_plasticos = 0, total_cartones = 0, total_aluminio = 0;
    int mayor_reciclaje = 0;
    string usuario_mayor_reciclaje;
    string tipo_usuario_mayor_reciclaje;

    for (size_t i = 0; i < usuarios.size(); ++i) {
        total_plasticos += usuarios[i].reciclaje_plasticos;
        total_cartones += usuarios[i].reciclaje_cartones;
        total_aluminio += usuarios[i].reciclaje_aluminio;

        int total_reciclado = usuarios[i].obtener_reciclaje_total();
        if (total_reciclado > mayor_reciclaje) {
            mayor_reciclaje = total_reciclado;
            usuario_mayor_reciclaje = usuarios[i].nombre;
            tipo_usuario_mayor_reciclaje = usuarios[i].tipo;
        }
    }
    printf("estadisticas de reciclaje:\n");
    printf("total plasticos reciclados: %d\n", total_plasticos);
    printf("total cartones reciclados: %d\n", total_cartones);
    printf("total aluminio reciclado: %d\n", total_aluminio);

    if (!usuario_mayor_reciclaje.empty()) {
        printf("el usuario con mayor porcentaje de reciclaje es: %s con un total de %d unidades recicladas.\n",
               usuario_mayor_reciclaje.c_str(), mayor_reciclaje);
        if (tipo_usuario_mayor_reciclaje == "ciudadano") {
            printf("recompensa: 20%% de descuento en cualquier tienda a elegir.\n");
        } else if (tipo_usuario_mayor_reciclaje == "estudiante") {
            printf("recompensa: entradas dobles para el parque de diversiones.\n");
        }
    }
}
int main() {
    vector<usuario> usuarios;
    char continuar;

    printf("bienvenido al sistema de gestion de reciclaje.\n");

    do {
        string nombre;
        string tipo_usuario;

        printf("\ningreso de nuevo usuario:\n");
        printf("ingrese el nombre del usuario: ");
        cin >> nombre;

        do {
            printf("es usted estudiante? (s/n): ");
            char respuesta;
            scanf(" %c", &respuesta);

            if (respuesta == 's' || respuesta == 'S') {
                tipo_usuario = "estudiante";
                break;
            } else if (respuesta == 'n' || respuesta == 'N') {
                tipo_usuario = "ciudadano";
                break;
            } else {
                printf("opcion no valida. por favor, responda con 's' o 'n'.\n");
            }
        } while (true);

        usuario nuevo_usuario(nombre, tipo_usuario);
        usuarios.push_back(nuevo_usuario);

        printf("desea ingresar otro usuario? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    for (size_t i = 0; i < usuarios.size(); ++i) {
        int cantidad_plasticos, cantidad_cartones, cantidad_aluminio;

        printf("\nregistro de reciclaje para %s:\n", usuarios[i].nombre.c_str());

        printf("ingrese la cantidad de plasticos reciclados: ");
        scanf("%d", &cantidad_plasticos);
        usuarios[i].registrar_reciclaje("plasticos", cantidad_plasticos);

        printf("ingrese la cantidad de cartones reciclados: ");
        scanf("%d", &cantidad_cartones);
        usuarios[i].registrar_reciclaje("cartones", cantidad_cartones);

        printf("ingrese la cantidad de aluminio reciclado: ");
        scanf("%d", &cantidad_aluminio);
        usuarios[i].registrar_reciclaje("aluminio", cantidad_aluminio);
    }

    mostrar_estadisticas(usuarios);

    return 0;
}


