$NetBSD: patch-source_ImageBuffer.cpp,v 1.2 2021/07/21 12:29:44 yhardy Exp $

Build with both jpeg and libjpeg-turbo.

--- source/ImageBuffer.cpp.orig	2020-05-01 19:02:38.000000000 +0000
+++ source/ImageBuffer.cpp
@@ -271,7 +271,11 @@ namespace {
 		
 		jpeg_stdio_src(&cinfo, file);
 		jpeg_read_header(&cinfo, true);
+#ifdef JCS_EXTENSIONS
 		cinfo.out_color_space = JCS_EXT_BGRA;
+#else
+		cinfo.out_color_space = JCS_RGB;
+#endif
 		
 		jpeg_start_decompress(&cinfo);
 		int width = cinfo.image_width;
@@ -297,6 +301,20 @@ namespace {
 		jpeg_finish_decompress(&cinfo);
 		jpeg_destroy_decompress(&cinfo);
 		
+#ifndef JCS_EXTENSIONS
+		height = buffer.Height();
+		for(int y = 0; y < height; ++y)
+		{
+			for(int x = width-1; x >= 0; --x)
+			{
+				rows[y][4*x+3] = 255;
+				rows[y][4*x+2] = rows[y][3*x];
+				rows[y][4*x+1] = rows[y][3*x+1];
+				rows[y][4*x]   = rows[y][3*x+2];
+			}
+		}
+#endif
+
 		return true;
 	}
 	
