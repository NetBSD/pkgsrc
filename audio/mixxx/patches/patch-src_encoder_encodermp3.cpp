$NetBSD: patch-src_encoder_encodermp3.cpp,v 1.1 2019/07/08 16:46:32 nia Exp $

We use libmp3lame on more than just Linux.

--- src/encoder/encodermp3.cpp.orig	2019-04-22 07:50:04.000000000 +0000
+++ src/encoder/encodermp3.cpp
@@ -95,15 +95,11 @@ EncoderMp3::EncoderMp3(EncoderCallback* 
      */
     QStringList libnames;
     QString libname = "";
-#ifdef __LINUX__
-    libnames << "mp3lame";
-#elif __WINDOWS__
+#if __WINDOWS__
     libnames << "lame_enc.dll";
     libnames << "libmp3lame.dll";
-#elif __APPLE__
-    libnames << "/usr/local/lib/libmp3lame.dylib";
-    //Using MacPorts (former DarwinPorts) results in ...
-    libnames << "/opt/local/lib/libmp3lame.dylib";
+#else
+    libnames << "mp3lame";
 #endif
 
     for (const auto& libname : libnames) {
