$NetBSD: patch-simgear_canvas_ShivaVG_src_shDefs.h,v 1.2 2021/02/25 10:22:14 nia Exp $

Support NetBSD.

--- simgear/canvas/ShivaVG/src/shDefs.h.orig	2021-01-23 18:01:02.000000000 +0000
+++ simgear/canvas/ShivaVG/src/shDefs.h
@@ -161,7 +161,7 @@ SHfloat getMaxFloat();
 
 /* OpenGL headers */
 
-#if defined(VG_API_LINUX) || defined(VG_API_FREEBSD) || defined(VG_API_OPENBSD)
+#if defined(VG_API_LINUX) || defined(VG_API_FREEBSD) || defined(VG_API_NETBSD) || defined(VG_API_OPENBSD)
     #include <GL/gl.h>
     #include <GL/glx.h>
 #elif defined(VG_API_MACOSX)
