$NetBSD: patch-src_core_audio_AudioOss.cpp,v 1.1 2013/06/17 15:16:47 ryoon Exp $

* Define dsp path for NetBSD.

--- src/core/audio/AudioOss.cpp.orig	2013-06-11 20:57:16.000000000 +0000
+++ src/core/audio/AudioOss.cpp
@@ -62,7 +62,7 @@
 
 
 #ifndef _PATH_DEV_DSP
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #define _PATH_DEV_DSP  "/dev/audio"
 #else
 #define _PATH_DEV_DSP  "/dev/dsp"
