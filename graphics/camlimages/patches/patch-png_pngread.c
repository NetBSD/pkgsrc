$NetBSD: patch-png_pngread.c,v 1.1 2011/02/19 10:54:37 wiz Exp $

Fix build with png-1.5.

--- png/pngread.c.orig	2002-03-26 13:15:10.000000000 +0000
+++ png/pngread.c
@@ -70,7 +70,7 @@ value read_png_file_as_rgb24( name )
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -126,7 +126,7 @@ value read_png_file_as_rgb24( name )
     }
   
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);
@@ -224,7 +224,7 @@ value read_png_file( name )
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -328,7 +328,7 @@ fprintf(stderr, "pngread.c: rgb image\n"
     }
   
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);
