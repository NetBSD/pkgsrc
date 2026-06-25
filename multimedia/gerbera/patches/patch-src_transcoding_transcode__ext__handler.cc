$NetBSD: patch-src_transcoding_transcode__ext__handler.cc,v 1.1 2026/06/25 08:16:53 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/transcoding/transcode_ext_handler.cc.orig	2026-06-25 08:02:29.570134085 +0000
+++ src/transcoding/transcode_ext_handler.cc
@@ -128,7 +128,7 @@ fs::path TranscodeExternalHandler::makeFifo()
 
     err = chmod(fifoPath.c_str(), S_IWUSR | S_IRUSR);
     if (err != 0) {
-        log_error("Failed to change location permissions: {}", std::strerror(errno));
+        log_error("Failed to change location permissions: {}", strerror(errno));
     }
     return fifoPath;
 }
@@ -151,7 +151,7 @@ void TranscodeExternalHandler::checkTranscoder(const s
 
     int err = 0;
     if (!isExecutable(check, &err))
-        throw_std_runtime_error("Transcoder {} is not executable: {}", profile->getCommand().c_str(), std::strerror(err));
+        throw_std_runtime_error("Transcoder {} is not executable: {}", profile->getCommand().c_str(), strerror(err));
 }
 
 #ifdef HAVE_CURL
