$NetBSD: patch-src_video_x11_SDL__x11opengl.c,v 1.3 2020/03/17 12:49:29 nia Exp $

NetBSD's libGL version differs between xsrc and pkgsc.  All hail the
mighty symlink.

--- src/video/x11/SDL_x11opengl.c.orig	2020-03-11 01:36:18.000000000 +0000
+++ src/video/x11/SDL_x11opengl.c
@@ -32,7 +32,8 @@
 #include "SDL_loadso.h"
 #include "SDL_x11opengles.h"
 
-#if defined(__IRIX__)
+#if defined(__IRIX__) || defined(__NetBSD__)
+/* NetBSD has different libGL versions in the base system and packages */
 /* IRIX doesn't have a GL library versioning system */
 #define DEFAULT_OPENGL  "libGL.so"
 #elif defined(__MACOSX__)
