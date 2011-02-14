$NetBSD: patch-src_im__png.c,v 1.2 2011/02/14 19:16:14 wiz Exp $

Fix build with png-1.5.
http://developer.berlios.de/patch/?func=detailpatch&patch_id=3131&group_id=735

--- src/im_png.c.orig	2004-02-14 15:16:33.000000000 +0000
+++ src/im_png.c
@@ -55,7 +55,7 @@ my_error_exit(png_struct *pp, guchar *w)
  */
 
 gboolean
-png_get_header(gchar *filename, png_info *info)
+png_get_header(gchar *filename, gint *width, gint *height, png_bytep color_type)
 {
    png_struct  *pp;
    png_info    *linfo;
@@ -99,10 +99,9 @@ png_get_header(gchar *filename, png_info
    png_init_io(pp, fp);
    png_read_info(pp, linfo);
 
-   info->width       = linfo->width;
-   info->height      = linfo->height;
-   info->valid       = linfo->valid;
-   info->color_type  = linfo->color_type;
+   *width       = png_get_image_width(pp, linfo);
+   *height      = png_get_image_height(pp, linfo);
+   *color_type  = png_get_color_type(pp, linfo);
 
    g_free(linfo);
    g_free(pp);
@@ -161,26 +160,30 @@ png_load(gchar *filename, PngLoadFunc fu
    png_init_io(pp, fp);
    png_read_info(pp, info);
 
-   if (info->bit_depth < 8)
+   if (png_get_bit_depth(pp, info) < 8)
    {
       png_set_packing(pp);
       png_set_expand(pp);
 
-      if (info->valid & PNG_INFO_sBIT)
-         png_set_shift(pp, &(info->sig_bit));
+      if (png_get_valid(pp, info, PNG_INFO_sBIT)) {
+         png_color_8p sig_bit;
+         png_get_sBIT(pp, info, &sig_bit);
+
+         png_set_shift(pp, sig_bit);
+      }
    } else
-   if (info->bit_depth == 16)
+   if (png_get_bit_depth(pp, info) == 16)
       png_set_strip_16(pp);
 
    /*
     * Turn on interlace handling...
     */
-   if (info->interlace_type)
+   if (png_get_interlace_type(pp, info))
       num_passes = png_set_interlace_handling(pp);
    else
       num_passes = 1;
 
-   switch (info->color_type)
+   switch (png_get_color_type(pp, info))
    {
       case PNG_COLOR_TYPE_RGB :           /* RGB */
          bpp = 3;
@@ -195,22 +198,30 @@ png_load(gchar *filename, PngLoadFunc fu
          bpp = 2;
          break;
       case PNG_COLOR_TYPE_PALETTE :       /* Indexed */
-         bpp = info->num_trans ? 4:3;
+         {
+           png_bytep trans_alpha;
+           int num_trans;
+           png_color_16p trans_color;
+
+           png_get_tRNS(pp, info, &trans_alpha, &num_trans, &trans_color);
+
+           bpp = num_trans ? 4:3;
+         }
          break;
    };
 
-   pixel = g_malloc(sizeof(guchar) * info->width * bpp);
+   pixel = g_malloc(sizeof(guchar) * png_get_image_width(pp, info) * bpp);
 
    for (pass = 0; pass < num_passes; pass++)
    {
-      for (scanline = 0; scanline < info->height; scanline++)
+      for (scanline = 0; scanline < png_get_image_height(pp, info); scanline++)
       {
-         if (info->color_type == PNG_COLOR_TYPE_PALETTE)
+         if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE)
             png_set_expand(pp);
 
             png_read_row(pp, pixel, NULL);
 
-         if ((*func) (pixel, info->width, 0, scanline, bpp, -1, 0)) goto png_read_cancelled;
+         if ((*func) (pixel, png_get_image_width(pp, info), 0, scanline, bpp, -1, 0)) goto png_read_cancelled;
       };
    };
 
