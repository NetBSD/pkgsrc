$NetBSD: patch-media_libsydneyaudio_src_sydney_audio_pulseaudio.c,v 1.3 2012/08/28 23:27:10 ryoon Exp $

--- media/libsydneyaudio/src/sydney_audio_pulseaudio.c.orig	2012-08-24 22:55:55.000000000 +0000
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
