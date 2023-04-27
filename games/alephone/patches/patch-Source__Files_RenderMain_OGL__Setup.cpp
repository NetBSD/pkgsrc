$NetBSD: patch-Source__Files_RenderMain_OGL__Setup.cpp,v 1.1 2023/04/27 13:33:47 yhardy Exp $

Use GLEW for GL extensions, works around a linking problem on NetBSD.

--- Source_Files/RenderMain/OGL_Setup.cpp.orig	2021-07-26 23:29:33.000000000 +0000
+++ Source_Files/RenderMain/OGL_Setup.cpp
@@ -115,7 +115,7 @@ bool OGL_IsPresent() {return _OGL_IsPres
 
 bool OGL_CheckExtension(const std::string extension) {
 #ifdef HAVE_OPENGL
-#ifdef __WIN32__
+#if	1
 	return glewIsSupported(extension.c_str());
 #else
 	char *extensions = (char *) glGetString(GL_EXTENSIONS);
