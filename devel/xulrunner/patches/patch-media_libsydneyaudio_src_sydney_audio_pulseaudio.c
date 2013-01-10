$NetBSD: patch-media_libsydneyaudio_src_sydney_audio_pulseaudio.c,v 1.4 2013/01/10 15:01:31 ryoon Exp $

--- media/libsydneyaudio/src/sydney_audio_pulseaudio.c.orig	2013-01-04 23:44:40.000000000 +0000
+++ media/libsydneyaudio/src/sydney_audio_pulseaudio.c
@@ -6,7 +6,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <pthread.h>
+_Pragma("GCC visibility push(default)")
 #include <pulse/pulseaudio.h>
+_Pragma("GCC visibility pop")
 #include "sydney_audio.h"
 
 /* Pulseaudio implementation based heavily on sydney_audio_alsa.c */
