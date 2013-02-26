$NetBSD: patch-src_ofont.h,v 1.1 2013/02/26 11:10:28 joerg Exp $

--- src/ofont.h.orig	2013-02-25 16:31:17.000000000 +0000
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
@@ -54,24 +49,24 @@ GLfloat* __glcFontGetKerning(__GLCfont* 
 			     GLfloat* outVec, __GLCcontext* inContext,
 			     GLfloat inScaleX, GLfloat inScaleY);
 #ifndef GLC_FT_CACHE
-inline void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext);
-inline void __glcFontClose(__GLCfont* This);
+void* __glcFontOpen(__GLCfont* This, __GLCcontext* inContext);
+void __glcFontClose(__GLCfont* This);
 #endif
 GLboolean __glcFontPrepareGlyph(__GLCfont* This, __GLCcontext* inContext,
 				GLfloat inScaleX, GLfloat inScaleY,
 				GLCulong inGlyphIndex);
-inline GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
+GLboolean __glcFontGetBitmapSize(__GLCfont* This, GLint* outWidth,
 					GLint *outHeight, GLint* outBoundingBox,
 					GLfloat inScaleX, GLfloat inScaleY,
 					int inFactor, __GLCcontext* inContext);
-inline GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
+GLfloat* __glcFontGetMaxMetric(__GLCfont* This, GLfloat* outVec,
 				      __GLCcontext* inContext);
-inline GLboolean __glcFontOutlineDecompose(__GLCfont* This,
+GLboolean __glcFontOutlineDecompose(__GLCfont* This,
 					   __GLCrendererData* inData,
 					   __GLCcontext* inContext);
-inline GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
+GLboolean __glcFontGetBitmap(__GLCfont* This, GLint inWidth,
 				    GLint inHeight, void* inBuffer,
 				    __GLCcontext* inContext);
-inline GLboolean __glcFontOutlineEmpty(__GLCfont* This,
+GLboolean __glcFontOutlineEmpty(__GLCfont* This,
 				       __GLCcontext* inContext);
 #endif /* __glc_ofont_h */
