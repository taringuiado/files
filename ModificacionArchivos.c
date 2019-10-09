#include<stdio.h>
#include <string.h>

//Manupulacion de ficheros en c
 struct registro {
 	char nombre[20];
 	int cedula;
 }estudiante;


int main() {
	char nombre2[20];
	int op,op2; 
	FILE *arch;
	printf("Agregar,ver,buscar,eliminar estudiantes\n\n");
	do{
	printf("\t1-Ingresar nuevo estudiante\n\t2-Ver los estudiantes\n\t3-Buscar estudiante\n\t4-Borrar todos los estudiantes\n\t5-Salir\n\n");
	scanf("%d",&op);
	getchar();
	switch (op) {
			case 1 : //Ingresar estudiante
				do {
					printf ("\n\tIngrese el NOMBRE del estudiante:\n");
					gets (estudiante.nombre);
					printf ("\n\tIngrese la CEDULA del estudiante:\n");
					scanf ("%d",&estudiante.cedula);
		
					arch = fopen("matricula.txt","a+");
					fwrite(&estudiante,sizeof(estudiante),1,arch);
					fclose(arch);
					printf("\n\t¿Agregar otro estudiante? (1:si/2:no)\n\n");
					scanf("%d",&op2);
					getchar();
					} while (op2==1);
			break;
			case 2 : //Mostrar todos los estudiantes
			arch = fopen("matricula.txt","a+");
				while (!feof(arch)) {
				fread (&estudiante,sizeof(estudiante),1,arch);
				if (!feof(arch)){
					printf("\n\tNombre: %s \n\tCedula: %d\n\n",estudiante.nombre,estudiante.cedula);
					puts("");
				} 
			}
	
			fclose(arch);
			break;
			
			case 3:  //Buscar estudiante 
			printf("\n\tIngrese el NOMBRE del estudiante que desea encontrar:\n");
			gets(nombre2);
			arch = fopen("matricula.txt","a+");
			while (!feof(arch)){
				fread(&estudiante,sizeof(estudiante),1,arch);
				if(!feof(arch)){
					if(strstr(nombre2,estudiante.nombre)!=NULL){
						printf("\n\tEL NOMBRE SE ENCONTRO\n\n\tNombre:%s\n\tCedula:%d\n\n",estudiante.nombre,estudiante.cedula);
					}else printf("\nEl nombre que escribio no se encuentra en el registro\n\n");
				}
			}
			fclose(arch);
			break;	
				
			case 4: //Borrar todos los estudiantes
			arch = fopen ("matricula.txt","w");
			fclose(arch);
			break;
			
			case 5: puts("Datos guardados...");
			break;
			
			default: printf("La opcion no es correcta.\n\n");
	}	
}while (op!=5);

}
	
	
	
