$NetBSD: patch-libvideogfx_graphics_fileio_png.cc,v 1.1 2011/03/28 08:01:21 wiz Exp $

Fix build with png-1.5.

--- libvideogfx/graphics/fileio/png.cc.orig	2002-11-12 13:23:17.000000000 +0000
+++ libvideogfx/graphics/fileio/png.cc
@@ -114,7 +114,7 @@ namespace videogfx {
          * the normal method of doing things with libpng).  REQUIRED unless you
          * set up your own error handlers in the png_create_read_struct() earlier.
          */
-        if (setjmp(png_ptr->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png_ptr))) {
             /* Free all of the memory associated with the png_ptr and info_ptr */
             png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
             /* If we get here, we had a problem reading the file */
@@ -309,7 +309,7 @@ namespace videogfx {
       /* Set error handling.  REQUIRED if you aren't supplying your own
        * error hadnling functions in the png_create_write_struct() call.
        */
-      if (setjmp(png_ptr->jmpbuf)) {
+      if (setjmp(png_jmpbuf(png_ptr))) {
           /* If we get here, we had a problem reading the file */
           png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
           AssertDescr(false, "could not write png file");
