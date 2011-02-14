$NetBSD: patch-plugins_image__saver_png__saver.c,v 1.2 2011/02/14 18:12:24 wiz Exp $

Fix build with png-1.5.
https://sourceforge.net/tracker/?func=detail&aid=3181113&group_id=39083&atid=424297

--- plugins/image_saver/png_saver.c.orig	2004-05-23 14:08:11.000000000 +0000
+++ plugins/image_saver/png_saver.c
@@ -130,7 +130,7 @@ save_png (GimvImageSaver *saver,
       return FALSE;
    }
 
-   if (setjmp (png_ptr->jmpbuf)) {
+   if (setjmp (png_jmpbuf(png_ptr))) {
       png_destroy_write_struct (&png_ptr, &info_ptr);
       fclose (handle);
       return FALSE;
