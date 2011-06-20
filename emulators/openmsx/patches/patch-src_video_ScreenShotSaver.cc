$NetBSD: patch-src_video_ScreenShotSaver.cc,v 1.1 2011/06/20 09:28:06 wiz Exp $

Fix build with png-1.5.

--- src/video/ScreenShotSaver.cc.orig	2007-04-14 21:25:30.000000000 +0000
+++ src/video/ScreenShotSaver.cc
@@ -31,7 +31,7 @@ static bool IMG_SavePNG_RW(int width, in
 		// Couldn't allocate memory for PNG file
 		goto error;
 	}
-	png_ptr->io_ptr = fp;
+	png_init_io(png_ptr, fp);
 
 	// Allocate/initialize the image information data.  REQUIRED
 	info_ptr = png_create_info_struct(png_ptr);
@@ -41,7 +41,7 @@ static bool IMG_SavePNG_RW(int width, in
 	}
 
 	// Set error handling.
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		// Error writing the PNG file
 		goto error;
 	}
@@ -78,18 +78,12 @@ static bool IMG_SavePNG_RW(int width, in
 	png_write_image(png_ptr, row_pointers);
 	png_write_end(png_ptr, info_ptr);
 
-	if (info_ptr->palette) {
-		free(info_ptr->palette);
-	}
 	png_destroy_write_struct(&png_ptr, &info_ptr);
 
 	fclose(fp);
 	return true;
 
 error:
-	if (info_ptr->palette) {
-		free(info_ptr->palette);
-	}
 	png_destroy_write_struct(&png_ptr, &info_ptr);
 
 	fclose(fp);
