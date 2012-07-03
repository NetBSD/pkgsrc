$NetBSD: patch-c__stuff_fb__c__stuff.xs,v 1.1 2012/07/03 18:43:37 joerg Exp $

--- c_stuff/fb_c_stuff.xs.orig	2012-07-03 14:35:36.000000000 +0000
+++ c_stuff/fb_c_stuff.xs
@@ -96,14 +96,12 @@ int rand_(double val) { return 1+(int) (
 
 void store_effect(SDL_Surface * s, SDL_Surface * img)
 {
-	void copy_line(int l) {
-		memcpy(s->pixels + l*img->pitch, img->pixels + l*img->pitch, img->pitch);
-	}
-	void copy_column(int c) {
-		int bpp = img->format->BytesPerPixel;
-		for (y=0; y<YRES; y++)
-			memcpy(s->pixels + y*img->pitch + c*bpp, img->pixels + y*img->pitch + c*bpp, bpp);
-	}
+#define copy_line(l) memcpy(s->pixels + l*img->pitch, img->pixels + l*img->pitch, img->pitch)
+#define copy_column(c) do { \
+		int bpp = img->format->BytesPerPixel; \
+		for (y=0; y<YRES; y++) \
+			memcpy(s->pixels + y*img->pitch + c*bpp, img->pixels + y*img->pitch + c*bpp, bpp); \
+	} while (0)
 
 	int step = 0;
 	int store_thickness = 15;
@@ -181,15 +179,8 @@ void squares_effect(SDL_Surface * s, SDL
 	int bpp = img->format->BytesPerPixel;
 	const int squares_size = 32;
 
-	int fillrect(int i, int j) {
-		int c, v;
-		if (i >= XRES/squares_size || j >= YRES/squares_size)
-			return 0;
-		v = i*squares_size*bpp + j*squares_size*img->pitch;
-		for (c=0; c<squares_size; c++)
-			memcpy(s->pixels + v + c*img->pitch, img->pixels + v + c*img->pitch, squares_size*bpp);
-		return 1;
-	}
+#define fillrect(i, j) \
+	} while (0)
 
 	int still_moving = 1;
 
@@ -200,8 +191,13 @@ void squares_effect(SDL_Surface * s, SDL
 
 		still_moving = 0;
 		for (j=i; j>=0; j--) {
-			if (fillrect(j, k))
-				still_moving = 1;
+			if (i >= XRES/squares_size || j >= YRES/squares_size)
+				continue;
+			int c, v;
+			v = i*squares_size*bpp + j*squares_size*img->pitch;
+			for (c=0; c<squares_size; c++)
+				memcpy(s->pixels + v + c*img->pitch, img->pixels + v + c*img->pitch, squares_size*bpp);
+			still_moving = 1;
 			k++;
 		}
 
@@ -211,12 +207,12 @@ void squares_effect(SDL_Surface * s, SDL
 
 
 /* -------------- Circle ------------------ */
+#define sqr(v) ((v) * (v))
 
 int * circle_steps;
 const int circle_max_steps = 40;
 void circle_init(void)
 {
-	int sqr(int v) { return v*v; }
 
 	circle_steps = malloc(XRES * YRES * sizeof(int));
 	if (!circle_steps)
@@ -229,6 +225,7 @@ void circle_init(void)
 			circle_steps[x+y*XRES] = (max-value)*circle_max_steps/max;
 		}
 }
+#undef sqr
 
 void circle_effect(SDL_Surface * s, SDL_Surface * img)
 {
