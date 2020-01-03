$NetBSD: patch-window_SDL__rotozoom.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- avoid use of float and use long long instead to avoid overflow

--- window/SDL_rotozoom.cc.orig	2008-01-06 05:17:14.000000000 +0000
+++ window/SDL_rotozoom.cc
@@ -42,11 +42,11 @@ int zoomSurfaceRGBA(SDL_Surface * src, S
 	/*
 	 * smaller to avoid overflow on right and bottom edge.     
 	 */
-	sx = (int) (65536.0 * (float) (src->w - 1) / (float) dst->w);
-	sy = (int) (65536.0 * (float) (src->h - 1) / (float) dst->h);
+	sx = (int) (65536 * (long long) (src->w - 1) / (long long) dst->w);
+	sy = (int) (65536 * (long long) (src->h - 1) / (long long) dst->h);
     } else {
-	sx = (int) (65536.0 * (float) src->w / (float) dst->w);
-	sy = (int) (65536.0 * (float) src->h / (float) dst->h);
+	sx = (int) (65536 * (long long) src->w / (long long) dst->w);
+	sy = (int) (65536 * (long long) src->h / (long long) dst->h);
     }
 
     /*
@@ -221,8 +221,8 @@ int zoomSurfaceY(SDL_Surface * src, SDL_
     /*
      * Variable setup 
      */
-    sx = (Uint32) (65536.0 * (float) src->w / (float) dst->w);
-    sy = (Uint32) (65536.0 * (float) src->h / (float) dst->h);
+    sx = (Uint32) (65536 * (long long) src->w / (long long) dst->w);
+    sy = (Uint32) (65536 * (long long) src->h / (long long) dst->h);
 
     /*
      * Allocate memory for row increments 
