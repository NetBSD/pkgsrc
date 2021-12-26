$NetBSD: patch-src_jpegwrite.c,v 1.1 2021/12/26 05:28:23 dholland Exp $

Use const. Don't use const where libjpeg doesn't accept it.

--- src/jpegwrite.c.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/jpegwrite.c
@@ -54,10 +54,10 @@ write_JPEG_file (value file,
 		 value height, 
 		 value qual)
 {
-  JSAMPLE *image_buffer;
+  const JSAMPLE *image_buffer;
   int image_height;
   int image_width;
-  char *filename;
+  const char *filename;
   int quality;
 
   /* This struct contains the JPEG compression parameters and pointers to
@@ -152,7 +152,7 @@ write_JPEG_file (value file,
      * Here the array is only one element long, but you could pass
      * more than one scanline at a time if that's more convenient.
      */
-    row_pointer[0] = & image_buffer[cinfo.next_scanline * row_stride];
+    row_pointer[0] = (char *) & image_buffer[cinfo.next_scanline * row_stride];
     (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
   }
 
@@ -207,7 +207,7 @@ value open_jpeg_file_for_write_colorspac
      value qual;
      J_COLOR_SPACE colorspace;
 {
-  char *filename;
+  const char *filename;
   int image_height;
   int image_width;
   int quality;
@@ -294,7 +294,7 @@ value jpegh, buf;
 
   cinfop = (struct jpeg_compress_struct *) Field( jpegh, 0 );
 
-  row[0] = String_val( buf );
+  row[0] = (char *)String_val( buf );
 
   jpeg_write_scanlines( cinfop, row, 1 );
   return Val_unit;
