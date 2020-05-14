$NetBSD: patch-Source_FreeImage.h,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage.h.orig	2018-03-25 17:42:20.000000000 +0000
+++ Source/FreeImage.h
@@ -155,8 +155,11 @@ typedef uint8_t BYTE;
 typedef uint16_t WORD;
 typedef uint32_t DWORD;
 typedef int32_t LONG;
+// Disable these, they conflict with the (wrong) ones of libraw
+#if 0
 typedef int64_t INT64;
 typedef uint64_t UINT64;
+#endif
 #else
 // MS is not C99 ISO compliant
 typedef long BOOL;
@@ -410,7 +413,12 @@ FI_ENUM(FREE_IMAGE_FORMAT) {
 	FIF_DDS		= 24,
 	FIF_GIF     = 25,
 	FIF_HDR		= 26,
-	FIF_FAXG3	= 27,
+/* The G3 fax format plugin is deliberately disabled in the Fedora build of
+   FreeImage as it requires that FreeImage uses a private copy of libtiff
+   which is a no no because of security reasons. */
+#if 0
+ 	FIF_FAXG3	= 27,
+#endif
 	FIF_SGI		= 28,
 	FIF_EXR		= 29,
 	FIF_J2K		= 30,
@@ -473,6 +481,10 @@ FI_ENUM(FREE_IMAGE_DITHER) {
 	FID_BAYER16x16	= 6		//! Bayer ordered dispersed dot dithering (order 4 dithering matrix)
 };
 
+/* The FreeImage_JPEGTransform functions are deliberately disabled in the
+   Fedora build of FreeImage as they require that FreeImage uses a private copy
+   of libjpeg which is a no no because of security reasons. */
+#if 0
 /** Lossless JPEG transformations
 Constants used in FreeImage_JPEGTransform
 */
@@ -486,6 +498,7 @@ FI_ENUM(FREE_IMAGE_JPEG_OPERATION) {
 	FIJPEG_OP_ROTATE_180	= 6,	//! 180-degree rotation
 	FIJPEG_OP_ROTATE_270	= 7		//! 270-degree clockwise (or 90 ccw)
 };
+#endif
 
 /** Tone mapping operators.
 Constants used in FreeImage_ToneMapping.
@@ -1088,7 +1101,10 @@ DLL_API const char* DLL_CALLCONV FreeIma
 // --------------------------------------------------------------------------
 // JPEG lossless transformation routines
 // --------------------------------------------------------------------------
-
+/* The FreeImage_JPEGTransform functions are deliberately disabled in the
++   Fedora build of FreeImage as they require that FreeImage uses a private copy
++   of libjpeg which is a no no because of security reasons. */
+#if 0
 DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransform(const char *src_file, const char *dst_file, FREE_IMAGE_JPEG_OPERATION operation, BOOL perfect FI_DEFAULT(TRUE));
 DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformU(const wchar_t *src_file, const wchar_t *dst_file, FREE_IMAGE_JPEG_OPERATION operation, BOOL perfect FI_DEFAULT(TRUE));
 DLL_API BOOL DLL_CALLCONV FreeImage_JPEGCrop(const char *src_file, const char *dst_file, int left, int top, int right, int bottom);
@@ -1097,6 +1113,7 @@ DLL_API BOOL DLL_CALLCONV FreeImage_JPEG
 DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformCombined(const char *src_file, const char *dst_file, FREE_IMAGE_JPEG_OPERATION operation, int* left, int* top, int* right, int* bottom, BOOL perfect FI_DEFAULT(TRUE));
 DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformCombinedU(const wchar_t *src_file, const wchar_t *dst_file, FREE_IMAGE_JPEG_OPERATION operation, int* left, int* top, int* right, int* bottom, BOOL perfect FI_DEFAULT(TRUE));
 DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformCombinedFromMemory(FIMEMORY* src_stream, FIMEMORY* dst_stream, FREE_IMAGE_JPEG_OPERATION operation, int* left, int* top, int* right, int* bottom, BOOL perfect FI_DEFAULT(TRUE));
+#endif
 
 
 // --------------------------------------------------------------------------
