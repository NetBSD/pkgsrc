$NetBSD: patch-src_gd__png.c,v 1.1 2013/06/30 15:13:09 ryoon Exp $

* Fix build with png-1.5.

--- src/gd_png.c.orig	2010-03-02 21:01:01.000000000 +0000
+++ src/gd_png.c
@@ -268,7 +268,7 @@ gdImagePtr gdImageCreateFromPngCtx(gdIOC
                 png_color_16p histogram;
 
                 png_get_hIST(png_ptr, info_ptr, &histogram);
-                png_set_dither(png_ptr, palette, num_palette,
+                png_set_quantize(png_ptr, palette, num_palette,
                   max_screen_colors, histogram, 1);
             } else
 #endif
@@ -294,7 +294,7 @@ gdImagePtr gdImageCreateFromPngCtx(gdIOC
                 palette[2].red = palette[2].green = palette[2].blue = 128;
                 palette[3].red = palette[3].green = palette[3].blue = 64;
                 /* final argument (full_dither) *must* be 1: */
-                png_set_dither(png_ptr, palette, 256, 256, NULL, 1);
+                png_set_quantize(png_ptr, palette, 256, 256, NULL, 1);
 #else
                 /* allocate a 6x6x6 color cube, starting at index 0 or 1 */
                 idx = (transparent < 0)? 0 : 1;
