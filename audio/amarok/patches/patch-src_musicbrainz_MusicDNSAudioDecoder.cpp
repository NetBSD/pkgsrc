$NetBSD: patch-src_musicbrainz_MusicDNSAudioDecoder.cpp,v 1.1 2017/01/19 08:48:13 markd Exp $

Build with ffmpeg3

--- src/musicbrainz/MusicDNSAudioDecoder.cpp.orig	2013-08-14 20:22:52.000000000 +0000
+++ src/musicbrainz/MusicDNSAudioDecoder.cpp
@@ -23,6 +23,9 @@
 #include "core/meta/Meta.h"
 
 extern "C" {
+#if defined(__DragonFly__) || defined(__NetBSD__)
+    #include <machine/int_const.h>
+#endif /* DragonFly | NetBSD */
     typedef quint64 UINT64_C;
     #include <libavcodec/avcodec.h>
     #include <libavformat/avformat.h>
@@ -223,7 +226,7 @@ MusicDNSAudioDecoder::decode( const QStr
             {
                 if( !decodedFrame )
                 {
-                    decodedFrame = avcodec_alloc_frame();
+                    decodedFrame = av_frame_alloc();
                     if( !decodedFrame )
                     {
                         warning() << "Unable to allocate enough memory to decode file.";
@@ -231,7 +234,7 @@ MusicDNSAudioDecoder::decode( const QStr
                         break;
                     }
                     else
-                        avcodec_get_frame_defaults( decodedFrame );
+                        av_frame_unref( decodedFrame );
                 }
 
                 decoderRet = avcodec_decode_audio4( pCodecCtx, decodedFrame, &gotFrame, &avpkt );
@@ -341,7 +344,7 @@ MusicDNSAudioDecoder::decode( const QStr
             {
                 if( !decodedFrame )
                 {
-                    decodedFrame = avcodec_alloc_frame();
+                    decodedFrame = av_frame_alloc();
                     if( !decodedFrame )
                     {
                         warning() << "Unable to allocate enough memory to decode file.";
@@ -349,7 +352,7 @@ MusicDNSAudioDecoder::decode( const QStr
                         break;
                     }
                     else
-                        avcodec_get_frame_defaults( decodedFrame );
+                        av_frame_unref( decodedFrame );
                 }
 
                 decoderRet = avcodec_decode_audio4( pCodecCtx, decodedFrame, &gotFrame, &avpkt );
@@ -459,7 +462,7 @@ MusicDNSAudioDecoder::decode( const QStr
             {
                 if( !decodedFrame )
                 {
-                    decodedFrame = avcodec_alloc_frame();
+                    decodedFrame = av_frame_alloc();
                     if( !decodedFrame )
                     {
                         warning() << "Unable to allocate enough memory to decode file.";
@@ -467,7 +470,7 @@ MusicDNSAudioDecoder::decode( const QStr
                         break;
                     }
                     else
-                        avcodec_get_frame_defaults( decodedFrame );
+                        av_frame_unref( decodedFrame );
                 }
 
                 decoderRet = avcodec_decode_audio4( pCodecCtx, decodedFrame, &gotFrame, &avpkt );
