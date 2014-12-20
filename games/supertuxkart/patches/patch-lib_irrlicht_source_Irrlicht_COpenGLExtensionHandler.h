$NetBSD: patch-lib_irrlicht_source_Irrlicht_COpenGLExtensionHandler.h,v 1.1 2014/12/20 20:21:12 ryoon Exp $

Fix MesaLib 10 build.
https://github.com/supertuxkart/stk-code/commit/244d00280c1b082ca164f92337773e9e4e1a3898

--- lib/irrlicht/source/Irrlicht/COpenGLExtensionHandler.h.orig	2013-11-13 23:55:29.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/COpenGLExtensionHandler.h
@@ -21,6 +21,7 @@
 	#endif
 	#include <GL/gl.h>
 	#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
+		 typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
 		#include "glext.h"
 	#endif
 	#include "wglext.h"
@@ -36,6 +37,7 @@
 	#endif
 	#include <OpenGL/gl.h>
 	#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
+		 typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
 		#include "glext.h"
 	#endif
 #elif defined(_IRR_COMPILE_WITH_SDL_DEVICE_) && !defined(_IRR_COMPILE_WITH_X11_DEVICE_)
@@ -49,6 +51,7 @@
 	#define NO_SDL_GLEXT
 	#include <SDL/SDL_video.h>
 	#include <SDL/SDL_opengl.h>
+	 typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
 	#include "glext.h"
 #else
 	#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
@@ -61,6 +64,7 @@
 	#include <GL/gl.h>
 	#include <GL/glx.h>
 	#if defined(_IRR_OPENGL_USE_EXTPOINTER_)
+	 typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
 	#include "glext.h"
 	#undef GLX_ARB_get_proc_address // avoid problems with local glxext.h
 	#include "glxext.h"
