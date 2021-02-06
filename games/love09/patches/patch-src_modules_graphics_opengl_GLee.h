$NetBSD: patch-src_modules_graphics_opengl_GLee.h,v 1.1 2021/02/06 14:27:41 maya Exp $

Newer mesa seems to use different include guards, add those as well.

--- src/modules/graphics/opengl/GLee.h.orig	2015-01-15 09:39:26.000000000 +0000
+++ src/modules/graphics/opengl/GLee.h
@@ -61,7 +61,9 @@
 	#include <OpenGL/gl.h>
 #else // GLX
 	#define __glext_h_  /* prevent glext.h from being included  */
+	#define __gl_glext_h_  /* prevent glext.h from being included - newer version */
 	#define __glxext_h_ /* prevent glxext.h from being included */
+	#define __glx_glxext_h_ /* prevent glxext.h from being included - newer version */
 	#define GLX_GLXEXT_PROTOTYPES
 	#include <GL/gl.h>
 	#include <GL/glx.h>
