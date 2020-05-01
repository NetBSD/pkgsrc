$NetBSD: patch-src_modules_loaders_gif_evas__image__load__gif.c,v 1.3 2020/05/01 00:08:22 joerg Exp $

--- src/modules/loaders/gif/evas_image_load_gif.c.orig	2013-08-01 15:41:35.000000000 +0000
+++ src/modules/loaders/gif/evas_image_load_gif.c
@@ -338,7 +338,7 @@ _evas_image_load_frame_image_data(Image_
 
    if (!cmap)
      {
-        DGifCloseFile(gif);
+        DGifCloseFile(gif, NULL);
         for (i = 0; i < scale_h; i++)
           {
              free(rows[i]);
@@ -725,7 +725,7 @@ evas_image_load_file_head_gif(Image_Entr
    if ((w < 1) || (h < 1) || (w > IMG_MAX_SIZE) || (h > IMG_MAX_SIZE) ||
        IMG_TOO_BIG(w, h))
      {
-        DGifCloseFile(gif);
+        DGifCloseFile(gif, NULL);
         if (IMG_TOO_BIG(w, h))
           *error = EVAS_LOAD_ERROR_RESOURCE_ALLOCATION_FAILED;
         else
@@ -740,7 +740,7 @@ evas_image_load_file_head_gif(Image_Entr
         if (DGifGetRecordType(gif, &rec) == GIF_ERROR)
           {
              /* PrintGifError(); */
-             DGifCloseFile(gif);
+             DGifCloseFile(gif, NULL);
              *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
              return EINA_FALSE;
           }
@@ -754,7 +754,7 @@ evas_image_load_file_head_gif(Image_Entr
              if (DGifGetImageDesc(gif) == GIF_ERROR)
                {
                   /* PrintGifError(); */
-                  DGifCloseFile(gif);
+                  DGifCloseFile(gif, NULL);
                   *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                   return EINA_FALSE;
                }
@@ -762,7 +762,7 @@ evas_image_load_file_head_gif(Image_Entr
              if (DGifGetCode(gif, &img_code, &img) == GIF_ERROR)
                {
                   /* PrintGifError(); */
-                  DGifCloseFile(gif);
+                  DGifCloseFile(gif, NULL);
                   *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                   return EINA_FALSE;
                }
@@ -818,7 +818,7 @@ evas_image_load_file_head_gif(Image_Entr
         ie->frames = NULL;
      }
 
-   DGifCloseFile(gif);
+   DGifCloseFile(gif, NULL);
    *error = EVAS_LOAD_ERROR_NONE;
    return EINA_TRUE;
 }
@@ -885,7 +885,7 @@ evas_image_load_specific_frame(Image_Ent
      }
 
    ie->frames = eina_list_append(ie->frames, frame);
-   DGifCloseFile(gif);
+   DGifCloseFile(gif, NULL);
    return EINA_TRUE;
 }
 
@@ -959,7 +959,7 @@ evas_image_load_file_data_gif(Image_Entr
                   *error = EVAS_LOAD_ERROR_UNKNOWN_FORMAT;
                   return EINA_FALSE;
                }
-             DGifCloseFile(gif);
+             DGifCloseFile(gif, NULL);
              *error = EVAS_LOAD_ERROR_NONE;
              return EINA_TRUE;
           }
@@ -1080,7 +1080,7 @@ evas_image_load_frame_duration_gif(Image
          }
      } while (rec != TERMINATE_RECORD_TYPE);
 
-   DGifCloseFile(gif);
+   DGifCloseFile(gif, NULL);
    return duration;
 }
 
