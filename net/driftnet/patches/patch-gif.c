$NetBSD: patch-gif.c,v 1.2 2014/05/20 19:11:07 adam Exp $

Fix building with newer giflib.

--- gif.c.orig	2002-07-09 19:26:41.000000000 +0000
+++ gif.c
@@ -20,7 +20,7 @@ static const char rcsid[] = "$Id: gif.c,
  */
 int gif_load_hdr(img I) {
     GifFileType *g;
-    g = I->us = DGifOpenFileHandle(fileno(I->fp));
+    g = I->us = DGifOpenFileHandle(fileno(I->fp), NULL);
     if (!I->us) {
         I->err = IE_HDRFORMAT;
         return 0;
@@ -36,7 +36,7 @@ int gif_load_hdr(img I) {
  * Abort loading a GIF file after the header is done.
  */
 int gif_abort_load(img I) {
-    DGifCloseFile((GifFileType*)I->us);
+    DGifCloseFile((GifFileType*)I->us, NULL);
     return 1;
 }
 
@@ -114,7 +114,7 @@ int gif_load_img(img I) {
     ret = 1;
 fail:
 
-    DGifCloseFile(g);
+    DGifCloseFile(g, NULL);
     
     return ret;
 }
