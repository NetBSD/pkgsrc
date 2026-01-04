$NetBSD: patch-src_ofont.h,v 1.3 2026/01/04 13:39:09 adam Exp $

Remove inlining.

--- src/ofont.h.orig	2008-10-18 21:35:13.000000000 +0000
+++ src/ofont.h
@@ -27,11 +27,6 @@
 
 #include "ofacedesc.h"
 
-/* It seems that Visual C++ does not recognize the inline keyword !?! */
-#ifdef _MSC_VER
-#define inline
-#endif
-
 struct __GLCfontRec {
   GLint id;
   __GLCfaceDescriptor* faceDesc;
@@ -54,46 +49,46 @@ GLfloat* __glcFontGetKerning(__GLCfont*
 			     GLfloat* outVec, __GLCcontext* inContext,
 			     GLfloat inScaleX, GLfloat inScaleY);
 #ifndef GLC_FT_CACHE
-static inline void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext);
-static inline void __glcFontClose(__GLCfont* This);
+static void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext);
+static void __glcFontClose(__GLCfont* This);
 #endif
 GLboolean __glcFontPrepareGlyph(__GLCfont* This, __GLCcontext* inContext,
 				GLfloat inScaleX, GLfloat inScaleY,
 				GLCulong inGlyphIndex);
-static inline GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
+static GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
 					       GLint *outHeight,
 					       GLfloat inScaleX,
 					       GLfloat inScaleY, int inFactor,
 					       GLint* outPixBoundingBox,
 					       __GLCcontext* inContext);
-static inline GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
+static GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
 					     __GLCcontext* inContext);
-static inline GLboolean __glcFontOutlineDecompose(__GLCfont* This,
+static GLboolean __glcFontOutlineDecompose(__GLCfont* This,
 						  __GLCrendererData* inData,
 						  __GLCcontext* inContext);
-static inline GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
+static GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
 					   GLint inHeight, void* inBuffer,
 					   __GLCcontext* inContext);
-static inline GLboolean __glcFontOutlineEmpty(__GLCfont* This);
+static GLboolean __glcFontOutlineEmpty(__GLCfont* This);
 
 /* Inline functions definitions */
 
 #ifndef GLC_FT_CACHE
 /* Open the font file */
-static inline void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext)
+static void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext)
 {
   return __glcFaceDescOpen(This->faceDesc, inContext);
 }
 
 /* Close the font file */
-static inline void __glcFontClose(__GLCfont* This)
+static void __glcFontClose(__GLCfont* This)
 {
    __glcFaceDescClose(This->faceDesc);
 }
 #endif
 
 /* Get the size of the bitmap in which the glyph will be rendered */
-static inline GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
+static GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
 					       GLint *outHeight,
 					       GLfloat inScaleX,
 					       GLfloat inScaleY, int inFactor,
@@ -108,14 +103,14 @@ static inline GLboolean __glcFontGetBitm
 /* Get the maximum metrics of a face that is the bounding box that encloses
  * every glyph of the face, and the maximum advance of the face.
  */
-static inline GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
+static GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
 					     __GLCcontext* inContext)
 {
   return __glcFaceDescGetMaxMetric(This->faceDesc, outVec, inContext);
 }
 
 /* Decompose the outline of a glyph */
-static inline GLboolean __glcFontOutlineDecompose(__GLCfont* This,
+static GLboolean __glcFontOutlineDecompose(__GLCfont* This,
 						  __GLCrendererData* inData,
 						  __GLCcontext* inContext)
 {
@@ -123,7 +118,7 @@ static inline GLboolean __glcFontOutline
 }
 
 /* Render the glyph in a bitmap */
-static inline GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
+static GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
 					   GLint inHeight, void* inBuffer,
 					   __GLCcontext* inContext)
 {
@@ -134,7 +129,7 @@ static inline GLboolean __glcFontGetBitm
 /* Chek if the outline of the glyph is empty (which means it is a spacing
  * character).
  */
-static inline GLboolean __glcFontOutlineEmpty(__GLCfont* This)
+static GLboolean __glcFontOutlineEmpty(__GLCfont* This)
 {
   return __glcFaceDescOutlineEmpty(This->faceDesc);
 }
