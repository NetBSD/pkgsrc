$NetBSD: patch-include_GL_gl.h,v 1.1 2013/06/13 14:16:21 wiz Exp $

Check for symbol existence with #ifdef, not #if.
Needed since some other files only #define the symbol without a value.

--- include/GL/gl.h.orig	2011-11-23 01:09:52.000000000 +0000
+++ include/GL/gl.h
@@ -2094,7 +2094,7 @@ typedef void (APIENTRYP PFNGLMULTITEXCOO
 
 
 
-#if GL_ARB_shader_objects
+#ifdef GL_ARB_shader_objects
 
 #ifndef GL_MESA_shader_debug
 #define GL_MESA_shader_debug 1
