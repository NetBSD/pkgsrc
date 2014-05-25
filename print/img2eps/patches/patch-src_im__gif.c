$NetBSD: patch-src_im__gif.c,v 1.2 2014/05/25 07:49:13 obache Exp $

* giflib>=5.0 API change

--- src/im_gif.c.orig	2005-01-04 19:18:57.000000000 +0000
+++ src/im_gif.c
@@ -77,10 +77,12 @@ static const char *_errstr(int err);
 void
 gif_close(image_gif *im)
 {
+    int giferror;
+
     free(im->pal);
 
-    if (DGifCloseFile(im->gif) != GIF_OK)
-	throwf(EIO, "error closing: %s", _errstr(GifLastError()));
+    if (DGifCloseFile(im->gif, &giferror) != GIF_OK)
+	throwf(EIO, "error closing: %s", _errstr(giferror));
 
     image_free((image *)im);
 }
@@ -115,8 +117,9 @@ gif_open(char *fname)
     image_gif *im;
     GifFileType *gif;
     exception ex;
+    int giferror;
 
-    if ((gif=DGifOpenFileName(fname)) == NULL)
+    if ((gif=DGifOpenFileName(fname, &giferror)) == NULL)
 	return NULL;
 
     if (catch(&ex) == 0) {
@@ -124,7 +127,7 @@ gif_open(char *fname)
 	drop();
     }
     else {
-	DGifCloseFile(im->gif);
+	DGifCloseFile(im->gif, NULL);
 	throw(&ex);
     }
 
@@ -196,7 +199,7 @@ gif_read_start(image_gif *im)
 
     if (DGifSlurp(im->gif) != GIF_OK)
 	throwf(EIO, "error reading image: %s",
-	       _errstr(GifLastError()));
+	       _errstr(im->gif->Error));
 
     if (im->gif->ImageCount != 1)
 	throws(EOPNOTSUPP, "multi-image GIFs not supported");
