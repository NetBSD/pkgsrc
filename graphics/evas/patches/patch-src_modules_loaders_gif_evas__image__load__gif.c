$NetBSD: patch-src_modules_loaders_gif_evas__image__load__gif.c,v 1.1 2013/08/30 22:35:53 joerg Exp $

--- src/modules/loaders/gif/evas_image_load_gif.c.orig	2013-08-30 21:25:51.000000000 +0000
+++ src/modules/loaders/gif/evas_image_load_gif.c
@@ -700,7 +700,7 @@ evas_image_load_file_head_gif(Image_Entr
         return EINA_FALSE;
      }
 
-   gif = DGifOpenFileHandle(fd);
+   gif = DGifOpenFileHandle(fd, NULL);
    if (!gif)
      {
         if (fd) close(fd);
@@ -838,7 +838,7 @@ evas_image_load_specific_frame(Image_Ent
         return EINA_FALSE;
      }
 
-   gif = DGifOpenFileHandle(fd);
+   gif = DGifOpenFileHandle(fd, NULL);
    if (!gif)
      {
         if (fd) close(fd);
@@ -927,7 +927,7 @@ evas_image_load_file_data_gif(Image_Entr
                   return EINA_FALSE;
                }
 
-             gif = DGifOpenFileHandle(fd);
+             gif = DGifOpenFileHandle(fd, NULL);
              if (!gif)
                {
                   if (fd) close(fd);
@@ -1000,7 +1000,7 @@ evas_image_load_frame_duration_gif(Image
 #endif
    if (fd < 0) return -1;
 
-   gif = DGifOpenFileHandle(fd);
+   gif = DGifOpenFileHandle(fd, NULL);
    if (!gif)
      {
         if (fd) close(fd);
