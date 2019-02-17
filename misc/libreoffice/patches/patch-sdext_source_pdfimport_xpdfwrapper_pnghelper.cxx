$NetBSD: patch-sdext_source_pdfimport_xpdfwrapper_pnghelper.cxx,v 1.1 2019/02/17 15:27:41 tnn Exp $

poppler compatibility

--- sdext/source/pdfimport/xpdfwrapper/pnghelper.cxx.orig	2018-12-12 21:59:14.000000000 +0000
+++ sdext/source/pdfimport/xpdfwrapper/pnghelper.cxx
@@ -242,7 +242,7 @@ void PngHelper::createPng( OutputBuffer&
     appendIHDR( o_rOutputBuf, width, height, 8, 6 ); // RGBA image
 
     // initialize stream
-    Guchar *p, *pm;
+    unsigned char *p, *pm;
     GfxRGB rgb;
     GfxGray alpha;
     ImageStream* imgStr =
@@ -328,7 +328,7 @@ void PngHelper::createPng( OutputBuffer&
     appendIHDR( o_rOutputBuf, width, height, 8, 6 ); // RGBA image
 
     // initialize stream
-    Guchar *p;
+    unsigned char *p;
     GfxRGB rgb;
     ImageStream* imgStr =
         new ImageStream(str,
@@ -374,7 +374,7 @@ void PngHelper::createPng( OutputBuffer&
     {
         for( int x = 0; x < maskWidth; ++x )
         {
-            Guchar aPixel = 0;
+            unsigned char aPixel = 0;
             imgStrMask->getPixel( &aPixel );
             int nIndex = (y*height/maskHeight) * (width*4+1) + // mapped line
                          (x*width/maskWidth)*4 + 1  + 3        // mapped column
