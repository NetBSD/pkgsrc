$NetBSD: patch-src_gfxoutputdrv_gifdrv.c,v 1.1 2014/05/25 09:44:43 obache Exp $

* Fixes for giflib-5.1 API change

--- src/gfxoutputdrv/gifdrv.c.orig	2012-07-25 23:46:05.000000000 +0000
+++ src/gfxoutputdrv/gifdrv.c
@@ -49,6 +49,11 @@
 #define VICE_MakeMapObject MakeMapObject
 #define VICE_FreeMapObject FreeMapObject
 #endif
+#if GIFLIB_MAJOR >= 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+#define VICE_EGifCloseFile(x) EGifCloseFile(x, NULL)
+#else
+#define VICE_EGifCloseFile(x) EGifCloseFile(x)
+#endif
 
 typedef struct gfxoutputdrv_data_s
 {
@@ -114,7 +119,7 @@ static int gifdrv_open(screenshot_t *scr
   if (EGifPutScreenDesc(sdata->fd, screenshot->width, screenshot->height, 8, 0, gif_colors) == GIF_ERROR ||
       EGifPutImageDesc(sdata->fd, 0, 0, screenshot->width, screenshot->height, 0, NULL) == GIF_ERROR)
   {
-    EGifCloseFile(sdata->fd);
+    VICE_EGifCloseFile(sdata->fd);
     VICE_FreeMapObject(gif_colors);
     lib_free(sdata->data);
     lib_free(sdata->ext_filename);
@@ -145,7 +150,7 @@ static int gifdrv_close(screenshot_t *sc
 
     sdata = screenshot->gfxoutputdrv_data;
 
-    EGifCloseFile(sdata->fd);
+    VICE_EGifCloseFile(sdata->fd);
     VICE_FreeMapObject(gif_colors);
 
     /* for some reason giflib will create a file with unexpected
@@ -184,7 +189,7 @@ static char *gifdrv_memmap_ext_filename;
 
 static int gifdrv_close_memmap(void)
 {
-  EGifCloseFile(gifdrv_memmap_fd);
+  VICE_EGifCloseFile(gifdrv_memmap_fd);
   VICE_FreeMapObject(gif_colors);
   lib_free(gifdrv_memmap_ext_filename);
 
@@ -231,7 +236,7 @@ static int gifdrv_open_memmap(const char
   if (EGifPutScreenDesc(gifdrv_memmap_fd, x_size, y_size, 8, 0, gif_colors) == GIF_ERROR ||
       EGifPutImageDesc(gifdrv_memmap_fd, 0, 0, x_size, y_size, 0, NULL) == GIF_ERROR)
   {
-    EGifCloseFile(gifdrv_memmap_fd);
+    VICE_EGifCloseFile(gifdrv_memmap_fd);
     VICE_FreeMapObject(gif_colors);
     lib_free(gifdrv_memmap_ext_filename);
     return -1;
