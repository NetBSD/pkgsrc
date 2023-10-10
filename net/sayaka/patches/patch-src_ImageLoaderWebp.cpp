$NetBSD: patch-src_ImageLoaderWebp.cpp,v 1.1 2023/10/10 14:20:53 tsutsui Exp $

- fix a problem that webp images with alpha channel are not shown properly.

--- src/ImageLoaderWebp.cpp.orig	2023-10-09 11:22:42.000000000 +0000
+++ src/ImageLoaderWebp.cpp
@@ -239,12 +239,10 @@ ImageLoaderWebp::Load(Image& img)
 		// RGBA 出力バッファを用意。
 		int stride = width * 4;
 		int outbufsize = stride * height;
-		std::vector<uint8> outbuf(outbufsize);
 
 		// RGBA で出力。
 		config.output.colorspace = MODE_RGBA;
-		config.output.u.RGBA.rgba = outbuf.data();
-		config.output.u.RGBA.size = outbuf.size();
+		config.output.u.RGBA.size = outbufsize;
 		config.output.u.RGBA.stride = stride;
 		int status = WebPDecode(filebuf.data(), filebuf.size(), &config);
 		if (status != VP8_STATUS_OK) {
@@ -253,7 +251,7 @@ ImageLoaderWebp::Load(Image& img)
 		}
 
 		// RGB に変換。
-		RGBAtoRGB(img.GetBuf(), outbuf.data(), width, height, stride, TRANSBG);
+		RGBAtoRGB(img.GetBuf(), config.output.u.RGBA.rgba, width, height, stride, TRANSBG);
 		rv = true;
  abort_alpha:
 		WebPFreeDecBuffer(&config.output);
