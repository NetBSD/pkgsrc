$NetBSD: patch-ffmpegthumbs_ffmpegthumbnailer_moviedecoder.cpp,v 1.1 2012/11/11 18:29:15 markd Exp $

Fix build with ffmpeg>=0.11.

--- ffmpegthumbs/ffmpegthumbnailer/moviedecoder.cpp.orig	2012-06-06 09:35:29.000000000 +0000
+++ ffmpegthumbs/ffmpegthumbnailer/moviedecoder.cpp
@@ -52,12 +52,11 @@ MovieDecoder::~MovieDecoder()
 void MovieDecoder::initialize(const QString& filename)
 {
     av_register_all();
-    avcodec_init();
     avcodec_register_all();
 
     QFileInfo fileInfo(filename);
 
-    if ((!m_FormatContextWasGiven) && av_open_input_file(&m_pFormatContext, fileInfo.absoluteFilePath().toUtf8().data(), NULL, 0, NULL) != 0) {
+    if ((!m_FormatContextWasGiven) && avformat_open_input(&m_pFormatContext, fileInfo.absoluteFilePath().toLocal8Bit().data(), NULL, NULL) != 0) {
         kDebug() <<  "Could not open input file: " << fileInfo.absoluteFilePath();
         return;
     }
