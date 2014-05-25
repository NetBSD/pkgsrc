$NetBSD: patch-src_modules_loaders_gif_evas__image__load__gif.c,v 1.2 2014/05/25 08:12:26 obache Exp $

* Adapt to giflib>=5 API changes

--- src/modules/loaders/gif/evas_image_load_gif.c.orig	2012-11-23 16:35:06.000000000 +0000
+++ src/modules/loaders/gif/evas_image_load_gif.c
@@ -338,7 +338,7 @@ _evas_image_load_frame_image_data(Image_
 
    if (!cmap)
      {
-        DGifCloseFile(gif);
+        DGifCloseFile(gif, NULL);
         for (i = 0; i < scale_h; i++)
           {
              free(rows[i]);
@@ -700,7 +700,7 @@ evas_image_load_file_head_gif(Image_Entr
         return EINA_FALSE;
      }
 
-   gif = DGifOpenFileHandle(fd);
+   gif = DGifOpenFileHandle(fd, NULL);
    if (!gif)
      {
         if (fd) close(fd);
@@ -721,7 +721,7 @@ evas_image_load_file_head_gif(Image_Entr
    if ((w < 1) || (h < 1) || (w > IMG_MAX_SIZE) || (h > IMG_MAX_SIZE) ||
        IMG_TOO_BIG(w, h))
      {
-        DGifCloseFile(gif);
+        DGifCloseFile(gif, NULL);
         if (IMG_TOO_BIG(w, h))
           *error = EVAS_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED;
         else
@@ -736,7 +736,7 @@ evas_image_load_file_head_gif(Image_Entr
         if (DGifGetRecordType(gif, &rec) == GIF_ERROR)
           {
              /* PrintGifError(); */
-             DGifCloseFile(gif);
+             DGifCloseFile(gif, NULL);
              *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
              return EINA_FALSE;
           }
@@ -750,7 +750,7 @@ evas_image_load_file_head_gif(Image_Entr
              if (DGifGetImageDesc(gif) == GIF_ERROR)
                {
                   /* PrintGifError(); */
-                  DGifCloseFile(gif);
+                  DGifCloseFile(gif, NULL);
                   *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                   return EINA_FALSE;
                }
@@ -758,7 +758,7 @@ evas_image_load_file_head_gif(Image_Entr
              if (DGifGetCode(gif, &img_code, &img) == GIF_ERROR)
                {
                   /* PrintGifError(); */
-                  DGifCloseFile(gif);
+                  DGifCloseFile(gif, NULL);
                   *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                   return EINA_FALSE;
                }
@@ -814,7 +814,7 @@ evas_image_load_file_head_gif(Image_Entr
         ie->frames = NULL;
      }
 
-   DGifCloseFile(gif);
+   DGifCloseFile(gif, NULL);
    *error = EVAS_LOAD_ERROR_NONE;
    return EINA_TRUE;
 }
@@ -838,7 +838,7 @@ evas_image_load_specific_frame(Image_Ent
         return EINA_FALSE;
      }
 
-   gif = DGifOpenFileHandle(fd);
+   gif = DGifOpenFileHandle(fd, NULL);
    if (!gif)
      {
         if (fd) close(fd);
@@ -877,7 +877,7 @@ evas_image_load_specific_frame(Image_Ent
      }
 
    ie->frames = eina_list_append(ie->frames, frame);
-   DGifCloseFile(gif);
+   DGifCloseFile(gif, NULL);
    return EINA_TRUE;
 }
 
@@ -927,7 +927,7 @@ evas_image_load_file_data_gif(Image_Entr
                   return EINA_FALSE;
                }
 
-             gif = DGifOpenFileHandle(fd);
+             gif = DGifOpenFileHandle(fd, NULL);
              if (!gif)
                {
                   if (fd) close(fd);
@@ -947,7 +947,7 @@ evas_image_load_file_data_gif(Image_Entr
                   *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                   return EINA_FALSE;
                }
-             DGifCloseFile(gif);
+             DGifCloseFile(gif, NULL);
              *error = EVAS_LOAD_ERROR_NONE;
              return EINA_TRUE;
           }
@@ -1000,7 +1000,7 @@ evas_image_load_frame_duration_gif(Image
 #endif
    if (fd < 0) return -1;
 
-   gif = DGifOpenFileHandle(fd);
+   gif = DGifOpenFileHandle(fd, NULL);
    if (!gif)
      {
         if (fd) close(fd);
@@ -1064,7 +1064,7 @@ evas_image_load_frame_duration_gif(Image
          }
      } while (rec != TERMINATE_RECORD_TYPE);
 
-   DGifCloseFile(gif);
+   DGifCloseFile(gif, NULL);
    return duration;
 }
 
