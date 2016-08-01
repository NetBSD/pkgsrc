$NetBSD: patch-src_doc_PdfImage.cpp,v 1.3 2016/08/01 13:39:34 adam Exp $

Recognize TIFF images with alpha channel when using the photometric
colour tag.

--- src/doc/PdfImage.cpp.orig	2016-05-15 19:06:35.000000000 +0000
+++ src/doc/PdfImage.cpp
@@ -589,7 +589,7 @@ void PdfImage::LoadFromTiffHandle(void* 
             break;
             
         case PHOTOMETRIC_RGB:
-            if ( bitsPixel != 24 )
+            if ( bitsPixel != 24 && bitsPixel != 32 )
             {
                 TIFFClose(hInTiffHandle);
                 PODOFO_RAISE_ERROR( ePdfError_UnsupportedImageFormat );
