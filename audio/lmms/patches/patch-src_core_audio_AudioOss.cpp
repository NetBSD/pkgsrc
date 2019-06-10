$NetBSD: patch-src_core_audio_AudioOss.cpp,v 1.2 2019/06/10 19:08:42 nia Exp $

Support NetBSD's OSS emulation.

--- src/core/audio/AudioOss.cpp.orig	2019-06-09 11:28:34.000000000 +0000
+++ src/core/audio/AudioOss.cpp
@@ -59,7 +59,7 @@
 
 
 #ifndef _PATH_DEV_DSP
-#ifdef __OpenBSD__
+#if (defined __OpenBSD__) || (defined __NetBSD__)
 #define _PATH_DEV_DSP  "/dev/audio"
 #else
 #define _PATH_DEV_DSP  "/dev/dsp"
