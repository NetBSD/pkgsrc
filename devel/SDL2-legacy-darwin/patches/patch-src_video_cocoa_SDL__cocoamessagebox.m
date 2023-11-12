$NetBSD: patch-src_video_cocoa_SDL__cocoamessagebox.m,v 1.1 2023/11/12 21:28:04 nia Exp $

The altivec header inclusion does not appear to be used in these files, and
breaks non-Altivec builds.

--- src/video/cocoa/SDL_cocoamessagebox.m.orig	2014-03-16 02:31:45.000000000 +0000
+++ src/video/cocoa/SDL_cocoamessagebox.m
@@ -22,13 +22,6 @@
 
 #if SDL_VIDEO_DRIVER_COCOA
 
-#if defined(__APPLE__) && defined(__POWERPC__) && !defined(__APPLE_ALTIVEC__)
-#include <altivec.h>
-#undef bool
-#undef vector
-#undef pixel
-#endif
-
 #include "SDL_events.h"
 #include "SDL_timer.h"
 #include "SDL_messagebox.h"
