$NetBSD: patch-src_image.c,v 1.2 2014/05/16 09:08:57 tron Exp $

Fix build with giflib 5.1.

--- src/image.c.orig	2013-01-01 20:37:17.000000000 +0000
+++ src/image.c	2014-05-16 09:42:14.000000000 +0100
@@ -7121,7 +7121,7 @@
 
 #else
 
-#define fn_DGifCloseFile	DGifCloseFile
+#define fn_DGifCloseFile(gf)	DGifCloseFile((gf), NULL)
 #define fn_DGifSlurp		DGifSlurp
 #define fn_DGifOpen		DGifOpen
 #define fn_DGifOpenFileName	DGifOpenFileName
@@ -7192,7 +7192,7 @@
 	}
 
       /* Open the GIF file.  */
-      gif = fn_DGifOpenFileName (SSDATA (file));
+      gif = fn_DGifOpenFileName (SSDATA (file), NULL);
       if (gif == NULL)
 	{
 	  image_error ("Cannot open `%s'", file, Qnil);
@@ -7213,7 +7213,7 @@
       memsrc.len = SBYTES (specified_data);
       memsrc.index = 0;
 
-      gif = fn_DGifOpen (&memsrc, gif_read_from_memory);
+      gif = fn_DGifOpen (&memsrc, gif_read_from_memory, NULL);
       if (!gif)
 	{
 	  image_error ("Cannot open memory source `%s'", img->spec, Qnil);
