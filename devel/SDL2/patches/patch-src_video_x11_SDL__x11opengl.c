$NetBSD: patch-src_video_x11_SDL__x11opengl.c,v 1.4 2020/04/05 16:24:28 nia Exp $

NetBSD's libGL version differs between xsrc and pkgsrc.  All hail the
mighty symlink.

https://bugzilla.libsdl.org/show_bug.cgi?id=5075

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
