$NetBSD: patch-src_modules_graphics_opengl_GLee.h,v 1.1 2019/12/22 22:26:04 joerg Exp $

--- src/modules/graphics/opengl/GLee.h.orig	2019-12-22 20:20:40.498620352 +0000
+++ src/modules/graphics/opengl/GLee.h
@@ -65,6 +65,7 @@
 	#define __glext_h_  /* prevent glext.h from being included  */
 	#define __glxext_h_ /* prevent glxext.h from being included */
 	#define GLX_GLXEXT_PROTOTYPES
+	#define GL_GLEXT_PROTOTYPES
 	#include <GL/gl.h>
 	#include <GL/glx.h>
 #endif
