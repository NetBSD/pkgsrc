$NetBSD: patch-src_modules_loaders_loader__gif.c,v 1.1 2013/07/06 05:58:03 ryoon Exp $

* Fix build with giflib 5.0.

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
