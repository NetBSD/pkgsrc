$NetBSD: patch-src_image.c,v 1.1 2013/07/05 13:33:40 ryoon Exp $

* Fix build with giflib 5.0.

--- src/image.c.orig	2013-01-01 20:37:17.000000000 +0000
+++ src/image.c
@@ -7192,7 +7192,7 @@ gif_load (struct frame *f, struct image 
 	}
 
       /* Open the GIF file.  */
-      gif = fn_DGifOpenFileName (SSDATA (file));
+      gif = fn_DGifOpenFileName (SSDATA (file), NULL);
       if (gif == NULL)
 	{
 	  image_error ("Cannot open `%s'", file, Qnil);
@@ -7213,7 +7213,7 @@ gif_load (struct frame *f, struct image 
       memsrc.len = SBYTES (specified_data);
       memsrc.index = 0;
 
-      gif = fn_DGifOpen (&memsrc, gif_read_from_memory);
+      gif = fn_DGifOpen (&memsrc, gif_read_from_memory, NULL);
       if (!gif)
 	{
 	  image_error ("Cannot open memory source `%s'", img->spec, Qnil);
