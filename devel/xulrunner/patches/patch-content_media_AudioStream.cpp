$NetBSD: patch-content_media_AudioStream.cpp,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- content/media/AudioStream.cpp.orig	2013-05-11 19:19:24.000000000 +0000
+++ content/media/AudioStream.cpp
@@ -314,7 +314,7 @@ nsresult NativeAudioStream::Init(int32_t
   mChannels = aNumChannels;
 
   if (sa_stream_create_pcm(reinterpret_cast<sa_stream_t**>(&mAudioHandle),
-                           NULL,
+                           "Mozilla",
                            SA_MODE_WRONLY,
                            SA_PCM_FORMAT_S16_NE,
                            aRate,
