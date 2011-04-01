$NetBSD: patch-src_glyphs-eimage.c,v 1.1 2011/04/01 13:00:32 wiz Exp $

Fix build with png-1.5.

--- src/glyphs-eimage.c.orig	2005-11-26 11:46:08.000000000 +0000
+++ src/glyphs-eimage.c
@@ -929,8 +929,8 @@ png_instantiate (Lisp_Object image_insta
   {
     int y;
     Binbyte **row_pointers;
-    height = info_ptr->height;
-    width = info_ptr->width;
+    height = png_get_image_height(png_ptr, info_ptr);
+    width = png_get_image_width(png_ptr, info_ptr);
 
     /* Wow, allocate all the memory.  Truly, exciting. */
     unwind.eimage = xnew_array_and_zero (Binbyte, width * height * 3);
@@ -982,22 +982,22 @@ png_instantiate (Lisp_Object image_insta
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
@@ -1018,16 +1018,20 @@ png_instantiate (Lisp_Object image_insta
        unobtrusive. */
     {
       int i;
+      png_textp text_ptr;
+      int num_text;
 
-      for (i = 0 ; i < info_ptr->num_text ; i++)
+      png_get_text(png_ptr, info_ptr, &text_ptr, &num_text);
+
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
