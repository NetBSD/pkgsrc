$NetBSD: patch-src_video_cocoa_SDL__cocoavideo.m,v 1.1 2023/11/12 21:28:04 nia Exp $

The altivec header inclusion does not appear to be used in these files, and
breaks non-Altivec builds.

--- src/video/cocoa/SDL_cocoavideo.m.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/video/cocoa/SDL_cocoavideo.m
@@ -22,13 +22,6 @@
 
 #if SDL_VIDEO_DRIVER_COCOA
 
-#if defined(__APPLE__) && defined(__POWERPC__) && !defined(__APPLE_ALTIVEC__)
-#include <altivec.h>
-#undef bool
-#undef vector
-#undef pixel
-#endif
-
 #include "SDL.h"
 #include "SDL_endian.h"
 #include "SDL_cocoavideo.h"
