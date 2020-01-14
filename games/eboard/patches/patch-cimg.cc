$NetBSD: patch-cimg.cc,v 1.3 2020/01/14 08:48:44 hauke Exp $

Fix build with png-1.5.
https://sourceforge.net/tracker/?func=detail&aid=3515237&group_id=11164&atid=111164

--- cimg.cc.orig	2020-01-13 16:13:00.560205280 +0000
+++ cimg.cc
@@ -94,11 +94,11 @@ CImg::CImg(const char *filename) {
       ct == PNG_COLOR_TYPE_GRAY_ALPHA)
     png_set_gray_to_rgb(pngp);
 
-  alloc(pngp->width,pngp->height);
+  alloc(png_get_image_width(pngp, infp),png_get_image_height(pngp, infp));
   if (!ok) { fclose(f); return; }
   ok = 0;
 
-  for(i=0;i<pngp->height;i++) {
+  for(i=0;i<png_get_image_height(pngp, infp);i++) {
     png_read_row(pngp, (png_bytep) (&data[i*rowlen]), NULL);
   }
 
