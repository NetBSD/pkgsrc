$NetBSD: patch-png_pngwrite.c,v 1.1 2011/02/19 10:54:37 wiz Exp $

Fix build with png-1.5.

--- png/pngwrite.c.orig	2004-03-04 17:10:00.000000000 +0000
+++ png/pngwrite.c
@@ -57,7 +57,7 @@ value write_png_file_rgb24( name, buffer
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_write_struct(&png_ptr, &info_ptr);
     fclose(fp);
@@ -166,7 +166,7 @@ value write_png_file_index( name, buffer
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_write_struct(&png_ptr, &info_ptr);
     fclose(fp);
