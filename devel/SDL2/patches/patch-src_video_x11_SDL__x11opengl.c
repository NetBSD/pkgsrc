$NetBSD: patch-src_video_x11_SDL__x11opengl.c,v 1.1 2015/02/03 08:50:44 snj Exp $

NetBSD's libGL version differs between xsrc and pkgsc.  All hail the
mighty symlink.

--- src/video/x11/SDL_x11opengl.c.orig	2014-03-15 19:31:44.000000000 -0700
+++ src/video/x11/SDL_x11opengl.c	2015-02-03 00:25:04.000000000 -0800
@@ -38,6 +38,8 @@
 #define DEFAULT_OPENGL  "/usr/X11R6/lib/libGL.1.dylib"
 #elif defined(__QNXNTO__)
 #define DEFAULT_OPENGL  "libGL.so.3"
+#elif defined(__NetBSD__)
+#define DEFAULT_OPENGL  "libGL.so"
 #else
 #define DEFAULT_OPENGL  "libGL.so.1"
 #endif
