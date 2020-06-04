$NetBSD: patch-src_java.desktop_bsd_native_libjsound_PLATFORM__API__BsdOS__ALSA__PCM.c,v 1.1 2020/06/04 01:10:38 ryoon Exp $

* Enable ALSA audio support under NetBSD.

--- src/java.desktop/bsd/native/libjsound/PLATFORM_API_BsdOS_ALSA_PCM.c.orig	2020-04-15 22:35:23.000000000 +0000
+++ src/java.desktop/bsd/native/libjsound/PLATFORM_API_BsdOS_ALSA_PCM.c
@@ -32,6 +32,10 @@
 
 #if USE_DAUDIO == TRUE
 
+#ifndef ESTRPIPE
+#    define ESTRPIPE EPIPE
+#endif
+
 // GetPosition method 1: based on how many bytes are passed to the kernel driver
 //                       + does not need much processor resources
 //                       - not very exact, "jumps"
