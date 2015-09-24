$NetBSD: patch-src_dispatch__common.c,v 1.3 2015/09/24 22:51:29 tnn Exp $

Native X has /usr/X11R7/lib/libGL.so.2.
Function must return a value if errx not declared with attr noreturn.

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
@@ -672,6 +672,7 @@ epoxy_get_proc_address(const char *name)
 #endif
     }
     errx(1, "Couldn't find current GLX or EGL context.\n");
+    return NULL;
 #endif
 }
 
