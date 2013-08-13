$NetBSD: patch-gif.c,v 1.1 2013/08/13 10:23:26 joerg Exp $

--- gif.c.orig	2013-08-12 16:49:30.000000000 +0000
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
