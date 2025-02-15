$NetBSD: patch-src_include_OpenImageIO_imagebuf.h,v 1.1 2025/02/15 15:47:55 wiz Exp $

In file included from /pbulk/work/multimedia/olive-editor/work/olive-55eedbfce909dfd7df97611a2eea1d1958385f9c/app/codec/ffmpeg/ffmpegdecoder.cpp:33:
/pbulk/work/multimedia/olive-editor/work/.buildlink/include/OpenImageIO/imagebuf.h: At global scope:
/pbulk/work/multimedia/olive-editor/work/.buildlink/include/OpenImageIO/imagebuf.h:31:2: error: extra ';' [-Wpedantic]
   31 | };  // namespace pvt
      |  ^

--- src/include/OpenImageIO/imagebuf.h.orig	2025-02-15 15:44:08.412258891 +0000
+++ src/include/OpenImageIO/imagebuf.h
@@ -28,7 +28,7 @@ class ImageCache;
 
 namespace pvt {
 class ImageCacheTile;
-};  // namespace pvt
+}  // namespace pvt
 
 
 
