$NetBSD: patch-src_ofont.c,v 1.1 2013/02/26 11:10:28 joerg Exp $

--- src/ofont.c.orig	2013-02-25 16:31:40.000000000 +0000
+++ src/ofont.c
@@ -284,7 +284,7 @@ GLboolean __glcFontFace(__GLCfont* This,
 
 #ifndef GLC_FT_CACHE
 /* Open the font file */
-inline void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext)
+void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext)
 {
   return __glcFaceDescOpen(This->faceDesc, inContext);
 }
@@ -292,7 +292,7 @@ inline void* __glcFontOpen(__GLCfont* Th
 
 
 /* Close the font file */
-inline void __glcFontClose(__GLCfont* This)
+void __glcFontClose(__GLCfont* This)
 {
    __glcFaceDescClose(This->faceDesc);
 }
@@ -321,7 +321,7 @@ GLboolean __glcFontPrepareGlyph(__GLCfon
 
 
 /* Get the size of the bitmap in which the glyph will be rendered */
-inline GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
+GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
 					GLint *outHeight, GLint* outBoundingBox,
 					GLfloat inScaleX, GLfloat inScaleY,
 					int inFactor, __GLCcontext* inContext)
@@ -336,7 +336,7 @@ inline GLboolean __glcFontGetBitmapSize(
 /* Get the maximum metrics of a face that is the bounding box that encloses
  * every glyph of the face, and the maximum advance of the face.
  */
-inline GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
+GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
 				      __GLCcontext* inContext)
 {
   return __glcFaceDescGetMaxMetric(This->faceDesc, outVec, inContext);
@@ -345,7 +345,7 @@ inline GLfloat* __glcFontGetMaxMetric(__
 
 
 /* Decompose the outline of a glyph */
-inline GLboolean __glcFontOutlineDecompose(__GLCfont* This,
+GLboolean __glcFontOutlineDecompose(__GLCfont* This,
 					   __GLCrendererData* inData,
 					   __GLCcontext* inContext)
 {
@@ -355,7 +355,7 @@ inline GLboolean __glcFontOutlineDecompo
 
 
 /* Render the glyph in a bitmap */
-inline GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
+GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
 				    GLint inHeight, void* inBuffer,
 				    __GLCcontext* inContext)
 {
@@ -368,7 +368,7 @@ inline GLboolean __glcFontGetBitmap(__GL
 /* Chek if the outline of the glyph is empty (which means it is a spacing
  * character).
  */
-inline GLboolean __glcFontOutlineEmpty(__GLCfont* This, __GLCcontext* inContext)
+GLboolean __glcFontOutlineEmpty(__GLCfont* This, __GLCcontext* inContext)
 {
   return __glcFaceDescOutlineEmpty(This->faceDesc, inContext);
 }
