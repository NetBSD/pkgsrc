$NetBSD: patch-src_glyphs-eimage.c,v 1.2 2015/02/04 09:19:20 hauke Exp $

Fix CVE-2009-2688, via <https://bugzilla.redhat.com/show_bug.cgi?id=511994>

--- src/glyphs-eimage.c.orig	2015-01-29 15:04:29.000000000 +0000
+++ src/glyphs-eimage.c
@@ -407,6 +407,7 @@ jpeg_instantiate (Lisp_Object image_inst
    */
 
   {
+    UINT_64_BIT pixels_sq;
     int jpeg_gray = 0;		/* if we're dealing with a grayscale */
     /* Step 4: set parameters for decompression.   */
 
@@ -429,7 +430,10 @@ jpeg_instantiate (Lisp_Object image_inst
     jpeg_start_decompress (&cinfo);
 
     /* Step 6: Read in the data and put into EImage format (8bit RGB triples)*/
-
+    pixels_sq =
+      (UINT_64_BIT) cinfo.output_width * (UINT_64_BIT) cinfo.output_height;
+    if (pixels_sq > ((size_t) -1) / 3)
+      signal_image_error ("JPEG image too large to instantiate", instantiator);
     unwind.eimage = (unsigned char*) xmalloc (cinfo.output_width * cinfo.output_height * 3);
     if (!unwind.eimage)
       signal_image_error("Unable to allocate enough memory for image", instantiator);
@@ -671,6 +675,7 @@ gif_instantiate (Lisp_Object image_insta
   {
     ColorMapObject *cmo = unwind.giffile->SColorMap;
     int i, j, row, pass, interlace, slice;
+    UINT_64_BIT pixels_sq;
     unsigned char *eip;
     /* interlaced gifs have rows in this order:
        0, 8, 16, ..., 4, 12, 20, ..., 2, 6, 10, ..., 1, 3, 5, ...  */
@@ -679,6 +684,9 @@ gif_instantiate (Lisp_Object image_insta
 
     height = unwind.giffile->SHeight;
     width = unwind.giffile->SWidth;
+    pixels_sq = (UINT_64_BIT) width * (UINT_64_BIT) height;
+    if (pixels_sq > ((size_t) -1) / (3 * unwind.giffile->ImageCount))
+      signal_image_error ("GIF image too large to instantiate", instantiator);
     unwind.eimage = (unsigned char*)
       xmalloc (width * height * 3 * unwind.giffile->ImageCount);
     if (!unwind.eimage)
@@ -939,7 +947,14 @@ png_instantiate (Lisp_Object image_insta
     unsigned char **row_pointers;
     height = png_get_image_height(png_ptr, info_ptr);
     width = png_get_image_width(png_ptr, info_ptr);
+    UINT_64_BIT pixels_sq;
 
+    pixels_sq = (UINT_64_BIT) width * (UINT_64_BIT) height;
+    if (pixels_sq > ((size_t) -1) / 3) {
+	    signal_image_error ("PNG image too large to instantiate",
+		instantiator);
+    }
+    
     /* Wow, allocate all the memory.  Truly, exciting.
        Well, yes, there's excitement to be had.  It turns out that libpng
        strips in place, so the last row overruns the buffer if depth is 16
@@ -949,7 +964,7 @@ png_instantiate (Lisp_Object image_insta
 
     padding = 5 * width;
     unwind.eimage = xnew_array_and_zero (unsigned char,
-					 width * height * 3 + padding);
+					 pixels_sq * 3 + padding);
 
     /* libpng expects that the image buffer passed in contains a
        picture to draw on top of if the png has any transparencies.
@@ -1286,6 +1301,7 @@ tiff_instantiate (Lisp_Object image_inst
 
     uint32 *raster;
     unsigned char *ep;
+    UINT_64_BIT pixels_sq;
 
     assert (!NILP (data));
 
@@ -1308,12 +1324,16 @@ tiff_instantiate (Lisp_Object image_inst
 
     TIFFGetField (unwind.tiff, TIFFTAG_IMAGEWIDTH, &width);
     TIFFGetField (unwind.tiff, TIFFTAG_IMAGELENGTH, &height);
-    unwind.eimage = (unsigned char *) xmalloc (width * height * 3);
+    pixels_sq = (UINT_64_BIT) width * (UINT_64_BIT) height;
+    if (pixels_sq >= 1 << 29)
+      signal_image_error ("TIFF image too large to instantiate", instantiator);
+    unwind.eimage = (unsigned char *) xmalloc (pixels_sq * 3);
+
 
     /* #### This is little more than proof-of-concept/function testing.
        It needs to be reimplemented via scanline reads for both memory
        compactness. */
-    raster = (uint32*) _TIFFmalloc (width * height * sizeof (uint32));
+    raster = (uint32*) _TIFFmalloc ((tsize_t) (pixels_sq * sizeof (uint32)));
     if (raster != NULL)
       {
 	int i,j;
