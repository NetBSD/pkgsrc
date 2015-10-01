$NetBSD: patch-src_dispatch__common.c,v 1.4 2015/10/01 13:50:05 tnn Exp $

Deal with hardcoded libGL locations and versions.
Function must return a value if errx not declared with attr noreturn.

--- src/dispatch_common.c.orig	2015-07-15 23:46:36.000000000 +0000
+++ src/dispatch_common.c
@@ -103,11 +103,13 @@
 #include "dispatch_common.h"
 
 #ifdef __APPLE__
+#ifndef GLX_LIB
 #define GLX_LIB "/opt/X11/lib/libGL.1.dylib"
+#endif
 #elif defined(ANDROID)
 #define GLX_LIB "libGLESv2.so"
 #else
-#define GLX_LIB "libGL.so.1"
+#define GLX_LIB "libGL.so"
 #endif
 
 #ifdef ANDROID
@@ -672,6 +674,7 @@ epoxy_get_proc_address(const char *name)
 #endif
     }
     errx(1, "Couldn't find current GLX or EGL context.\n");
+    return NULL;
 #endif
 }
 
