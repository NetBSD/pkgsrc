$NetBSD: patch-src_dispatch__common.c,v 1.1 2015/06/14 21:50:07 prlw1 Exp $

Native X has /usr/X11R7/lib/libGL.so.2.

--- src/dispatch_common.c.orig	2014-05-14 00:22:08.000000000 +0000
+++ src/dispatch_common.c
@@ -105,7 +105,7 @@
 #ifdef __APPLE__
 #define GLX_LIB "/opt/X11/lib/libGL.1.dylib"
 #else
-#define GLX_LIB "libGL.so.1"
+#define GLX_LIB "libGL.so"
 #endif
 
 struct api {
