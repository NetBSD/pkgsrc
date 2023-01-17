$NetBSD: patch-src_podofo_doc_PdfImage.cpp,v 1.1 2023/01/17 14:01:57 spz Exp $

Recognize TIFF images with alpha channel when using the photometric
colour tag.

--- src/podofo/doc/PdfImage.cpp.orig	2016-05-15 19:06:35.000000000 +0000
+++ src/podofo/doc/PdfImage.cpp
@@ -589,7 +589,7 @@ void PdfImage::LoadFromTiffHandle(void* 
             break;
             
         case PHOTOMETRIC_RGB:
-            if ( bitsPixel != 24 )
+            if ( bitsPixel != 24 && bitsPixel != 32 )
             {
                 TIFFClose(hInTiffHandle);
                 PODOFO_RAISE_ERROR( ePdfError_UnsupportedImageFormat );
