$NetBSD: patch-simgear_canvas_ShivaVG_src_shConfig.h,v 1.1 2018/08/04 04:04:28 nia Exp $

Support NetBSD.

--- simgear/canvas/ShivaVG/src/shConfig.h.orig	2018-06-03 18:56:36.000000000 +0000
+++ simgear/canvas/ShivaVG/src/shConfig.h
@@ -31,6 +31,11 @@
     // FreeBSD
     #define VG_API_FREEBSD
 
+#elif defined(__NetBSD__)
+
+    // NetBSD
+    #define VG_API_NETBSD
+
 #else
 
     // Unsupported system
