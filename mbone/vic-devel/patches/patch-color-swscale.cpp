$NetBSD: patch-color-swscale.cpp,v 1.1 2009/07/01 13:51:47 sborrill Exp $

Work with newer ffmpeg (should work with all version of avutil back to 2006)

--- render/color-swscale.cpp.orig	2009-07-01 14:44:00.000000000 +0100
+++ render/color-swscale.cpp	2009-07-01 14:44:07.000000000 +0100
@@ -129,7 +129,7 @@
   	uint8_t *sws_tar[3];
   	int sws_src_stride[3];
   	int sws_tar_stride[3];	
-  	int out_format;
+	enum PixelFormat out_format;
   	int bytes_per_pixel;
 };
 
