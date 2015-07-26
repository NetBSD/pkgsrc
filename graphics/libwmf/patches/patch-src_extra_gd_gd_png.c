$NetBSD: patch-src_extra_gd_gd_png.c,v 1.1.2.2 2015/07/26 19:49:47 tron Exp $

CVE-2004-0941 - Multiple buffer overflows in the gd graphics library
CVE-2007-2756 - Denial of service (CPU consumption) via a crafted PNG image with
truncated data

--- src/extra/gd/gd_png.c.orig	2015-07-16 23:29:21.000000000 +0000
+++ src/extra/gd/gd_png.c
@@ -78,8 +78,11 @@ static void
 gdPngReadData (png_structp png_ptr,
 	       png_bytep data, png_size_t length)
 {
-  gdGetBuf (data, length, (gdIOCtx *)
-	    png_get_io_ptr (png_ptr));
+  int check;
+  check = gdGetBuf (data, length, (gdIOCtx *) png_get_io_ptr (png_ptr));
+  if (check != length) {
+    png_error(png_ptr, "Read Error: truncated data");
+  }
 }
 
 static void
@@ -181,6 +184,14 @@ gdImageCreateFromPngCtx (gdIOCtx * infil
 
   png_get_IHDR (png_ptr, info_ptr, &width, &height, &bit_depth, &color_type,
 		&interlace_type, NULL, NULL);
+  if (overflow2(sizeof (int), width)) 
+    {
+      return NULL;
+    }
+  if (overflow2(sizeof (int) * width, height)) 
+    {
+      return NULL;
+    }  
   if ((color_type == PNG_COLOR_TYPE_RGB) ||
       (color_type == PNG_COLOR_TYPE_RGB_ALPHA))
     {
