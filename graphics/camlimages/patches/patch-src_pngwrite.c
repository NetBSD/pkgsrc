$NetBSD: patch-src_pngwrite.c,v 1.1 2011/08/07 20:36:20 wiz Exp $

Fix build with png-1.5.

--- src/pngwrite.c.orig	2011-01-25 14:10:44.000000000 +0000
+++ src/pngwrite.c	2011-04-17 13:36:21.000000000 +0000
@@ -62,7 +62,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_write_struct(&png_ptr, &info_ptr);
     fclose(fp);
@@ -171,7 +171,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_write_struct(&png_ptr, &info_ptr);
     fclose(fp);
