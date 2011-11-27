$NetBSD: patch-src_audio_wav_WavFile.cpp,v 1.1 2011/11/27 19:33:55 joerg Exp $

--- src/audio/wav/WavFile.cpp.orig	2011-11-27 01:17:47.000000000 +0000
+++ src/audio/wav/WavFile.cpp
@@ -65,13 +65,6 @@
 #   include <new>
 #endif
 
-#if defined(WAV_HAVE_IOS_OPENMODE)
-    typedef std::ios::openmode openmode;
-#else
-    typedef int openmode;
-#endif
-
-
 const wavHeader WavFile::defaultWavHdr = {
     // ASCII keywords are hex-ified.
     {0x52,0x49,0x46,0x46}, {0,0,0,0}, {0x57,0x41,0x56,0x45},
@@ -132,7 +125,7 @@ void* WavFile::open(AudioConfig &cfg, co
     endian_little16(wavHdr.bitsPerSample,bits);
     endian_little32(wavHdr.dataChunkLen,0);
 
-    openmode createAttr = std::ios::out;
+    std::ios::openmode createAttr = std::ios::out;
 #if defined(WAV_HAVE_IOS_BIN)
     createAttr |= std::ios::bin;
 #else
