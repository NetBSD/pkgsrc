$NetBSD: patch-graf2d_asimage_src_libAfterImage_export.c,v 1.1 2011/12/23 01:17:54 joerg Exp $

--- graf2d/asimage/src/libAfterImage/export.c.orig	2011-12-22 22:02:37.000000000 +0000
+++ graf2d/asimage/src/libAfterImage/export.c
@@ -491,7 +491,7 @@ ASImage2png_int ( ASImage *im, void *dat
 	png_ptr = png_create_write_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
     if ( png_ptr != NULL )
     	if( (info_ptr = png_create_info_struct(png_ptr)) != NULL )
-			if( setjmp(png_ptr->jmpbuf) )
+			if( setjmp(png_jmpbuf(png_ptr)) )
 			{
 				png_destroy_info_struct(png_ptr, (png_infopp) &info_ptr);
 				info_ptr = NULL ;
