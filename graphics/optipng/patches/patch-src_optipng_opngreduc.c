$NetBSD: patch-src_optipng_opngreduc.c,v 1.1 2012/03/19 12:39:55 adam Exp $

Fix colour reduction bug.

--- src/optipng/opngreduc.c.orig	2012-03-19 12:22:37.000000000 +0000
+++ src/optipng/opngreduc.c
@@ -1207,7 +1207,10 @@ opng_reduce_palette(png_structp png_ptr,
    }
 
    if (reductions & OPNG_REDUCE_8_TO_4_2_1)
+   {
       result |= opng_reduce_palette_bits(png_ptr, info_ptr, reductions);
+      bit_depth = png_get_bit_depth(png_ptr, info_ptr);
+   }
    if ((bit_depth < 8) || !is_gray)
       return result;
 
