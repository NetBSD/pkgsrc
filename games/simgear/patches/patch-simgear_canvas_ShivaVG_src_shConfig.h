$NetBSD: patch-simgear_canvas_ShivaVG_src_shConfig.h,v 1.3 2021/02/25 10:22:14 nia Exp $

Support NetBSD and SunOS.

--- simgear/canvas/ShivaVG/src/shConfig.h.orig	2021-01-23 18:01:02.000000000 +0000
+++ simgear/canvas/ShivaVG/src/shConfig.h
@@ -16,7 +16,7 @@
         #define NOMINMAX
     #endif
 
-#elif defined(linux) || defined(__linux)
+#elif defined(linux) || defined(__linux) || defined(__sun)
 
     // Linux
     #define VG_API_LINUX
@@ -31,6 +31,11 @@
     // FreeBSD
     #define VG_API_FREEBSD
 
+#elif defined(__NetBSD__)
+
+    // NetBSD
+    #define VG_API_NETBSD
+
 #elif defined(__OpenBSD__)
 
     // FreeBSD
