$NetBSD: patch-core_libs_threadimageio_video_videothumbdecoder.cpp,v 1.1 2025/02/25 08:32:38 wiz Exp $

fix FFmpeg 7 deprecated warning for avcodec_close() 
https://invent.kde.org/graphics/digikam/-/commit/b813e82e5d2daaeb9bdf9f2f757060008db94e7c

--- core/libs/threadimageio/video/videothumbdecoder.cpp.orig	2024-11-15 14:51:34.000000000 +0000
+++ core/libs/threadimageio/video/videothumbdecoder.cpp
@@ -91,7 +91,17 @@ void VideoThumbDecoder::destroy()
 
     if (d->pVideoCodecContext)
     {
+
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(61, 3, 100)
+
+        avcodec_free_context(&d->pVideoCodecContext);
+
+#else
+
         avcodec_close(d->pVideoCodecContext);
+
+#endif
+
         d->pVideoCodecContext = nullptr;
     }
 
