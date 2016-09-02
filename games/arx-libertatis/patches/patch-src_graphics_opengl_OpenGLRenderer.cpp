$NetBSD: patch-src_graphics_opengl_OpenGLRenderer.cpp,v 1.1 2016/09/02 16:46:04 wiz Exp $

Turn off VBO if not available. This may help with performance issues.

--- ./src/graphics/opengl/OpenGLRenderer.cpp.orig	2012-06-08 21:12:01.000000000 +0200
+++ ./src/graphics/opengl/OpenGLRenderer.cpp	2012-06-08 21:13:12.000000000 +0200
@@ -148,6 +148,8 @@
 	useVBOs = useVertexArrays;
 	if(useVBOs && !GLEW_ARB_map_buffer_range) {
 		LogWarning << "Missing OpenGL extension ARB_map_buffer_range, VBO performance will suffer.";
+		LogWarning << "Turning VBO off.";
+		useVBOs = false;
 	}
 	
 	glEnable(GL_POLYGON_OFFSET_FILL);
