$NetBSD: patch-src_print__volume.c,v 1.1 2020/03/11 22:46:36 nia Exp $

Use sunaudio on NetBSD.

--- src/print_volume.c.orig	2019-01-23 08:03:56.000000000 +0000
+++ src/print_volume.c
@@ -21,7 +21,7 @@
 #include <sys/soundcard.h>
 #endif
 
-#ifdef __OpenBSD__
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/audioio.h>
@@ -86,7 +86,7 @@ void print_volume(yajl_gen json_gen, cha
         free(instance);
     }
 
-#if !defined(__DragonFly__) && !defined(__OpenBSD__)
+#if defined(__linux__)
     /* Try PulseAudio first */
 
     /* If the device name has the format "pulse[:N]" where N is the
@@ -272,7 +272,7 @@ void print_volume(yajl_gen json_gen, cha
     if (mixer_idx > 0)
         free(mixerpath);
 
-#if defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
     int oclass_idx = -1, master_idx = -1, master_mute_idx = -1;
     int master_next = AUDIO_MIXER_LAST;
     mixer_devinfo_t devinfo, devinfo2;
