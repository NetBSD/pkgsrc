$NetBSD: patch-Source__Files_RenderMain_OGL__Render.cpp,v 1.1 2023/04/27 13:33:47 yhardy Exp $

Use GLEW for GL extensions, works around a linking problem on NetBSD.

--- Source_Files/RenderMain/OGL_Render.cpp.orig	2021-01-17 20:42:00.000000000 +0000
+++ Source_Files/RenderMain/OGL_Render.cpp
@@ -513,7 +513,7 @@ bool OGL_StartRun()
 	// Will stop previous run if it had been active
 	if (OGL_IsActive()) OGL_StopRun();
 
-#ifdef __WIN32__
+#if 1
 	glewInit();
 #endif
 
