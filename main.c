/*
 * Este programa resuelve los valores de x de una ecuacion cuadratica
 * con el uso de la formula general, el usuario ingresa las variables
 * a,b y c, y el programa lo resolvera en caso posible.
 *
 * Autor: Jonathan Nuñez de Caceres.
 * Fecha: 4 de Octubre del 2018.
 * Correo: A01411277@itesm.mx
 */

// Libreria de entrada y salida estandar
#include <stdio.h>
// Libreria estandar
#include <stdlib.h>
// Libreria para manipulacion de arreglos de caracteres.
#include <string.h>
// Libreria de matematicas.
#include <math.h>

// Funcion que valida si el valor ingresado es un numero.
int Validate(char a[], double* x){
    char *end;
    int flag = 0;

    // Con esta funcion se convierte de string a double.
    *x = strtod(a, &end);

    // Cuando el valor que ingreso el usuario tiene 9 caracteres,
    // end, que es el texto que se extrae de el valor tiene que tener
    // una longitud igual a 0 para ser valida.
    if(strlen(a) == 9){
        if(strlen(end) > 0){
            printf("No valido.\n");
            flag = 1;
        }
    }
    // Cuando no tiene los 9 caracteres, end tiene que ser menor o igual a 1,
    // ya que se cuenta la nueva linea.
    else{
        if(strlen(end) > 1){
            printf("No valido.\n");
            flag = 1;
        }
    }
    // Si no es valido se regresa un 1.
    return flag;
}




int main() {
    // Declaracion de variables.
    char a[10];
    double num_a;
    char b[10];
    double num_b;
    char c[10];
    double num_c;
    int cond;
    double discriminant;
    double x1;
    double x2;

    // Se pide el valor de a.
    do{
        printf("Ingresa el valor de a:");
        fgets(a, sizeof(a), stdin);
        // Se vacia el buffer del teclado por si el usuario
        // se pasa de 9 caracteres no haya problemas.
        fflush(stdin);
        cond = Validate(a, &num_a);
        if(!num_a){
            printf("a no puede ser igual a 0\n");
            cond = 1;
        }
    } while(cond);

    // Se pide el valor de b.
    do{
        printf("Ingresa el valor de b:");
        fgets(b, sizeof(b), stdin);
        fflush(stdin);
        cond = Validate(b, &num_b);
    } while(cond);

    // Se pide el valor de c.
    do{
        printf("Ingresa el valor de c:");
        fgets(c, sizeof(c), stdin);
        fflush(stdin);
        cond = Validate(c, &num_c);
    } while(cond);


    // Se saca el discriminate (lo que esta dentro de la raiz).
    discriminant = pow(num_b,2) - 4 * num_a * num_c;

    // Si el discriminante es mayor a 0 se tienen dos respuestas.
    if(discriminant > 0){
        x1 = (-num_b + sqrt(discriminant)) / (2 * num_a);
        x2 = (-num_b - sqrt(discriminant)) / (2 * num_a);

        printf("\nx1 = %lf", x1);
        printf("\nx2 = %lf", x2);
    // Si el discriminante es igual a 0 se tiene una respuesta.
    } else if(discriminant == 0){
        x1 = (-num_b + sqrt(discriminant)) / 2 * num_a;
        printf("\nx = %lf", x1);
    // Si es memor a 0 no se puede resolver.
    } else{
        printf("\nNo se puede calcular el discriminante.");
    }

    return 0;
}