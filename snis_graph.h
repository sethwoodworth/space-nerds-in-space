#ifndef SNIS_GRAPH_H__
#define SNIS_GRAPH_H__

#ifdef SNIS_GRAPH_DECLARE_GLOBALS
#define SNG_GLOBAL
#define INIT(y) = y
#else
#define SNG_GLOBAL extern
#define INIT(y)
#endif

/* cardinal color indexes into huex array */
#define BLACK 0
#define WHITE 1
extern int BLUE;
extern int GREEN;
#define YELLOW 2
#define RED 3
#define ORANGE 4
extern int CYAN;
#define MAGENTA 5
#define DARKGREEN 6
#define DARKRED 7
#define AMBER 8
#define LIMEGREEN 9
#define DARKTURQUOISE 10
#define ORANGERED 11

#define NCOLORS 12              /* number of "cardinal" colors */
#define NSPARKCOLORS 25         /* 25 shades from yellow to red for the sparks */
#define NRAINBOWSTEPS (16)
#define NRAINBOWCOLORS (NRAINBOWSTEPS*3)
#define GRAY (NCOLORS + NSPARKCOLORS + NRAINBOWCOLORS)
#define NSHADESOFGRAY 256
#define NSHADECOLORS 10
#define GRADIENTS (GRAY + NSHADESOFGRAY + NSHADECOLORS*NSHADESOFGRAY)
#define NGRADIENTS 3
#define NGRADIENT_SHADES 16
#define NTOTAL_GRADIENT_SHADES (NGRADIENT_SHADES*2 + 1)

#define COLOR_DARKER(c,p) (c-(p*NGRADIENT_SHADES/100))
#define COLOR_LIGHTER(c, p) (c+(p*NGRADIENT_SHADES/100))

struct my_vect_obj;

struct sng_dotted_plot_func_context {
        GdkDrawable *drawable;
        GdkGC *gc;
        int i;
};

struct sng_color {
	/* color channel range 0 to 1 */
	float red;
	float green;
	float blue;
};

extern void sng_set_scale(float xscale, float yscale);

extern void sng_current_draw_line(GdkDrawable *drawable, GdkGC *gc, float x1, float y1, float x2, float y2);
extern void sng_current_draw_thick_line(GdkDrawable *drawable, GdkGC *gc, float x1, float y1, float x2, float y2);
extern void sng_current_draw_rectangle(GdkDrawable *drawable,
	GdkGC *gc, gboolean filled, float x, float y, float width, float height);
extern void sng_current_draw_bright_line(GdkDrawable *drawable,
	GdkGC *gc, float x1, float y1, float x2, float y2, int color);
extern void sng_current_draw_arc(GdkDrawable *drawable, GdkGC *gc,
	gboolean filled, float x, float y, float width, float height, float angle1, float angle2);

SNG_GLOBAL void sng_dotted_line_plot_func(int x, int y, void *context);
SNG_GLOBAL void sng_electric_line_plot_func(int x, int y, void *context);
SNG_GLOBAL void sng_draw_dotted_line(GdkDrawable *drawable,
	GdkGC *gc, float x1, float y1, float x2, float y2);
SNG_GLOBAL void sng_draw_electric_line(GdkDrawable *drawable,
	GdkGC *gc, float x1, float y1, float x2, float y2);

SNG_GLOBAL void sng_draw_vect_obj(GtkWidget *w, GdkGC *gc, struct my_vect_obj *v, float x, float y);
SNG_GLOBAL float sng_abs_xy_draw_letter(GtkWidget *w, GdkGC *gc, struct my_vect_obj **font, 
		unsigned char letter, float x, float y);
SNG_GLOBAL void sng_abs_xy_draw_string(GtkWidget *w, GdkGC *gc, char *s, int font, float x, float y) ;
SNG_GLOBAL void sng_abs_xy_draw_string_with_cursor(GtkWidget *w, GdkGC *gc,
				char *s, int font, float x, float y, int cursor_pos, int cursor_on) ;
SNG_GLOBAL void sng_center_xy_draw_string(GtkWidget *w, GdkGC *gc, char *s, int font, float x, float y);
SNG_GLOBAL void sng_draw_point(GdkDrawable *drawable, GdkGC *gc, float x, float y);
SNG_GLOBAL void sng_setup_colors(GtkWidget *w);
SNG_GLOBAL void sng_set_foreground(int c);
SNG_GLOBAL void sng_set_foreground_alpha(int c, float a);
SNG_GLOBAL struct sng_color sng_get_foreground();
SNG_GLOBAL struct sng_color sng_get_color(int c);
SNG_GLOBAL void sng_set_context(GdkDrawable *drawable, GdkGC *gc);
SNG_GLOBAL void sng_draw_circle(GdkDrawable *drawable, GdkGC *gc, int filled, float x, float y, float r);
SNG_GLOBAL void sng_draw_laser_line(GdkDrawable *drawable, GdkGC *gc,
			float x1, float y1, float x2, float y2, int color);

/* pixel size of the actual output window */
SNG_GLOBAL void sng_set_screen_size(int width, int height);

/* size of the extent given to primitive drawing functions */
SNG_GLOBAL void sng_set_extent_size(int width, int height);

/* clip inside the extent */
SNG_GLOBAL void sng_set_clip_window(int x1, int y1, int x2, int y2);

/* offet and scale 3d rendering inside extent bounds */
SNG_GLOBAL void sng_set_3d_viewport(int x_offset, int y_offset, int width, int height);

SNG_GLOBAL char *sng_load_png_texture(const char *filename, int flipVertical, int flipHorizontal, int *w, int *h,
			int *hasAlpha, char *whynot, int whynotlen);

SNG_GLOBAL void sng_setup_colors(GtkWidget *w);
#undef SNG_GLOBAL
#endif
