#include<SDL2/SDL.h>

const int LARGURA=800;
const int ALTURA=600;

typedef unsigned char uint8;

SDL_Renderer* atributos=NULL;


void setColor(uint8 r, uint8 g, uint8 b)
{
	SDL_SetRenderDrawColor(atributos,r,g,b,SDL_ALPHA_OPAQUE);
}

void setBackColor(uint8 r, uint8 g, uint8 b)
{
	setColor(r,g,b);
	SDL_RenderClear(atributos);
}


int main(int argc, char* argv[])
{
	SDL_Window* janela=NULL;
		
	SDL_Init(SDL_INIT_VIDEO);
	janela=SDL_CreateWindow("MOVENDO QUADRADO",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
	        LARGURA,ALTURA,SDL_WINDOW_SHOWN);
	
	atributos=SDL_CreateRenderer(janela,-1,SDL_RENDERER_ACCELERATED);
	
	setBackColor(0,255,128);
	
	setColor(255,0,0);
	SDL_Rect box;
	box.x=LARGURA/2;
	box.y=ALTURA/2;
	box.w=20;
	box.h=20;
	SDL_RenderFillRect(atributos,&box);
	
	bool continua=true;
	SDL_Event evento;
	
while(continua)
{
    while(SDL_PollEvent(&evento))
    {
        switch(evento.type)
        {
            case SDL_QUIT:
                continua=false;    
                break;
            case SDL_KEYDOWN:
                switch(evento.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continua=false;
                        break;
                    case SDLK_LEFT:
                        if (box.x - 15 >= 0) // Verifica se a posição do quadrado não ultrapassa o limite esquerdo
                            box.x -= 15;
                        break;
                    case SDLK_RIGHT:
                        if (box.x + box.w + 15 <= LARGURA) // Verifica se a posição do quadrado não ultrapassa o limite direito
                            box.x += 15;
                        break;
                    case SDLK_UP:
                        if (box.y - 15 >= 0) // Verifica se a posição do quadrado não ultrapassa o limite superior
                            box.y -= 15;
                        break;
                    case SDLK_DOWN:
                        if (box.y + box.h + 15 <= ALTURA) // Verifica se a posição do quadrado não ultrapassa o limite inferior
                            box.y += 15;
                        break;
                }
        }
    }   
    
    setBackColor(0,255,128);
    setColor(255,0,0);
    SDL_RenderFillRect(atributos,&box);   
    SDL_RenderPresent(atributos);            
}

		
	      
	//SDL_Delay(5000);
	SDL_DestroyWindow(janela);
	SDL_Quit();
	return 0;
}
