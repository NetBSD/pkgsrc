$NetBSD: patch-src_modules_loaders_loader__gif.c,v 1.2 2014/05/16 10:19:11 obache Exp $

* Fix build with giflib>=5.1.

--- src/modules/loaders/loader_gif.c.orig	2011-04-15 22:05:28.000000000 +0000
+++ src/modules/loaders/loader_gif.c
@@ -36,7 +36,7 @@ load(ImlibImage * im, ImlibProgressFunct
 #endif
    if (fd < 0)
       return 0;
-   gif = DGifOpenFileHandle(fd);
+   gif = DGifOpenFileHandle(fd, NULL);
    if (!gif)
      {
         close(fd);
@@ -60,13 +60,13 @@ load(ImlibImage * im, ImlibProgressFunct
              h = gif->Image.Height;
              if (!IMAGE_DIMENSIONS_OK(w, h))
                {
-                  DGifCloseFile(gif);
+                  DGifCloseFile(gif, NULL);
                   return 0;
                }
              rows = malloc(h * sizeof(GifRowType *));
              if (!rows)
                {
-                  DGifCloseFile(gif);
+                  DGifCloseFile(gif, NULL);
                   return 0;
                }
              for (i = 0; i < h; i++)
@@ -78,7 +78,7 @@ load(ImlibImage * im, ImlibProgressFunct
                   rows[i] = malloc(w * sizeof(GifPixelType));
                   if (!rows[i])
                     {
-                       DGifCloseFile(gif);
+                       DGifCloseFile(gif, NULL);
                        for (i = 0; i < h; i++)
                          {
                             if (rows[i])
@@ -150,7 +150,7 @@ load(ImlibImage * im, ImlibProgressFunct
         im->data = (DATA32 *) malloc(sizeof(DATA32) * w * h);
         if (!im->data)
           {
-             DGifCloseFile(gif);
+             DGifCloseFile(gif, NULL);
              free(rows);
              return 0;
           }
@@ -181,7 +181,7 @@ load(ImlibImage * im, ImlibProgressFunct
                        last_per = (int)per;
                        if (!(progress(im, (int)per, 0, last_y, w, i)))
                          {
-                            DGifCloseFile(gif);
+                            DGifCloseFile(gif, NULL);
                             for (i = 0; i < h; i++)
                               {
                                  free(rows[i]);
@@ -198,7 +198,7 @@ load(ImlibImage * im, ImlibProgressFunct
      {
         progress(im, 100, 0, last_y, w, h);
      }
-   DGifCloseFile(gif);
+   DGifCloseFile(gif, NULL);
    for (i = 0; i < h; i++)
      {
         free(rows[i]);
