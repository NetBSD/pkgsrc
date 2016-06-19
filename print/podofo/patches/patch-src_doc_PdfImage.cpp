$NetBSD: patch-src_doc_PdfImage.cpp,v 1.1 2016/06/19 22:55:18 joerg Exp $

--- src/doc/PdfImage.cpp.orig	2016-06-07 16:48:51.790860153 +0000
+++ src/doc/PdfImage.cpp
@@ -550,7 +550,7 @@ void PdfImage::LoadFromTiff( const char*
 		break;
 
 		case PHOTOMETRIC_RGB:
-            if ( bitsPixel != 24 )
+            if ( bitsPixel != 24 && bitsPixel != 32 )
 			{
 				TIFFClose(hInfile);
 				PODOFO_RAISE_ERROR( ePdfError_UnsupportedImageFormat );
