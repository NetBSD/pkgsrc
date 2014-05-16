$NetBSD: patch-src_image.c,v 1.2 2014/05/16 14:12:29 tron Exp $

* Fix build with giflib 5.1.

--- src/image.c.orig	2014-05-16 14:28:37.000000000 +0100
+++ src/image.c	2014-05-16 14:29:19.000000000 +0100
@@ -7270,7 +7270,7 @@
 
 #else
 
-#define fn_DGifCloseFile	DGifCloseFile
+#define fn_DGifCloseFile(gf)	DGifCloseFile((gf), NULL)
 #define fn_DGifSlurp		DGifSlurp
 #define fn_DGifOpen		DGifOpen
 #define fn_DGifOpenFileName	DGifOpenFileName
@@ -7350,7 +7350,7 @@
 	}
 
       /* Open the GIF file.  */
-      gif = fn_DGifOpenFileName (SDATA (file));
+      gif = fn_DGifOpenFileName (SDATA (file), NULL);
       if (gif == NULL)
 	{
 	  image_error ("Cannot open `%s'", file, Qnil);
@@ -7366,7 +7366,7 @@
       memsrc.len = SBYTES (specified_data);
       memsrc.index = 0;
 
-      gif = fn_DGifOpen (&memsrc, gif_read_from_memory);
+      gif = fn_DGifOpen (&memsrc, gif_read_from_memory, NULL);
       if (!gif)
 	{
 	  image_error ("Cannot open memory source `%s'", img->spec, Qnil);
