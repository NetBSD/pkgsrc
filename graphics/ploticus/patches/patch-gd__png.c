$NetBSD: patch-gd__png.c,v 1.1 2011/04/03 11:58:22 wiz Exp $

Fix build with png-1.5.

--- gd_png.c.orig	1999-07-29 23:25:50.000000000 +0000
+++ gd_png.c
@@ -265,7 +265,7 @@ gdImagePtr gdImageCreateFromPngCtx(gdIOC
                 png_color_16p histogram;
 
                 png_get_hIST(png_ptr, info_ptr, &histogram);
-                png_set_dither(png_ptr, palette, num_palette,
+                png_set_quantize(png_ptr, palette, num_palette,
                   max_screen_colors, histogram, 1);
             } else
 #endif
@@ -291,7 +291,7 @@ gdImagePtr gdImageCreateFromPngCtx(gdIOC
                 palette[2].red = palette[2].green = palette[2].blue = 128;
                 palette[3].red = palette[3].green = palette[3].blue = 64;
                 /* final argument (full_dither) *must* be 1: */
-                png_set_dither(png_ptr, palette, 256, 256, NULL, 1);
+                png_set_quantize(png_ptr, palette, 256, 256, NULL, 1);
 #else
                 /* allocate a 6x6x6 color cube, starting at index 0 or 1 */
                 idx = (transparent < 0)? 0 : 1;
@@ -305,7 +305,7 @@ gdImagePtr gdImageCreateFromPngCtx(gdIOC
                         }
                     }
                 }
-                png_set_dither(png_ptr, palette, idx, idx, NULL, 1);
+                png_set_quantize(png_ptr, palette, idx, idx, NULL, 1);
 #endif
             }
             break;
