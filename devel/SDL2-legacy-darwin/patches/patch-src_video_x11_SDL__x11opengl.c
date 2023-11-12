$NetBSD: patch-src_video_x11_SDL__x11opengl.c,v 1.1 2023/11/12 21:28:04 nia Exp $

NetBSD support. This was upstreamed a long time ago.
We can have different versioning systems depending on modular xorg vs. xsrc.

--- src/video/x11/SDL_x11opengl.c.orig	2014-03-16 02:31:44.000000000 +0000
+++ src/video/x11/SDL_x11opengl.c
@@ -31,7 +31,7 @@
 #include "SDL_loadso.h"
 #include "SDL_x11opengles.h"
 
-#if defined(__IRIX__)
+#if defined(__IRIX__) || defined(__NetBSD__)
 /* IRIX doesn't have a GL library versioning system */
 #define DEFAULT_OPENGL  "libGL.so"
 #elif defined(__MACOSX__)
