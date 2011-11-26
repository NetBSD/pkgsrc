$NetBSD: patch-examples_cally_src_model.cpp,v 1.1 2011/11/26 17:12:24 joerg Exp $

--- examples/cally/src/model.cpp.orig	2003-11-29 16:53:38.000000000 +0000
+++ examples/cally/src/model.cpp
@@ -17,6 +17,8 @@
 #include "menu.h"
 #include "tga.h"
 
+#include <inttypes.h>
+
 //----------------------------------------------------------------------------//
 // Static member variables initialization                                     //
 //----------------------------------------------------------------------------//
@@ -633,7 +635,7 @@ void Model::renderMesh(bool bWireframe, 
           glEnable(GL_COLOR_MATERIAL);
 
           // set the texture id we stored in the map user data
-          glBindTexture(GL_TEXTURE_2D, (GLuint)pCalRenderer->getMapUserData(0));
+          glBindTexture(GL_TEXTURE_2D, (GLuint)(uintptr_t)pCalRenderer->getMapUserData(0));
 
           // set the texture coordinate buffer
           glTexCoordPointer(2, GL_FLOAT, 0, &meshTextureCoordinates[0][0]);
