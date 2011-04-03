$NetBSD: patch-lib_ivis__common_png__util.c,v 1.1 2011/04/03 11:27:25 wiz Exp $

Fix build with png-1.5.

--- lib/ivis_common/png_util.c.orig	2009-08-23 04:05:11.000000000 +0000
+++ lib/ivis_common/png_util.c
@@ -153,16 +153,16 @@ BOOL iV_loadImage_PNG(const char *fileNa
 
 	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
 
-	image->width = info_ptr->width;
-	image->height = info_ptr->height;
-	image->depth = info_ptr->channels;
-	image->bmp = malloc(info_ptr->height * info_ptr->rowbytes);
+	image->width = png_get_image_width(png_ptr, info_ptr);
+	image->height = png_get_image_height(png_ptr, info_ptr);
+	image->depth = png_get_channels(png_ptr, info_ptr);
+	image->bmp = malloc(image->height * png_get_rowbytes(png_ptr, info_ptr));
 
 	{
 		unsigned int i = 0;
 		png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);
-		for ( i = 0; i < info_ptr->height; i++ )
-			memcpy( image->bmp + (info_ptr->rowbytes * i), row_pointers[i], info_ptr->rowbytes );
+		for ( i = 0; i < image->height; i++ )
+			memcpy( image->bmp + (png_get_rowbytes(png_ptr, info_ptr) * i), row_pointers[i], png_get_rowbytes(png_ptr, info_ptr) );
 	}
 
 	PNGReadCleanup(&info_ptr, &png_ptr, fileHandle);
