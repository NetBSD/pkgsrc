$NetBSD: patch-plugins_decoder_ffmpeg_k3bffmpegwrapper.cpp,v 1.2 2012/11/11 18:32:24 markd Exp $

commit 61ca30beb978f68e72257408777c6433f33129bd
Author: Michal Malek <michalm@jabster.pl>
Date:   Sun Aug 28 20:18:53 2011 +0200

    Fixed compilation with new FFMPEG
    
    BUG: 274817
    FIXED-IN: 2.0.3

diff --git a/plugins/decoder/ffmpeg/k3bffmpegwrapper.cpp b/plugins/decoder/ffmpeg/k3bffmpegwrapper.cpp
index 0ad59fc..0c5f366 100644
--- plugins/decoder/ffmpeg/k3bffmpegwrapper.cpp
+++ plugins/decoder/ffmpeg/k3bffmpegwrapper.cpp
@@ -88,7 +88,7 @@
     close();
 
     // open the file
-    int err = ::av_open_input_file( &d->formatContext, m_filename.toLocal8Bit(), 0, 0, 0 );
+    int err = ::avformat_open_input( &d->formatContext, m_filename.toLocal8Bit(), 0, NULL);
     if( err < 0 ) {
         kDebug() << "(K3bFFMpegFile) unable to open " << m_filename << " with error " << err;
         return false;
@@ -109,7 +109,13 @@ bool K3bFFMpegFile::open()
 #else
     ::AVCodecContext* codecContext =  d->formatContext->streams[0]->codec;
 #endif
-    if( codecContext->codec_type != CODEC_TYPE_AUDIO ) {
+    if( codecContext->codec_type != 
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(52, 64, 0)
+        AVMEDIA_TYPE_AUDIO)
+#else
+        CODEC_TYPE_AUDIO)
+#endif
+    {
         kDebug() << "(K3bFFMpegFile) not a simple audio stream: " << m_filename;
         return false;
     }
@@ -137,7 +143,7 @@
     }
 
     // dump some debugging info
-    ::dump_format( d->formatContext, 0, m_filename.toLocal8Bit(), 0 );
+    ::av_dump_format( d->formatContext, 0, m_filename.toLocal8Bit(), 0 );
 
     return true;
 }
@@ -225,8 +231,11 @@ QString K3bFFMpegFile::typeComment() const
 QString K3bFFMpegFile::title() const
 {
     // FIXME: is this UTF8 or something??
-    if( d->formatContext->title[0] != '\0' )
-        return QString::fromLocal8Bit( d->formatContext->title );
+    AVDictionaryEntry *ade = av_dict_get( d->formatContext->metadata, "TITLE", NULL, 0 );
+    if( ade == NULL )
+        return QString();
+    if( ade->value != '\0' )
+        return QString::fromLocal8Bit( ade->value );
     else
         return QString();
 }
@@ -235,8 +244,11 @@ QString K3bFFMpegFile::title() const
 QString K3bFFMpegFile::author() const
 {
     // FIXME: is this UTF8 or something??
-    if( d->formatContext->author[0] != '\0' )
-        return QString::fromLocal8Bit( d->formatContext->author );
+    AVDictionaryEntry *ade = av_dict_get( d->formatContext->metadata, "ARTIST", NULL, 0 );
+    if( ade == NULL )
+        return QString();
+    if( ade->value != '\0' )
+        return QString::fromLocal8Bit( ade->value );
     else
         return QString();
 }
@@ -245,8 +257,11 @@ QString K3bFFMpegFile::author() const
 QString K3bFFMpegFile::comment() const
 {
     // FIXME: is this UTF8 or something??
-    if( d->formatContext->comment[0] != '\0' )
-        return QString::fromLocal8Bit( d->formatContext->comment );
+    AVDictionaryEntry *ade = av_dict_get( d->formatContext->metadata, "COMMENT", NULL, 0 );
+    if( ade == NULL )
+        return QString();
+    if( ade->value != '\0' )
+        return QString::fromLocal8Bit( ade->value );
     else
         return QString();
 }
@@ -309,8 +324,13 @@ int K3bFFMpegFile::fillOutputBuffer()
 #if LIBAVCODEC_VERSION_MAJOR < 52
         int len = ::avcodec_decode_audio(
 #else
+   #if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(52, 64, 0)
+        int len = ::avcodec_decode_audio3(
+   #else
         int len = ::avcodec_decode_audio2(
+   #endif
 #endif
+
 #ifdef FFMPEG_BUILD_PRE_4629
             &d->formatContext->streams[0]->codec,
 #else
@@ -318,7 +338,11 @@ int K3bFFMpegFile::fillOutputBuffer()
 #endif
             (short*)d->alignedOutputBuffer,
             &d->outputBufferSize,
+#if LIBAVCODEC_VERSION_INT >= AV_VERSION_INT(52, 64, 0)
+            &d->packet );
+#else
             d->packetData, d->packetSize );
+#endif
 
         if( d->packetSize <= 0 || len < 0 )
             ::av_free_packet( &d->packet );
