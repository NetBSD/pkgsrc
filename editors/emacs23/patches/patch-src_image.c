$NetBSD: patch-src_image.c,v 1.1 2013/07/05 13:36:12 ryoon Exp $

* Fix build with giflib 5.0.

--- src/image.c.orig	2012-01-11 12:35:01.000000000 +0000
+++ src/image.c
@@ -7350,7 +7350,7 @@ gif_load (f, img)
 	}
 
       /* Open the GIF file.  */
-      gif = fn_DGifOpenFileName (SDATA (file));
+      gif = fn_DGifOpenFileName (SDATA (file), NULL);
       if (gif == NULL)
 	{
 	  image_error ("Cannot open `%s'", file, Qnil);
@@ -7366,7 +7366,7 @@ gif_load (f, img)
       memsrc.len = SBYTES (specified_data);
       memsrc.index = 0;
 
-      gif = fn_DGifOpen (&memsrc, gif_read_from_memory);
+      gif = fn_DGifOpen (&memsrc, gif_read_from_memory, NULL);
       if (!gif)
 	{
 	  image_error ("Cannot open memory source `%s'", img->spec, Qnil);
