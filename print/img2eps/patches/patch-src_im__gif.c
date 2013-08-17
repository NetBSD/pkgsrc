$NetBSD: patch-src_im__gif.c,v 1.1 2013/08/17 11:17:48 joerg Exp $

--- src/im_gif.c.orig	2013-08-15 18:22:38.000000000 +0000
+++ src/im_gif.c
@@ -71,6 +71,7 @@ struct image_gif {
 IMAGE_DECLARE(gif);
 
 static const char *_errstr(int err);
+static int giferror;
 
 
 
@@ -80,7 +81,7 @@ gif_close(image_gif *im)
     free(im->pal);
 
     if (DGifCloseFile(im->gif) != GIF_OK)
-	throwf(EIO, "error closing: %s", _errstr(GifLastError()));
+	throwf(EIO, "error closing: %s", _errstr(giferror));
 
     image_free((image *)im);
 }
@@ -116,7 +117,7 @@ gif_open(char *fname)
     GifFileType *gif;
     exception ex;
 
-    if ((gif=DGifOpenFileName(fname)) == NULL)
+    if ((gif=DGifOpenFileName(fname, &giferror)) == NULL)
 	return NULL;
 
     if (catch(&ex) == 0) {
@@ -196,7 +197,7 @@ gif_read_start(image_gif *im)
 
     if (DGifSlurp(im->gif) != GIF_OK)
 	throwf(EIO, "error reading image: %s",
-	       _errstr(GifLastError()));
+	       _errstr(giferror));
 
     if (im->gif->ImageCount != 1)
 	throws(EOPNOTSUPP, "multi-image GIFs not supported");
