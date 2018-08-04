$NetBSD: patch-simgear_canvas_ShivaVG_src_shDefs.h,v 1.1 2018/08/04 04:04:28 nia Exp $

Support NetBSD.

--- simgear/canvas/ShivaVG/src/shDefs.h.orig	2018-06-03 18:56:36.000000000 +0000
+++ simgear/canvas/ShivaVG/src/shDefs.h
@@ -161,7 +161,7 @@ SHfloat getMaxFloat();
 
 /* OpenGL headers */
 
-#if defined(VG_API_LINUX) || defined(VG_API_FREEBSD)
+#if defined(VG_API_LINUX) || defined(VG_API_FREEBSD) || defined(VG_API_NETBSD)
     #include <GL/gl.h>
     #include <GL/glx.h>
 #elif defined(VG_API_MACOSX)
