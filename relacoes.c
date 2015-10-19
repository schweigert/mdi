/////////////////////////////////
/// TRABALHO DE MDI           ///
/// Made with ♥ by:           ///
///   Marlon Henry Schweigert ///
/////////////////////////////////

/////////////////////////////////
/// TRABALHO DE MATEMATICA    ///
/// DISCRETA. PROF:           ///
///   Chidabaram Chidabaram   ///
/////////////////////////////////


///////////////////////////////////////////////////
// RELAÇÕES TRANSITIVAS, REFLEXIVAS E SIMÉTRICAS //
///////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

void EscreverComparacao (int **m,int pos1,int pos2, int A, int B);

char op, comp;
int res;

int main (void){

	int tamLeitura = 0;
	
	printf ("DIGITE O NUMERO DE ELEMENTOS NO VETOR: \t");
	scanf ("%d", &tamLeitura);
	
	int *elementos = NULL;
	int *auxelem = NULL;
	
	auxelem = malloc(sizeof(int)*tamLeitura);
	
	if (auxelem == NULL){
		printf("ERRO AO ALOCAR MEMÓRIA\n");
		exit(EXIT_FAILURE);
	}
	
	elementos = auxelem;
	
	int i = 0;
	
	for (i = 0; i < tamLeitura; i++){
		
		printf ("DIGITE O VALOR DA POSICAO #%d: \t",i);
		scanf ("%d",&elementos[i]);
		puts("");
		
	}
	getchar();
	
	printf("Qual a operação a ser realizada entre os termos?\n");
	printf("Insira +, -, * ou /\n");
	scanf("%c", &op);
	getchar();
	printf("O resultado da operação deve ser igual, diferente, maior ou menor que um valor x?\n");
	printf("Ou deve ser divisível por um valor x?\n");
	printf("Insira =, !, >, < ou d\n");
	scanf("%c", &comp);
	printf("Qual é este valor x?\n");
	scanf("%d", &res);
	
	int **mat = NULL;
	int *vetorz = NULL;
	
	mat = malloc(sizeof(int*) *tamLeitura);
	vetorz = malloc(sizeof(int)*tamLeitura*tamLeitura);
	
	if(mat == NULL || vetorz == NULL){
		printf ("ERRO AO ALOCAR MEMÓRIA");
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; i < tamLeitura;i++){
		
		mat[i] = &vetorz[tamLeitura*i];
		
	}
	
	int x,y,z;
	
	printf ("\t");
	// IMPRIMIR TABELA
	for (x = 0; x < tamLeitura; x++){
		printf("%d\t",elementos[x]);
	}
	printf("\n");
	for (x = 0; x < tamLeitura; x++){
		printf ("%d|\t",elementos[x]);
		for (y = 0; y < tamLeitura; y++){
		
			EscreverComparacao(mat,x,y,elementos[x],elementos[y]);
			printf("%d\t",mat[x][y]);
			
		}
		printf ("\n");
	}
	
	int verd = 0;
	int verd1 = 1;
	int verd2 = 1;
	for (x = 0; x < tamLeitura; x++){
		
		verd += mat[x][x];
		
		for (y = 0; y < tamLeitura && verd1; y++){
			
			if (mat[x][y] != mat[y][x]){
				verd1 = 0;
				break;
			}
		}
		for (y=0; y < tamLeitura && verd2; y++){
			for (z=0; z < tamLeitura; z++){
				if(mat[x][y]&&mat[y][z]&&!mat[x][z]){
					verd2 = 0;
					break;
				}
			}
		}
		
	}
	
	if (verd/(x-1) == 1) printf ("REFLEXIVA!\n");
	if (verd1) printf ("SIMÉTRICA!\n");
	if (verd2) printf ("TRANSITIVA!\n");
	
	return 0;
}



void EscreverComparacao (int **m,int pos1,int pos2, int A, int B){
	
	int r;
	
	switch(op){
		case '+':
			r=A+B;
			break;
		case '-':
			r=A-B;
			break;
		case '*':
			r=A*B;
			break;
		case '/':
			r=A/B;
			break;
	}
	switch(comp){
		case '=':
			m[pos1][pos2] = (r==res);
			break;
		case '!':
			m[pos1][pos2] = (r!=res);
			break;
		case '>':
			m[pos1][pos2] = (r>res);
			break;
		case '<':
			m[pos1][pos2] = (r<res);
			break;
		case 'd':
			m[pos1][pos2] = (r%res==0);
			break;
	}
	
}
