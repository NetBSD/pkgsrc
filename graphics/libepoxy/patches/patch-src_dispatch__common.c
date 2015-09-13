$NetBSD: patch-src_dispatch__common.c,v 1.2 2015/09/13 04:44:49 tnn Exp $

Native X has /usr/X11R7/lib/libGL.so.2.

--- src/dispatch_common.c.orig	2015-07-15 23:46:36.000000000 +0000
+++ src/dispatch_common.c
@@ -107,7 +107,7 @@
 #elif defined(ANDROID)
 #define GLX_LIB "libGLESv2.so"
 #else
-#define GLX_LIB "libGL.so.1"
+#define GLX_LIB "libGL.so"
 #endif
 
 #ifdef ANDROID
