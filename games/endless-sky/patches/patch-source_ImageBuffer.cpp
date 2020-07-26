$NetBSD: patch-source_ImageBuffer.cpp,v 1.1 2020/07/26 05:21:20 dholland Exp $

Build with both jpeg and libjpeg-turbo.

--- source/ImageBuffer.cpp~	2020-05-01 19:02:38.000000000 +0000
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
