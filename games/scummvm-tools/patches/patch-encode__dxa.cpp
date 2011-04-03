$NetBSD: patch-encode__dxa.cpp,v 1.1 2011/04/03 11:20:47 wiz Exp $

Fix build with png-1.5.

--- encode_dxa.cpp.orig	2006-06-21 21:11:51.000000000 +0000
+++ encode_dxa.cpp
@@ -217,10 +217,10 @@ int read_png_file(char* filename, unsign
 
 	png_read_info(png_ptr, info_ptr);
 
-	width = info_ptr->width;
-	height = info_ptr->height;
-	color_type = info_ptr->color_type;
-	bit_depth = info_ptr->bit_depth;
+	width = png_get_image_width(png_ptr, info_ptr);
+	height = png_get_image_height(png_ptr, info_ptr);
+	color_type = png_get_color_type(png_ptr, info_ptr);
+	bit_depth = png_get_bit_depth(png_ptr, info_ptr);
 
 	if (color_type != PNG_COLOR_TYPE_PALETTE) {
 		palette = NULL;
@@ -236,13 +236,13 @@ int read_png_file(char* filename, unsign
 
 	row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
 	for (int y=0; y<height; y++)
-		row_pointers[y] = (png_byte*) malloc(info_ptr->rowbytes);
+		row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr, info_ptr));
 
 	png_read_image(png_ptr, row_pointers);
 
 	image = new unsigned char[width * height];
 	for (int y=0; y<height; y++)
-		memcpy(&image[y*width], row_pointers[y], info_ptr->rowbytes);
+		memcpy(&image[y*width], row_pointers[y], png_get_rowbytes(png_ptr, info_ptr));
 
 	for (int y=0; y<height; y++)
 		free(row_pointers[y]);
