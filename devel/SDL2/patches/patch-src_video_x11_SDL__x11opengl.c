$NetBSD: patch-src_video_x11_SDL__x11opengl.c,v 1.2 2017/01/26 03:46:20 nat Exp $

NetBSD's libGL version differs between xsrc and pkgsc.  All hail the
mighty symlink.

--- src/video/x11/SDL_x11opengl.c.orig	2016-10-20 03:56:26.000000000 +0000
+++ src/video/x11/SDL_x11opengl.c
@@ -38,6 +38,8 @@
 #define DEFAULT_OPENGL  "/usr/X11R6/lib/libGL.1.dylib"
 #elif defined(__QNXNTO__)
 #define DEFAULT_OPENGL  "libGL.so.3"
+#elif defined(__NetBSD__)
+#define DEFAULT_OPENGL  "libGL.so"
 #else
 #define DEFAULT_OPENGL  "libGL.so.1"
 #endif
