$NetBSD: patch-examples_miniviewer__gl_src_viewer.cpp,v 1.1 2011/11/26 17:12:24 joerg Exp $

--- examples/miniviewer_gl/src/viewer.cpp.orig	2003-10-13 20:06:46.000000000 +0000
+++ examples/miniviewer_gl/src/viewer.cpp
@@ -20,6 +20,8 @@
 #include "tick.h"
 #include "tga.h"
 
+#include <inttypes.h>
+
 //----------------------------------------------------------------------------//
 // The one and only Viewer instance                                           //
 //----------------------------------------------------------------------------//
@@ -870,7 +872,7 @@ void Viewer::renderModel()
             glEnable(GL_COLOR_MATERIAL);
 
             // set the texture id we stored in the map user data
-            glBindTexture(GL_TEXTURE_2D, (GLuint)pCalRenderer->getMapUserData(0));
+            glBindTexture(GL_TEXTURE_2D, (GLuint)(uintptr_t)pCalRenderer->getMapUserData(0));
 
             // set the texture coordinate buffer
             glTexCoordPointer(2, GL_FLOAT, 0, &meshTextureCoordinates[0][0]);
