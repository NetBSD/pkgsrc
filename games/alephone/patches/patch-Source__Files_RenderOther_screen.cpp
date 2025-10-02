$NetBSD: patch-Source__Files_RenderOther_screen.cpp,v 1.2 2025/10/02 11:19:51 adam Exp $

Use GLEW for GL extensions, works around a linking problem on NetBSD.

--- Source_Files/RenderOther/screen.cpp.orig	2025-08-29 15:31:33.000000000 +0000
+++ Source_Files/RenderOther/screen.cpp
@@ -967,7 +967,7 @@ static void change_screen_mode(int width
 			SDL_GL_CreateContext(main_screen);
 			context_created = true;
 		}
-#if defined (__WIN32__) && (HAVE_OPENGL)
+#if HAVE_OPENGL
 		glewInit();
 #endif
 		if (!OGL_CheckExtension("GL_ARB_vertex_shader") || !OGL_CheckExtension("GL_ARB_fragment_shader") || !OGL_CheckExtension("GL_ARB_shader_objects") || !OGL_CheckExtension("GL_ARB_shading_language_100"))
