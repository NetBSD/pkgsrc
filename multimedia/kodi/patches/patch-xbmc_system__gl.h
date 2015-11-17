$NetBSD: patch-xbmc_system__gl.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/system_gl.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/system_gl.h
@@ -38,6 +38,10 @@
   #elif defined(TARGET_FREEBSD)
     #include <GL/glew.h>
     #include <GL/gl.h>
+  #elif defined(TARGET_NETBSD)
+    #include <GL/glew.h>
+    #include <GL/gl.h>
+    #include <GL/glext.h>
   #elif defined(TARGET_DARWIN)
     #include <GL/glew.h>
     #include <OpenGL/gl.h>
