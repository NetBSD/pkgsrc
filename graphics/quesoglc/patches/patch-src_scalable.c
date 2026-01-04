$NetBSD: patch-src_scalable.c,v 1.1 2026/01/04 13:39:09 adam Exp $

Fixes for newer glu.

--- src/scalable.c.orig	2026-01-04 11:50:44.510274999 +0000
+++ src/scalable.c
@@ -597,15 +597,13 @@ void __glcRenderCharScalable(__GLCfont* 
     gluTessProperty(tess, GLU_TESS_BOUNDARY_ONLY, GL_FALSE);
 
     gluTessCallback(tess, GLU_TESS_ERROR,
-			(void (CALLBACK *) (GLenum))__glcCallbackError);
+			(void (CALLBACK *) (void))__glcCallbackError);
     gluTessCallback(tess, GLU_TESS_VERTEX_DATA,
-		    (void (CALLBACK *) (void*, void*))__glcVertexCallback);
+		    (void (CALLBACK *) (void))__glcVertexCallback);
     gluTessCallback(tess, GLU_TESS_COMBINE_DATA,
-		    (void (CALLBACK *) (GLdouble[3], void*[4],
-					GLfloat[4], void**, void*))
-		    __glcCombineCallback);
+		    (void (CALLBACK *) (void))__glcCombineCallback);
     gluTessCallback(tess, GLU_TESS_BEGIN_DATA,
-		    (void (CALLBACK *) (GLenum, void*))__glcBeginCallback);
+		    (void (CALLBACK *) (void))__glcBeginCallback);
 
     gluTessNormal(tess, 0., 0., 1.);
 
