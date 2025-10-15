$NetBSD: patch-src_framework_audio_thirdparty_fluidsynth_fluidsynth-2.3.3_src_external_portable__endian.h,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD.

--- src/framework/audio/thirdparty/fluidsynth/fluidsynth-2.3.3/src/external/portable_endian.h.orig	2025-07-21 10:19:15.262011313 +0000
+++ src/framework/audio/thirdparty/fluidsynth/fluidsynth-2.3.3/src/external/portable_endian.h
@@ -55,7 +55,7 @@
 #elif defined(__NetBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
 
 #	include <sys/endian.h>
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #	define be16toh(x) betoh16(x)
 #	define le16toh(x) letoh16(x)
 
