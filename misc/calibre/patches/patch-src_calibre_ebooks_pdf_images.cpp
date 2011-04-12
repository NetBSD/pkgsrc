$NetBSD: patch-src_calibre_ebooks_pdf_images.cpp,v 1.1 2011/04/12 21:48:01 wiz Exp $

Fix build with png-1.5.

--- src/calibre/ebooks/pdf/images.cpp.orig	2009-11-16 19:41:31.000000000 +0000
+++ src/calibre/ebooks/pdf/images.cpp
@@ -6,6 +6,7 @@
 #include <math.h>
 #include <iostream>
 #include <wand/MagickWand.h>
+#include <zlib.h>
 
 #include "images.h"
 #include "utils.h"
@@ -294,7 +295,7 @@ void PNGWriter::write_splash_bitmap(Spla
 
 void calibre_png_mem_write(png_structp png_ptr, png_bytep data, png_size_t length) {
     if (!png_ptr || length < 1) return;
-    vector<char> *buf = static_cast< vector<char>* >(png_ptr->io_ptr);
+    vector<char> *buf = static_cast< vector<char>* >(png_get_io_ptr(png_ptr));
     buf->reserve(buf->capacity() + length); 
     do {
         buf->push_back(static_cast<char>(*data));
