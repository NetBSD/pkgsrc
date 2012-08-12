$NetBSD: patch-plug-ins_png_png.c,v 1.2 2012/08/12 22:04:48 wiz Exp $

Fix build with png-1.5.
https://sourceforge.net/tracker/?func=detail&aid=3255946&group_id=75029&atid=542708

--- plug-ins/png/png.c.orig	2006-11-24 20:52:55.000000000 +0000
+++ plug-ins/png/png.c
@@ -405,7 +405,7 @@ load_image (gchar *filename)	/* I - File
   info = (png_infop)calloc(sizeof(png_info), 1);
 #endif /* PNG_LIBPNG_VER > 88 */
 
-  if (setjmp (pp->jmpbuf))
+  if (setjmp (png_jmpbuf(pp)))
   {
     g_message ("%s\nPNG error. File corrupted?", filename);
     return image;
@@ -448,15 +448,15 @@ load_image (gchar *filename)	/* I - File
   */
 
 #ifndef WORDS_BIGENDIAN
-  if(info->bit_depth == 16)
+  if(png_get_bit_depth(pp, info) == 16)
 	  png_set_swap(pp);
 #endif
 
-  if (info->color_type == PNG_COLOR_TYPE_GRAY && info->bit_depth < 8) {
+  if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_GRAY && png_get_bit_depth(pp, info) < 8) {
     png_set_expand(pp);
   }
 
-  if (info->color_type == PNG_COLOR_TYPE_PALETTE && info->bit_depth < 8) {
+  if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE && png_get_bit_depth(pp, info) < 8) {
     png_set_packing(pp);
   }
 
@@ -464,8 +464,8 @@ load_image (gchar *filename)	/* I - File
   * Expand G+tRNS to GA, RGB+tRNS to RGBA
   */
 
-  if (info->color_type != PNG_COLOR_TYPE_PALETTE &&
-                       (info->valid & PNG_INFO_tRNS)) {
+  if (png_get_color_type(pp, info) != PNG_COLOR_TYPE_PALETTE &&
+                       png_get_valid(pp, info, PNG_INFO_tRNS) != 0) {
     png_set_expand(pp);
   }
 
@@ -482,7 +482,7 @@ load_image (gchar *filename)	/* I - File
 
 #if PNG_LIBPNG_VER > 99
   if (png_get_valid(pp, info, PNG_INFO_tRNS) &&
-      info->color_type == PNG_COLOR_TYPE_PALETTE)
+      png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE)
   {
     png_get_tRNS(pp, info, &alpha_ptr, &num, NULL);
     /* Copy the existing alpha values from the tRNS chunk */
@@ -505,9 +505,9 @@ load_image (gchar *filename)	/* I - File
 
   png_read_update_info(pp, info);
   
-  if(info->bit_depth==16)
+  if(png_get_bit_depth(pp, info) == 16)
   {
-	  switch (info->color_type)
+	  switch (png_get_color_type(pp, info))
 	  {
 		  case PNG_COLOR_TYPE_RGB :		/* RGB */
 			  bpp        = 6;
@@ -545,7 +545,7 @@ load_image (gchar *filename)	/* I - File
   }
   else
   {
-	  switch (info->color_type)
+	  switch (png_get_color_type(pp, info))
 	  {
 		  case PNG_COLOR_TYPE_RGB :		/* RGB */
 			  bpp        = 3;
@@ -582,7 +582,7 @@ load_image (gchar *filename)	/* I - File
 	  };
   }
 
-  image = gimp_image_new(info->width, info->height, image_type);
+  image = gimp_image_new(png_get_image_width(pp, info), png_get_image_height(pp, info), image_type);
   if (image == -1)
   {
     g_message("Can't allocate new image\n%s", filename);
@@ -595,7 +595,7 @@ load_image (gchar *filename)	/* I - File
   * Create the "background" layer to hold the image...
   */
 
-  layer = gimp_layer_new(image, _("Background"), info->width, info->height,
+  layer = gimp_layer_new(image, _("Background"), png_get_image_width(pp, info), png_get_image_height(pp, info),
                          layer_type, 100, NORMAL_MODE);
   gimp_image_add_layer(image, layer, 0);
 
@@ -627,20 +627,23 @@ load_image (gchar *filename)	/* I - File
 
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
@@ -659,18 +662,18 @@ load_image (gchar *filename)	/* I - File
   */
 
   tile_height = gimp_tile_height ();
-  pixel       = g_new(guchar, tile_height * info->width * bpp);
+  pixel       = g_new(guchar, tile_height * png_get_image_width(pp, info) * bpp);
   pixels      = g_new(guchar *, tile_height);
 
-  if(info->bit_depth==16)
+  if(png_get_bit_depth(pp, info) == 16)
   {
 	  for (i = 0; i < tile_height; i ++)
-		  pixels[i] = pixel + info->width * info->channels * i * 2;
+		  pixels[i] = pixel + png_get_image_width(pp, info) * png_get_channels(pp, info) * i * 2;
   }
   else
   {
 	  for (i = 0; i < tile_height; i ++)
-		  pixels[i] = pixel + info->width * info->channels * i;
+		  pixels[i] = pixel + png_get_image_width(pp, info) * png_get_channels(pp, info) * i;
   }
 
   for (pass = 0; pass < num_passes; pass ++)
@@ -680,11 +683,11 @@ load_image (gchar *filename)	/* I - File
 	   */
 
 	  for (begin = 0, end = tile_height;
-			  begin < info->height;
+			  begin < png_get_image_height(pp, info);
 			  begin += tile_height, end += tile_height)
 	  {
-		  if (end > info->height)
-			  end = info->height;
+		  if (end > png_get_image_height(pp, info))
+			  end = png_get_image_height(pp, info);
 
 		  num = end - begin;
 
@@ -697,20 +700,28 @@ load_image (gchar *filename)	/* I - File
 		  gimp_pixel_rgn_set_rect(&pixel_rgn, pixel, 0, begin,
 				  drawable->width, num);
 
-		  gimp_progress_update(((double)pass + (double)end / (double)info->height) /
+		  gimp_progress_update(((double)pass + (double)end / (double)png_get_image_height(pp, info)) /
 				  (double)num_passes);
 	  };
   };
 
 #if defined(PNG_iCCP_SUPPORTED)
+  {
+  png_charp iccp_name;
+  int iccp_compression_type;
+  png_bytep iccp_profile;
+  png_uint_32 iccp_proflen;
+  png_get_iCCP(pp, info, &iccp_name, &iccp_compression_type, &iccp_profile, &iccp_proflen);
+
   /* set icc profile */
-  if (info->iccp_proflen > 0) {
-    gimp_image_set_icc_profile_by_mem (image, info->iccp_proflen,
-                                              info->iccp_profile,
+  if (iccp_proflen > 0) {
+    gimp_image_set_icc_profile_by_mem (image, iccp_proflen,
+                                              iccp_profile,
                                               ICC_IMAGE_PROFILE);
     printf ("%s:%d %s() set embedded profile \"%s\"\n",
              __FILE__,__LINE__,__func__,
-                                              info->iccp_name);
+                                              iccp_name);
+  }
   }
 #endif
 
@@ -808,6 +819,8 @@ save_image (gchar  *filename,	        /*
                 blue;           /* Used for palette background */
   time_t	cutime;         /* Time since epoch */
   struct tm	*gmt;		/* GMT broken down */
+  int color_type;               /* type of colors in image */
+  int bit_depth;                /* width of colors in bit */
 
  /*
   * PNG 0.89 and newer have a sane, forwards compatible constructor.
@@ -824,7 +837,7 @@ save_image (gchar  *filename,	        /*
   info = (png_infop)calloc(sizeof(png_info), 1);
 #endif /* PNG_LIBPNG_VER > 88 */
 
-  if (setjmp (pp->jmpbuf))
+  if (setjmp (png_jmpbuf(pp)))
   {
     g_message ("%s\nPNG error. Couldn't save image", filename);
     return 0;
@@ -863,10 +876,6 @@ save_image (gchar  *filename,	        /*
 
   png_set_compression_level (pp, pngvals.compression_level);
 
-  info->width          = drawable->width;
-  info->height         = drawable->height;
-  info->interlace_type = pngvals.interlaced;
-
  /*
   * Set color type and remember bytes per pixel count 
   */
@@ -874,71 +883,67 @@ save_image (gchar  *filename,	        /*
   switch (type)
   {
     case RGB_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_RGB;
-	info->bit_depth      = 8;
+        color_type = PNG_COLOR_TYPE_RGB;
+	bit_depth      = 8;
         bpp              = 3;
         break;
     case RGBA_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_RGB_ALPHA;
-	info->bit_depth      = 8;
+        color_type = PNG_COLOR_TYPE_RGB_ALPHA;
+	bit_depth      = 8;
         bpp              = 4;
         break;
     case GRAY_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_GRAY;
-	info->bit_depth      = 8;
+        color_type = PNG_COLOR_TYPE_GRAY;
+	bit_depth      = 8;
         bpp              = 1;
         break;
     case GRAYA_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_GRAY_ALPHA;
-	info->bit_depth      = 8;
+        color_type = PNG_COLOR_TYPE_GRAY_ALPHA;
+	bit_depth      = 8;
         bpp              = 2;
         break;
     case INDEXED_IMAGE :
 	bpp		 = 1;
-	info->bit_depth      = 8;
-        info->color_type = PNG_COLOR_TYPE_PALETTE;
-	info->valid      |= PNG_INFO_PLTE;
-        info->palette= (png_colorp) gimp_image_get_cmap(image_ID, &num_colors);
-        info->num_palette= num_colors;
+	bit_depth      = 8;
+        color_type = PNG_COLOR_TYPE_PALETTE;
+	png_set_PLTE(pp, info, (png_colorp) gimp_image_get_cmap (image_ID, &num_colors), num_colors);
         break;
     case INDEXEDA_IMAGE :
 	bpp		 = 2;
-	info->bit_depth      = 8;
-	info->color_type = PNG_COLOR_TYPE_PALETTE;
+	bit_depth      = 8;
+	color_type = PNG_COLOR_TYPE_PALETTE;
 	respin_cmap (pp, info, image_ID); /* fix up transparency */
 	break;
     case U16_RGB_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_RGB;
-	info->bit_depth      = 16;
+        color_type = PNG_COLOR_TYPE_RGB;
+	bit_depth      = 16;
         bpp              = 6;
         break;
     case U16_RGBA_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_RGB_ALPHA;
-	info->bit_depth      = 16;
+        color_type = PNG_COLOR_TYPE_RGB_ALPHA;
+	bit_depth      = 16;
         bpp              = 8;
         break;
     case U16_GRAY_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_GRAY;
-	info->bit_depth      = 16;
+        color_type = PNG_COLOR_TYPE_GRAY;
+	bit_depth      = 16;
         bpp              = 2;
         break;
     case U16_GRAYA_IMAGE :
-        info->color_type = PNG_COLOR_TYPE_GRAY_ALPHA;
-	info->bit_depth      = 16;
+        color_type = PNG_COLOR_TYPE_GRAY_ALPHA;
+	bit_depth      = 16;
         bpp              = 4;
         break;
     case U16_INDEXED_IMAGE :
 	bpp		 = 2;
-	info->bit_depth      = 16;
-        info->color_type = PNG_COLOR_TYPE_PALETTE;
-	info->valid      |= PNG_INFO_PLTE;
-        info->palette= (png_colorp) gimp_image_get_cmap(image_ID, &num_colors);
-        info->num_palette= num_colors;
+	bit_depth      = 16;
+        color_type = PNG_COLOR_TYPE_PALETTE;
+	png_set_PLTE(pp, info, (png_colorp) gimp_image_get_cmap (image_ID, &num_colors), num_colors);
         break;
     case U16_INDEXEDA_IMAGE :
 	bpp		 = 4;
-	info->bit_depth      = 16;
-	info->color_type = PNG_COLOR_TYPE_PALETTE;
+	bit_depth      = 16;
+	color_type = PNG_COLOR_TYPE_PALETTE;
 	respin_cmap (pp, info, image_ID); /* fix up transparency */
 	break;
     default:
@@ -950,16 +955,22 @@ save_image (gchar  *filename,	        /*
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
+      bit_depth= 1;
+    else if (num_palette <= 4)
+      bit_depth= 2;
+    else if (num_palette <= 16)
+      bit_depth= 4;
     /* otherwise the default is fine */
   }
 
+  png_set_IHDR(pp, info, drawable->width, drawable->height, bit_depth, color_type, pngvals.interlaced ? PNG_INTERLACE_ADAM7 : PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
+
   // write icc profile
 #if defined(PNG_iCCP_SUPPORTED)
   if (gimp_image_has_icc_profile (image_ID, ICC_IMAGE_PROFILE)) {
@@ -971,9 +982,11 @@ save_image (gchar  *filename,	        /*
     png_set_iCCP (pp, info,
            gimp_image_get_icc_profile_description (image_ID, ICC_IMAGE_PROFILE),
                   0, buffer, size);
+#if 0
     printf ("%s:%d %s() embedd icc profile \"%s\"\n",
              __FILE__,__LINE__,__func__,
                                               info->iccp_name);
+#endif
   }
 #endif
 
@@ -1039,13 +1052,13 @@ save_image (gchar  *filename,	        /*
   * Convert unpacked pixels to packed if necessary
   */
 
-  if (info->color_type == PNG_COLOR_TYPE_PALETTE && info->bit_depth < 8)
+  if (png_get_color_type(pp, info) == PNG_COLOR_TYPE_PALETTE && png_get_bit_depth(pp, info) < 8)
     png_set_packing(pp);
 
   /* Set swapping for 16 bit per sample images */
   
 #ifndef WORDS_BIGENDIAN
-  if (info->bit_depth == 16)
+  if (png_get_bit_depth(pp, info) == 16)
 	  png_set_swap(pp);
 #endif
   
@@ -1077,7 +1090,7 @@ save_image (gchar  *filename,	        /*
 	num = end - begin;
 	
 	gimp_pixel_rgn_get_rect (&pixel_rgn, pixel, 0, begin, drawable->width, num);
-        if (info->valid & PNG_INFO_tRNS) {
+        if (png_get_valid(pp, info, PNG_INFO_tRNS) != 0) {
           for (i = 0; i < num; ++i) {
 	    fixed= pixels[i];
             for (k = 0; k < drawable->width; ++k) {
@@ -1085,7 +1098,7 @@ save_image (gchar  *filename,	        /*
             }
           }
        /* Forgot this case before, what if there are too many colors? */
-        } else if (info->valid & PNG_INFO_PLTE && bpp == 2) {
+        } else if (png_get_valid(pp, info, PNG_INFO_PLTE) && bpp == 2) {
           for (i = 0; i < num; ++i) {
 	    fixed= pixels[i];
             for (k = 0; k < drawable->width; ++k) {
@@ -1097,7 +1110,7 @@ save_image (gchar  *filename,	        /*
 	png_write_rows (pp, pixels, num);
 	
 	gimp_progress_update (((double)pass + (double)end /
-                    (double)info->height) / (double)num_passes);
+                    (double)png_get_image_height(pp, info)) / (double)num_passes);
       };
   };
 
