$NetBSD: patch-include_GL_glpng.h,v 1.1 2011/04/03 16:38:41 wiz Exp $

Fix build with png-1.5.

--- include/GL/glpng.h.orig	2009-05-04 18:51:48.000000000 +0000
+++ include/GL/glpng.h
@@ -57,7 +57,7 @@ extern "C" {
 #define PNG_SIMPLEMIPMAP PNG_SIMPLEMIPMAPS
 
 /* Transparency parameters */
-#define PNG_CALLBACK  -3 /* Call the callback function to generate alpha   */
+#define PNG_CALLBACKT -3 /* Call the callback function to generate alpha   */
 #define PNG_ALPHA     -2 /* Use alpha channel in PNG file, if there is one */
 #define PNG_SOLID     -1 /* No transparency                                */
 #define PNG_STENCIL    0 /* Sets alpha to 0 for r=g=b=0, 1 otherwise       */
