$NetBSD: patch-src_SDL__Pango.c,v 1.1 2014/04/17 20:17:18 joerg Exp $

--- src/SDL_Pango.c.orig	2014-04-17 14:27:56.000000000 +0000
+++ src/SDL_Pango.c
@@ -284,6 +284,14 @@ typedef struct _contextImpl {
     int min_width;
     int min_height;
 } contextImpl;
+
+void
+SDLPango_CopyFTBitmapToSurface(
+    const FT_Bitmap *bitmap,
+    SDL_Surface *surface,
+    const SDLPango_Matrix *matrix,
+    SDL_Rect *rect);
+
 
 
 /*!
