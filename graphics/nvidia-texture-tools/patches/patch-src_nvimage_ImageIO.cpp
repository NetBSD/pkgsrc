$NetBSD: patch-src_nvimage_ImageIO.cpp,v 1.1 2016/09/18 17:08:20 kamil Exp $

Add NetBSD support.
Adapt for new libpng API.
Fix false->NULL conversion warnings.

--- src/nvimage/ImageIO.cpp.orig	2010-05-15 09:12:05.000000000 +0000
+++ src/nvimage/ImageIO.cpp
@@ -135,7 +135,7 @@ FloatImage * nv::ImageIO::loadFloat(cons
 	StdInputStream stream(fileName);
 	
 	if (stream.isError()) {
-		return false;
+		return NULL;
 	}
 	
 	return loadFloat(fileName, stream);
@@ -233,7 +233,7 @@ Image * nv::ImageIO::loadTGA(Stream & s)
 		case TGA_TYPE_INDEXED:
 			if( tga.colormap_type!=1 || tga.colormap_size!=24 || tga.colormap_length>256 ) {
 				nvDebug( "*** ImageIO::loadTGA: Error, only 24bit paletted images are supported.\n" );
-				return false;
+				return NULL;
 			}
 			pal = true;
 			break;
@@ -254,7 +254,7 @@ Image * nv::ImageIO::loadTGA(Stream & s)
 
 		default:
 			nvDebug( "*** ImageIO::loadTGA: Error, unsupported image type.\n" );
-			return false;
+			return NULL;
 	}
 
 	const uint pixel_size = (tga.pixel_size/8);
@@ -603,7 +603,7 @@ static void user_read_data(png_structp p
 {
 	nvDebugCheck(png_ptr != NULL);
 	
-	Stream * s = (Stream *)png_ptr->io_ptr;
+	Stream * s = (Stream *)png_get_io_ptr(png_ptr);
 	s->serialize(data, (int)length);
 	
 	if (s->isError()) {
@@ -621,7 +621,7 @@ Image * nv::ImageIO::loadPNG(Stream & s)
 	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
 	if (png_ptr == NULL) {
 	//	nvDebug( "*** LoadPNG: Error allocating read buffer in file '%s'.\n", name );
-		return false;
+		return NULL;
 	}
 
 	// Allocate/initialize a memory block for the image information
@@ -629,14 +629,14 @@ Image * nv::ImageIO::loadPNG(Stream & s)
 	if (info_ptr == NULL) {
 		png_destroy_read_struct(&png_ptr, NULL, NULL);
 	//	nvDebug( "*** LoadPNG: Error allocating image information for '%s'.\n", name );
-		return false;
+		return NULL;
 	}
 
 	// Set up the error handling
 	if (setjmp(png_jmpbuf(png_ptr))) {
 		png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 	//	nvDebug( "*** LoadPNG: Error reading png file '%s'.\n", name );
-		return false;
+		return NULL;
 	}
 
 	// Set up the I/O functions.
@@ -1506,4 +1506,3 @@ namespace ImageIO {
 } // ImageIO
 
 #endif // 0
-
