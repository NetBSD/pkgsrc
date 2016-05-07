$NetBSD: patch-src_Canvas_ShivaVG_src_shDefs.h,v 1.1 2016/05/07 09:56:57 joerg Exp $

On NetBSD7, glxext.h actually requires the typedefs from glext.h.

--- src/Canvas/ShivaVG/src/shDefs.h.orig	2016-05-06 14:28:17.000000000 +0000
+++ src/Canvas/ShivaVG/src/shDefs.h
@@ -167,7 +167,6 @@ SHfloat getMaxFloat();
     #include <GL/gl.h>
     #include <GL/glu.h>
 #else
-    #define GL_GLEXT_LEGACY /* don't include glext.h */
     #include <GL/gl.h>
     #include <GL/glu.h>
     #include <GL/glx.h>
