$NetBSD: patch-src_pngread.c,v 1.1 2011/08/07 20:36:20 wiz Exp $

Fix build with png-1.5.

--- src/pngread.c.orig	2011-01-25 14:10:44.000000000 +0000
+++ src/pngread.c	2011-04-17 13:35:40.000000000 +0000
@@ -69,7 +69,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -134,7 +134,7 @@
     png_set_rows(png_ptr, info_ptr, row_pointers);
 
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);
@@ -243,7 +243,7 @@
   }
 
   /* error handling */
-  if (setjmp(png_ptr->jmpbuf)) {
+  if (setjmp(png_jmpbuf(png_ptr))) {
     /* Free all of the memory associated with the png_ptr and info_ptr */
     png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
     fclose(fp);
@@ -302,7 +302,7 @@
     png_set_rows(png_ptr, info_ptr, row_pointers);
 
     /* Later, we can return something */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
       /* Free all of the memory associated with the png_ptr and info_ptr */
       png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
       fclose(fp);
