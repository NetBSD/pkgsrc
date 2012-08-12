$NetBSD: patch-common_pngloader.c,v 1.2 2012/08/12 21:41:02 wiz Exp $

Fix build with png-1.5.
https://sourceforge.net/tracker/?func=detail&aid=3556781&group_id=92651&atid=601520

--- common/pngloader.c.orig	2004-03-17 03:43:53.000000000 +0000
+++ common/pngloader.c
@@ -90,10 +90,10 @@ uint8_t **parse_pngmap8bit(char* file_na
 
     png_read_info(png_ptr, info_ptr);
 
-    if (width != info_ptr->width || height != info_ptr->height)
+    if (width != png_get_image_width(png_ptr, info_ptr) || height != png_get_image_height(png_ptr, info_ptr))
 	LOG(LOG_FATAL, "width/height of map do not match that of image");
-    color_type = info_ptr->color_type;
-    bit_depth = info_ptr->bit_depth;
+    color_type = png_get_color_type(png_ptr, info_ptr);
+    bit_depth = png_get_bit_depth(png_ptr, info_ptr);
 
     number_of_passes = png_set_interlace_handling(png_ptr);
     png_read_update_info(png_ptr, info_ptr);
@@ -104,11 +104,11 @@ uint8_t **parse_pngmap8bit(char* file_na
 
     row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
     for (y=0; y<height; y++)
-	row_pointers[y] = (png_byte*) malloc(info_ptr->rowbytes);
+	row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr, info_ptr));
 
     png_read_image(png_ptr, row_pointers);
 
-    if (info_ptr->color_type != PNG_COLOR_TYPE_GRAY)
+    if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_GRAY)
 	LOG(LOG_FATAL, "Image %s is not grayscale", file_name);
 
     map = safer_malloc(sizeof(uint8_t *) * height);
@@ -172,10 +172,10 @@ int16_t **parse_pngmap16bit(char* file_n
 
     png_read_info(png_ptr, info_ptr);
 
-    if (width != info_ptr->width || height != info_ptr->height)
+    if (width != png_get_image_width(png_ptr, info_ptr) || height != png_get_image_height(png_ptr, info_ptr))
 	LOG(LOG_FATAL, "width/height of map do not match that of image");
-    color_type = info_ptr->color_type;
-    bit_depth = info_ptr->bit_depth;
+    color_type = png_get_color_type(png_ptr, info_ptr);
+    bit_depth = png_get_bit_depth(png_ptr, info_ptr);
 
     number_of_passes = png_set_interlace_handling(png_ptr);
     png_read_update_info(png_ptr, info_ptr);
@@ -186,11 +186,11 @@ int16_t **parse_pngmap16bit(char* file_n
 
     row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
     for (y=0; y<height; y++)
-	row_pointers[y] = (png_byte*) malloc(info_ptr->rowbytes);
+	row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr, info_ptr));
 
     png_read_image(png_ptr, row_pointers);
 
-    if (info_ptr->color_type != PNG_COLOR_TYPE_RGB)
+    if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_RGB)
 	LOG(LOG_FATAL, "Image %s is not RGB", file_name);
 
     map = safer_malloc(sizeof(int16_t *) * height);
@@ -254,10 +254,10 @@ uint8_t *parse_pngRGBA(char* file_name, 
 
     png_read_info(png_ptr, info_ptr);
 
-    /*if (width != info_ptr->width || height != info_ptr->height)
+    /*if (width != png_get_image_width(png_ptr, info_ptr) || height != png_get_image_height(png_ptr, info_ptr))
       LOG(LOG_FATAL, "width/height of map do not match that of image");*/
-    color_type = info_ptr->color_type;
-    bit_depth = info_ptr->bit_depth;
+    color_type = png_get_color_type(png_ptr, info_ptr);
+    bit_depth = png_get_bit_depth(png_ptr, info_ptr);
 
     number_of_passes = png_set_interlace_handling(png_ptr);
     png_read_update_info(png_ptr, info_ptr);
@@ -266,30 +266,30 @@ uint8_t *parse_pngRGBA(char* file_name, 
     if (setjmp(png_jmpbuf(png_ptr)))
 	bailout();
 
-    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * info_ptr->height);
-    for (y=0; y < info_ptr->height; y++)
-	row_pointers[y] = (png_byte*) malloc(info_ptr->rowbytes);
+    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * png_get_image_height(png_ptr, info_ptr));
+    for (y=0; y < png_get_image_height(png_ptr, info_ptr); y++)
+	row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr, info_ptr));
 
     png_read_image(png_ptr, row_pointers);
 
-    if (info_ptr->color_type != PNG_COLOR_TYPE_RGBA)
+    if (png_get_color_type(png_ptr, info_ptr) != PNG_COLOR_TYPE_RGBA)
 	LOG(LOG_FATAL, "Image %s is not RGBA", file_name);
 
-    row_stride = info_ptr->width * 4;
+    row_stride = png_get_image_width(png_ptr, info_ptr) * 4;
 
-    map = safer_malloc(sizeof(uint8_t) * info_ptr->height *
-		       info_ptr->width * 4);
+    map = safer_malloc(sizeof(uint8_t) * png_get_image_height(png_ptr, info_ptr) *
+		       png_get_image_width(png_ptr, info_ptr) * 4);
 
-/*    indx = row_stride * (info_ptr->height-1); */
+/*    indx = row_stride * (png_get_image_height(png_ptr, info_ptr)-1); */
     indx = 0;
-    for (y=0; y < info_ptr->height; y++) {
+    for (y=0; y < png_get_image_height(png_ptr, info_ptr); y++) {
 	png_byte* row = row_pointers[y];
 	memcpy(map+indx, row, row_stride);
 	indx += row_stride;
     }
 
-    *height = info_ptr->height;
-    *width = info_ptr->width;
+    *height = png_get_image_height(png_ptr, info_ptr);
+    *width = png_get_image_width(png_ptr, info_ptr);
 
     return(map);
 }
