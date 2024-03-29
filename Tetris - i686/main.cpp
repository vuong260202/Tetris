#include "runGame.h"
using namespace std;


bool showPE( SDL_Renderer* ren , base screen )
{
    int x = screen.y + 5 * step;
    int y = screen.x + 10 * step;
    setColor( ren , BLACK_COLOR );

    SDL_Rect rt = {0, 0, width, height};
    renderIMG( ren, IMG_NEN, screen.y, screen.x);
    showIMG( IMG_NEN_2, ren, {screen.y + step, screen.x + step, 15 * step, 30 * step});


    //renderBG(ren , 1, 2, 3);

    screen.render_khung( ren );

    show( ren , "PLAY" , WHITE_COLOR, x + 10, y , 100 , 50, 48 );
    show( ren , "EXIT" , WHITE_COLOR, x + 10, y + 4 * step , 100 , 50, 48 );

    SDL_RenderPresent( ren );

    return event( 1, x, y);
}

int main(int argc, char* argv[])
{
    SDL_Window* win;
    SDL_Renderer* ren;

//----------------------------------------------
    srand(time(NULL));
    initSDL( win, ren );

    base screen;
    screen.init_khung();

    if( showPE( ren , screen ) == false ) return 0;

    while( true )
    {
        screen.init();
        int k = runGame( ren, screen );
        if( k == 0 ) return 0;
        if( k == 2 )
            if( showPE( ren , screen ) == false ) return 0;
    }
//----------------------------------------------
    SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}












