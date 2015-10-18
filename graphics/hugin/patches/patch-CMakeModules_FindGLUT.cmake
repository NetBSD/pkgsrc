$NetBSD: patch-CMakeModules_FindGLUT.cmake,v 1.1 2015/10/18 15:56:56 adam Exp $

Fix configure phase on OS X.

--- CMakeModules/FindGLUT.cmake.orig	2014-02-12 17:14:43.000000000 +0000
+++ CMakeModules/FindGLUT.cmake
@@ -31,10 +31,7 @@ ELSE (WIN32)
   
   IF (APPLE)
     # These values for Apple could probably do with improvement.
-    FIND_PATH( GLUT_INCLUDE_DIR glut.h
-      /System/Library/Frameworks/GLUT.framework/Versions/A/Headers
-      ${OPENGL_LIBRARY_DIR}
-      )
+    SET(GLUT_INCLUDE_DIR "/usr/include")
     SET(GLUT_glut_LIBRARY "-framework GLUT" CACHE STRING "GLUT library for OSX") 
     SET(GLUT_cocoa_LIBRARY "-framework Cocoa" CACHE STRING "Cocoa framework for OSX")
   ELSE (APPLE)
