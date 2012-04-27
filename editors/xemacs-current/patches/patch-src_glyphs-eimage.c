$NetBSD: patch-src_glyphs-eimage.c,v 1.2 2012/04/27 14:37:37 hauke Exp $

Fix CVE-2009-2688, via <https://bugzilla.redhat.com/show_bug.cgi?id=511994>

Adapt to new libpng 1.5 interfaces

--- src/glyphs-eimage.c.orig	2005-11-26 11:46:08.000000000 +0000
+++ src/glyphs-eimage.c
@@ -401,6 +401,7 @@ jpeg_instantiate (Lisp_Object image_inst
    */
 
   {
+    UINT_64_BIT pixels_sq;
     int jpeg_gray = 0;		/* if we're dealing with a grayscale */
     /* Step 4: set parameters for decompression.   */
 
@@ -423,7 +424,10 @@ jpeg_instantiate (Lisp_Object image_inst
     jpeg_start_decompress (&cinfo);
 
     /* Step 6: Read in the data and put into EImage format (8bit RGB triples)*/
-
+    pixels_sq =
+      (UINT_64_BIT) cinfo.output_width * (UINT_64_BIT) cinfo.output_height;
+    if (pixels_sq > ((size_t) -1) / 3)
+      signal_image_error ("JPEG image too large to instantiate", instantiator);
     unwind.eimage =
       xnew_binbytes (cinfo.output_width * cinfo.output_height * 3);
     if (!unwind.eimage)
@@ -669,6 +673,7 @@ gif_instantiate (Lisp_Object image_insta
   {
     ColorMapObject *cmo = unwind.giffile->SColorMap;
     int i, j, row, pass, interlace, slice;
+    UINT_64_BIT pixels_sq;
     Binbyte *eip;
     /* interlaced gifs have rows in this order:
        0, 8, 16, ..., 4, 12, 20, ..., 2, 6, 10, ..., 1, 3, 5, ...  */
@@ -677,6 +682,9 @@ gif_instantiate (Lisp_Object image_insta
 
     height = unwind.giffile->SHeight;
     width = unwind.giffile->SWidth;
+    pixels_sq = (UINT_64_BIT) width * (UINT_64_BIT) height;
+    if (pixels_sq > ((size_t) -1) / (3 * unwind.giffile->ImageCount))
+      signal_image_error ("GIF image too large to instantiate", instantiator);
     unwind.eimage =
       xnew_binbytes (width * height * 3 * unwind.giffile->ImageCount);
     if (!unwind.eimage)
@@ -929,11 +937,15 @@ png_instantiate (Lisp_Object image_insta
   {
     int y;
     Binbyte **row_pointers;
-    height = info_ptr->height;
-    width = info_ptr->width;
+    UINT_64_BIT pixels_sq;
+    height = png_get_image_height(png_ptr, info_ptr);
+    width = png_get_image_width(png_ptr, info_ptr);
+    pixels_sq = (UINT_64_BIT) width * (UINT_64_BIT) height;
+    if (pixels_sq > ((size_t) -1) / 3)
+      signal_image_error ("PNG image too large to instantiate", instantiator);
 
     /* Wow, allocate all the memory.  Truly, exciting. */
-    unwind.eimage = xnew_array_and_zero (Binbyte, width * height * 3);
+    unwind.eimage = xnew_array_and_zero (Binbyte, (size_t) (pixels_sq * 3));
     /* libpng expects that the image buffer passed in contains a
        picture to draw on top of if the png has any transparencies.
        This could be a good place to pass that in... */
@@ -982,22 +994,22 @@ png_instantiate (Lisp_Object image_insta
     /* Now that we're using EImage, ask for 8bit RGB triples for any type
        of image*/
     /* convert palette images to full RGB */
-    if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE)
+    if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_PALETTE)
       png_set_expand (png_ptr);
     /* send grayscale images to RGB too */
-    if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY ||
-        info_ptr->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
+    if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY ||
+        png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
       png_set_gray_to_rgb (png_ptr);
     /* we can't handle alpha values */
-    if (info_ptr->color_type & PNG_COLOR_MASK_ALPHA)
+    if (png_get_color_type(png_ptr, info_ptr) & PNG_COLOR_MASK_ALPHA)
       png_set_strip_alpha (png_ptr);
     /* tell libpng to strip 16 bit depth files down to 8 bits */
-    if (info_ptr->bit_depth == 16)
+    if (png_get_bit_depth(png_ptr, info_ptr) == 16)
       png_set_strip_16 (png_ptr);
     /* if the image is < 8 bits, pad it out */
-    if (info_ptr->bit_depth < 8)
+    if (png_get_bit_depth(png_ptr, info_ptr) < 8)
       {
-	if (info_ptr->color_type == PNG_COLOR_TYPE_GRAY)
+	if (png_get_color_type(png_ptr, info_ptr) == PNG_COLOR_TYPE_GRAY)
 	  png_set_expand (png_ptr);
 	else
 	  png_set_packing (png_ptr);
@@ -1018,16 +1030,20 @@ png_instantiate (Lisp_Object image_insta
        unobtrusive. */
     {
       int i;
+      png_textp text_ptr;
+      int num_text;
+
+      png_get_text(png_ptr, info_ptr, &text_ptr, &num_text);
 
-      for (i = 0 ; i < info_ptr->num_text ; i++)
+      for (i = 0 ; i < num_text ; i++)
 	{
 	  /* How paranoid do I have to be about no trailing NULLs, and
-	     using (int)info_ptr->text[i].text_length, and strncpy and a temp
+	     using (int)text_ptr[i].text_length, and strncpy and a temp
 	     string somewhere? */
 
 	  warn_when_safe (Qpng, Qinfo, "%s - %s",
-			  info_ptr->text[i].key,
-			  info_ptr->text[i].text);
+			  text_ptr[i].key,
+			  text_ptr[i].text);
 	}
     }
 #endif
@@ -1268,6 +1284,7 @@ tiff_instantiate (Lisp_Object image_inst
 
     uint32 *raster;
     Binbyte *ep;
+    UINT_64_BIT pixels_sq;
 
     assert (!NILP (data));
 
@@ -1290,12 +1307,15 @@ tiff_instantiate (Lisp_Object image_inst
 
     TIFFGetField (unwind.tiff, TIFFTAG_IMAGEWIDTH, &width);
     TIFFGetField (unwind.tiff, TIFFTAG_IMAGELENGTH, &height);
-    unwind.eimage = xnew_binbytes (width * height * 3);
+    pixels_sq = (UINT_64_BIT) width * (UINT_64_BIT) height;
+    if (pixels_sq >= 1 << 29)
+      signal_image_error ("TIFF image too large to instantiate", instantiator);
+    unwind.eimage = xnew_binbytes (pixels_sq * 3);
 
     /* #### This is little more than proof-of-concept/function testing.
        It needs to be reimplemented via scanline reads for both memory
        compactness. */
-    raster = (uint32*) _TIFFmalloc (width * height * sizeof (uint32));
+    raster = (uint32*) _TIFFmalloc ((tsize_t) (pixels_sq * sizeof (uint32)));
     if (raster != NULL)
       {
 	int i, j;
