$NetBSD: patch-src_dispatch__common.h,v 1.1 2015/06/13 19:13:10 tnn Exp $

Override EGL detection.

--- src/dispatch_common.h.orig	2014-05-14 00:22:08.000000000 +0000
+++ src/dispatch_common.h
@@ -34,7 +34,12 @@
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
 #else
+#include "config.h"
+#ifdef BUILD_EGL
 #define PLATFORM_HAS_EGL 1
+#else
+#define PLATFORM_HAS_EGL 0
+#endif
 #define PLATFORM_HAS_GLX 1
 #define PLATFORM_HAS_WGL 0
 #define EPOXY_IMPORTEXPORT
