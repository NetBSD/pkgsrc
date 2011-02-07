$NetBSD: patch-plug-ins_common_png.c,v 1.1 2011/02/07 21:09:13 wiz Exp $

Fix build with png-1.5.

--- plug-ins/common/png.c.orig	2003-05-08 21:34:37.000000000 +0000
+++ plug-ins/common/png.c
@@ -465,7 +465,7 @@ load_image (gchar *filename)    /* I - F
   info = (png_infop)calloc(sizeof(png_info), 1);
 #endif /* PNG_LIBPNG_VER > 88 */
 
-  if (setjmp (pp->jmpbuf))
+  if (setjmp (png_jmpbuf(pp)))
   {
     g_message (_("%s\nPNG error. File corrupted?"), filename);
     return image;
@@ -507,15 +507,15 @@ load_image (gchar *filename)    /* I - F
   * Latest attempt, this should be my best yet :)
   */
 
-  if (info->bit_depth == 16) {
+  if (png_get_bit_depth(pp, info) == 16) {
     png_set_strip_16(pp);
   }
 
-  if (info->color_type == PNG_COLOR_TYPE_GRAY && info->bit_depth < 8) {
+  if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_GRAY && png_get_bit_depth(pp, info) < 8) {
     png_set_expand(pp);
   }
 
-  if (info->color_type == PNG_COLOR_TYPE_PALETTE && info->bit_depth < 8) {
+  if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE && png_get_bit_depth(pp, info) < 8) {
     png_set_packing(pp);
   }
 
@@ -523,8 +523,8 @@ load_image (gchar *filename)    /* I - F
   * Expand G+tRNS to GA, RGB+tRNS to RGBA
   */
 
-  if (info->color_type != PNG_COLOR_TYPE_PALETTE &&
-                       (info->valid & PNG_INFO_tRNS)) {
+  if (png_get_color_type(pp, info) != PNG_COLOR_TYPE_PALETTE &&
+                       (png_get_valid(pp, info, PNG_INFO_tRNS))) {
     png_set_expand(pp);
   }
 
@@ -541,7 +541,7 @@ load_image (gchar *filename)    /* I - F
 
 #if PNG_LIBPNG_VER > 99
   if (png_get_valid(pp, info, PNG_INFO_tRNS) &&
-      info->color_type == PNG_COLOR_TYPE_PALETTE)
+      png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE)
   {
     png_get_tRNS(pp, info, &alpha_ptr, &num, NULL);
     /* Copy the existing alpha values from the tRNS chunk */
@@ -564,7 +564,7 @@ load_image (gchar *filename)    /* I - F
 
   png_read_update_info(pp, info);
   
-  switch (info->color_type)
+  switch (png_get_color_type(pp, info))
   {
     case PNG_COLOR_TYPE_RGB :           /* RGB */
         bpp        = 3;
@@ -600,7 +600,7 @@ load_image (gchar *filename)    /* I - F
         return -1;
   };
 
-  image = gimp_image_new(info->width, info->height, image_type);
+  image = gimp_image_new(png_get_image_width(pp, info), png_get_image_height(pp, info), image_type);
   if (image == -1)
   {
     g_message("Can't allocate new image\n%s", filename);
@@ -611,7 +611,7 @@ load_image (gchar *filename)    /* I - F
   * Create the "background" layer to hold the image...
   */
 
-  layer = gimp_layer_new(image, _("Background"), info->width, info->height,
+  layer = gimp_layer_new(image, _("Background"), png_get_image_width(pp, info), png_get_image_height(pp, info),
                          layer_type, 100, GIMP_NORMAL_MODE);
   gimp_image_add_layer(image, layer, 0);
 
@@ -645,20 +645,23 @@ load_image (gchar *filename)    /* I - F
 
   empty= 0; /* by default assume no full transparent palette entries */
 
-  if (info->color_type & PNG_COLOR_MASK_PALETTE) {
+  if (png_get_color_type(pp, info) & PNG_COLOR_MASK_PALETTE) {
+    png_colorp palette;
+    int num_palette;
+    png_get_PLTE(pp, info, &palette, &num_palette);
 
 #if PNG_LIBPNG_VER > 99
     if (png_get_valid(pp, info, PNG_INFO_tRNS)) {
       for (empty= 0; empty < 256 && alpha[empty] == 0; ++empty);
         /* Calculates number of fully transparent "empty" entries */
 
-      gimp_image_set_cmap(image, (guchar *) (info->palette + empty),
-                          info->num_palette - empty);
+      gimp_image_set_cmap(image, (guchar *) (palette + empty),
+                          num_palette - empty);
     } else {
-      gimp_image_set_cmap(image, (guchar *)info->palette, info->num_palette);
+      gimp_image_set_cmap(image, (guchar *)palette, num_palette);
     }
 #else
-    gimp_image_set_cmap(image, (guchar *)info->palette, info->num_palette);
+    gimp_image_set_cmap(image, (guchar *)palette, num_palette);
 #endif /* PNG_LIBPNG_VER > 99 */
 
   }
@@ -677,11 +680,11 @@ load_image (gchar *filename)    /* I - F
   */
 
   tile_height = gimp_tile_height ();
-  pixel       = g_new(guchar, tile_height * info->width * bpp);
+  pixel       = g_new(guchar, tile_height * png_get_image_width(pp, info) * bpp);
   pixels      = g_new(guchar *, tile_height);
 
   for (i = 0; i < tile_height; i ++)
-    pixels[i] = pixel + info->width * info->channels * i;
+    pixels[i] = pixel + png_get_image_width(pp, info) * png_get_channels(pp, info) * i;
 
   for (pass = 0; pass < num_passes; pass ++)
   {
@@ -690,11 +693,11 @@ load_image (gchar *filename)    /* I - F
     */
 
     for (begin = 0, end = tile_height;
-         begin < info->height;
+         begin < png_get_image_height(pp, info);
          begin += tile_height, end += tile_height)
     {
-      if (end > info->height)
-        end = info->height;
+      if (end > png_get_image_height(pp, info))
+        end = png_get_image_height(pp, info);
 
       num = end - begin;
         
@@ -707,7 +710,7 @@ load_image (gchar *filename)    /* I - F
       gimp_pixel_rgn_set_rect(&pixel_rgn, pixel, 0, begin,
                               drawable->width, num);
 
-      gimp_progress_update(((double)pass + (double)end / (double)info->height) /
+      gimp_progress_update(((double)pass + (double)end / (double)png_get_image_height(pp, info)) /
                            (double)num_passes);
     };
   };
@@ -806,6 +809,8 @@ save_image (gchar  *filename,           
                 blue;           /* Used for palette background */
   time_t        cutime;         /* Time since epoch */
   struct tm     *gmt;           /* GMT broken down */
+  int color_type;               /* type of colors in image */
+  int bit_depth;                /* width of colors in bit */
 
   guchar remap [256];    /* Re-mapping for the palette */
 
@@ -824,7 +829,7 @@ save_image (gchar  *filename,           
   info = (png_infop)calloc(sizeof(png_info), 1);
 #endif /* PNG_LIBPNG_VER > 88 */
 
-  if (setjmp (pp->jmpbuf))
+  if (setjmp (png_jmpbuf(pp)))
   {
     g_message (_("%s\nPNG error. Couldn't save image"), filename);
     return 0;
@@ -863,11 +868,6 @@ save_image (gchar  *filename,           
 
   png_set_compression_level (pp, pngvals.compression_level);
 
-  info->width          = drawable->width;
-  info->height         = drawable->height;
-  info->bit_depth      = 8;
-  info->interlace_type = pngvals.interlaced;
-
  /* 
   * Initialise remap[]
   */
@@ -883,31 +883,29 @@ save_image (gchar  *filename,           
   switch (type)
   {
     case GIMP_RGB_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_RGB;
+        color_type = PNG_COLOR_TYPE_RGB;
         bpp              = 3;
         break;
     case GIMP_RGBA_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_RGB_ALPHA;
+        color_type = PNG_COLOR_TYPE_RGB_ALPHA;
         bpp              = 4;
         break;
     case GIMP_GRAY_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_GRAY;
+        color_type = PNG_COLOR_TYPE_GRAY;
         bpp              = 1;
         break;
     case GIMP_GRAYA_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_GRAY_ALPHA;
+        color_type = PNG_COLOR_TYPE_GRAY_ALPHA;
         bpp              = 2;
         break;
     case GIMP_INDEXED_IMAGE :
         bpp              = 1;
-        info->color_type = PNG_COLOR_TYPE_PALETTE;
-        info->valid      |= PNG_INFO_PLTE;
-        info->palette= (png_colorp) gimp_image_get_cmap(image_ID, &num_colors);
-        info->num_palette= num_colors;
+        color_type = PNG_COLOR_TYPE_PALETTE;
+        png_set_PLTE(pp, info, (png_colorp) gimp_image_get_cmap (image_ID, &num_colors), num_colors);
         break;
     case GIMP_INDEXEDA_IMAGE :
         bpp              = 2;
-        info->color_type = PNG_COLOR_TYPE_PALETTE;
+        color_type = PNG_COLOR_TYPE_PALETTE;
         respin_cmap (pp, info, remap, image_ID, drawable); /* fix up transparency */
         break;
     default:
@@ -919,16 +917,22 @@ save_image (gchar  *filename,           
   * Fix bit depths for (possibly) smaller colormap images
   */
   
-  if (info->valid & PNG_INFO_PLTE) {
-    if (info->num_palette <= 2)
-      info->bit_depth= 1;
-    else if (info->num_palette <= 4)
-      info->bit_depth= 2;
-    else if (info->num_palette <= 16)
-      info->bit_depth= 4;
+  if (png_get_valid(pp, info, PNG_INFO_PLTE)) {
+    png_colorp palette;
+    int num_palette;
+    png_get_PLTE(pp, info, &palette, &num_palette);
+
+    if (num_palette <= 2)
+      bit_depth = 1;
+    else if (num_palette <= 4)
+      bit_depth = 2;
+    else if (num_palette <= 16)
+      bit_depth = 4;
     /* otherwise the default is fine */
   }
 
+  png_set_IHDR(pp, info, drawable->width, drawable->height, bit_depth, color_type, pngvals.interlaced ? PNG_INTERLACE_ADAM7 : PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
+
   /* All this stuff is optional extras, if the user is aiming for smallest
      possible file size she can turn them all off */
 
@@ -991,7 +995,7 @@ save_image (gchar  *filename,           
   * Convert unpacked pixels to packed if necessary
   */
 
-  if (info->color_type == PNG_COLOR_TYPE_PALETTE && info->bit_depth < 8)
+  if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE && png_get_bit_depth(pp, info) < 8)
     png_set_packing(pp);
 
  /*
@@ -1021,7 +1025,7 @@ save_image (gchar  *filename,           
         num = end - begin;
         
         gimp_pixel_rgn_get_rect (&pixel_rgn, pixel, 0, begin, drawable->width, num);
-        if (info->valid & PNG_INFO_tRNS) 
+        if (png_get_valid(pp, info, PNG_INFO_tRNS))
           {
             for (i = 0; i < num; ++i) 
               {
@@ -1036,7 +1040,7 @@ save_image (gchar  *filename,           
               }
             /* Forgot this case before, what if there are too many colors? */
           } 
-        else if (info->valid & PNG_INFO_PLTE && bpp == 2) 
+        else if (png_get_valid(pp, info, PNG_INFO_PLTE) && bpp == 2) 
           {
             for (i = 0; i < num; ++i) 
               {
@@ -1051,7 +1055,7 @@ save_image (gchar  *filename,           
         png_write_rows (pp, pixels, num);
         
         gimp_progress_update (((double)pass + (double)end /
-                    (double)info->height) / (double)num_passes);
+                    (double)png_get_image_height(pp, info)) / (double)num_passes);
       };
   };
 
