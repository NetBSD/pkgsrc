$NetBSD: patch-src_detect.c,v 1.1 2011/02/07 01:31:57 wiz Exp $

Fix build with png-1.5.

--- src/detect.c.orig	2004-02-14 15:16:33.000000000 +0000
+++ src/detect.c
@@ -119,14 +119,16 @@ static gboolean
 detect_png(guchar *filename, ImageInfo *info)
 {
 #ifdef HAVE_LIBPNG
-   png_info pnginfo;
+   gint width;
+   gint height;
+   png_byte color_type;
 
-   if (png_get_header(filename, &pnginfo))
+   if (png_get_header(filename, &width, &height, &color_type))
    {
       info->type = PNG;
-      info->width = pnginfo.width;
-      info->height = pnginfo.height;
-      switch (pnginfo.color_type)
+      info->width = width;
+      info->height = height;
+      switch (color_type)
       {
          case PNG_COLOR_TYPE_RGB :
             info->ncolors = 24;
