$NetBSD: patch-Core_HW_SimpleAudioDec.cpp,v 1.1 2025/04/13 16:19:29 nia Exp $

Fix build.

--- Core/HW/SimpleAudioDec.cpp.orig	2025-04-13 11:08:45.470735632 +0000
+++ Core/HW/SimpleAudioDec.cpp
@@ -351,7 +351,7 @@ bool FFmpegAudioDecoder::Decode(const ui
 	return true;
 #else
 	// Zero bytes output. No need to memset.
-	*outbytes = 0;
+	//*outbytes = 0;
 	return true;
 #endif  // USE_FFMPEG
 }
