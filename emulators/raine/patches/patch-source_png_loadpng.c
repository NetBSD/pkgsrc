$NetBSD: patch-source_png_loadpng.c,v 1.1 2011/03/14 12:04:31 obache Exp $

--- source/png/loadpng.c.orig	2005-08-18 08:52:15.000000000 +0000
+++ source/png/loadpng.c
@@ -275,7 +275,7 @@ BITMAP *load_png(AL_CONST char *filename
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	pack_fclose(fp);
@@ -337,7 +337,7 @@ BITMAP *load_png_from_zip(unzFile uf, RG
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	/* If we get here, we had a problem reading the file */
@@ -435,7 +435,7 @@ BITMAP *load_memory_png(AL_CONST void *b
      * the normal method of doing things with libpng).  REQUIRED unless you
      * set up your own error handlers in the png_create_read_struct() earlier.
      */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* Free all of the memory associated with the png_ptr and info_ptr */
 	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
 	/* If we get here, we had a problem reading the file */
