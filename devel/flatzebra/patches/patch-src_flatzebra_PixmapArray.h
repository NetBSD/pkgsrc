$NetBSD: patch-src_flatzebra_PixmapArray.h,v 1.1 2026/01/05 21:32:30 ktnb Exp $

Point to SDL2

--- src/flatzebra/PixmapArray.h.orig	2026-01-04 02:31:40.349165312 +0000
+++ src/flatzebra/PixmapArray.h
@@ -24,8 +24,8 @@
 
 #include <flatzebra/Couple.h>
 
-#include <SDL.h>
-#include <SDL_image.h>
+#include <SDL2/SDL.h>
+#include <SDL2/SDL_image.h>
 
 #include <assert.h>
 #include <vector>
