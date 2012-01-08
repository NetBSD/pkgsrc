$NetBSD: patch-src_imageloader__png.cpp,v 1.1.1.1 2012/01/08 15:52:12 wiz Exp $

Fix build with png-1.5.

--- src/imageloader_png.cpp.orig	2004-09-26 19:24:31.000000000 +0000
+++ src/imageloader_png.cpp
@@ -19,7 +19,7 @@ static void png_read_xu4(png_structp png
    png_size_t check;
    U4FILE *file;
  
-   file = (U4FILE *) png_ptr->io_ptr;
+   file = (U4FILE *) png_get_io_ptr(png_ptr);
    check = file->read(data, (png_size_t)1, length);
 
    if (check != length)
