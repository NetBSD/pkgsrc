$NetBSD: patch-ax,v 1.3 2014/05/23 22:34:41 dholland Exp $

* Fix build with png-1.5.
* Fix build with giflib 5.0.
* Fix build with giflib 5.1.

--- src/xfns.c.orig	2002-12-06 17:05:35.000000000 +0000
+++ src/xfns.c
@@ -8541,7 +8541,11 @@ my_png_error (png_ptr, msg)
 {
   xassert (png_ptr != NULL);
   image_error ("PNG error: %s", build_string (msg), Qnil);
+#if (PNG_LIBPNG_VER < 10500)
   longjmp (png_ptr->jmpbuf, 1);
+#else
+  png_longjmp (png_ptr, 1);
+#endif
 }
 
 
@@ -8699,7 +8703,7 @@ png_load (f, img)
 
   /* Set error jump-back.  We come back here when the PNG library
      detects an error.  */
-  if (setjmp (png_ptr->jmpbuf))
+  if (setjmp (png_jmpbuf(png_ptr)))
     {
     error:
       if (png_ptr)
@@ -9759,7 +9763,7 @@ gif_load (f, img)
 	}
 
       /* Open the GIF file.  */
-      gif = DGifOpenFileName (XSTRING (file)->data);
+      gif = DGifOpenFileName (XSTRING (file)->data, NULL);
       if (gif == NULL)
 	{
 	  image_error ("Cannot open `%s'", file, Qnil);
@@ -9775,7 +9779,7 @@ gif_load (f, img)
       memsrc.len = STRING_BYTES (XSTRING (specified_data));
       memsrc.index = 0;
 
-      gif = DGifOpen(&memsrc, gif_read_from_memory);
+      gif = DGifOpen(&memsrc, gif_read_from_memory, NULL);
       if (!gif)
 	{
 	  image_error ("Cannot open memory source `%s'", img->spec, Qnil);
@@ -9789,7 +9793,7 @@ gif_load (f, img)
   if (rc == GIF_ERROR)
     {
       image_error ("Error reading `%s'", img->spec, Qnil);
-      DGifCloseFile (gif);
+      DGifCloseFile (gif, NULL);
       UNGCPRO;
       return 0;
     }
@@ -9800,7 +9804,7 @@ gif_load (f, img)
     {
       image_error ("Invalid image number `%s' in image `%s'",
 		   image, img->spec);
-      DGifCloseFile (gif);
+      DGifCloseFile (gif, NULL);
       UNGCPRO;
       return 0;
     }
@@ -9811,7 +9815,7 @@ gif_load (f, img)
   /* Create the X image and pixmap.  */
   if (!x_create_x_image_and_pixmap (f, width, height, 0, &ximg, &img->pixmap))
     {
-      DGifCloseFile (gif);
+      DGifCloseFile (gif, NULL);
       UNGCPRO;
       return 0;
     }
@@ -9903,7 +9907,7 @@ gif_load (f, img)
 	  }
     }
 
-  DGifCloseFile (gif);
+  DGifCloseFile (gif, NULL);
 
   /* Put the image into the pixmap, then free the X image and its buffer.  */
   x_put_x_image (f, ximg, img->pixmap, width, height);
