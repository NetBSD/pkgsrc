$NetBSD: patch-Source__Files_RenderOther_screen.cpp,v 1.1 2023/04/27 13:33:47 yhardy Exp $

Use GLEW for GL extensions, works around a linking problem on NetBSD.

--- Source_Files/RenderOther/screen.cpp.orig	2021-10-31 00:46:41.000000000 +0000
+++ Source_Files/RenderOther/screen.cpp
@@ -963,7 +963,7 @@ static void change_screen_mode(int width
 			SDL_GL_CreateContext(main_screen);
 			context_created = true;
 		}
-#ifdef __WIN32__
+#if 1
 		glewInit();
 #endif
 		if (!OGL_CheckExtension("GL_ARB_vertex_shader") || !OGL_CheckExtension("GL_ARB_fragment_shader") || !OGL_CheckExtension("GL_ARB_shader_objects") || !OGL_CheckExtension("GL_ARB_shading_language_100"))
