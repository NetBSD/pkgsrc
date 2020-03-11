$NetBSD: patch-src_print__volume.c,v 1.2 2020/03/11 23:28:21 nia Exp $

Use sunaudio on NetBSD.

https://github.com/i3/i3status/pull/391

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
@@ -248,7 +248,7 @@ void print_volume(yajl_gen json_gen, cha
     snd_mixer_selem_id_free(sid);
 
 #endif
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
     char *mixerpath;
     char defaultmixer[] = "/dev/mixer";
     int mixfd, vol, devmask = 0;
@@ -272,7 +272,7 @@ void print_volume(yajl_gen json_gen, cha
     if (mixer_idx > 0)
         free(mixerpath);
 
-#if defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
     int oclass_idx = -1, master_idx = -1, master_mute_idx = -1;
     int master_next = AUDIO_MIXER_LAST;
     mixer_devinfo_t devinfo, devinfo2;
@@ -327,15 +327,17 @@ void print_volume(yajl_gen json_gen, cha
         vol = (int)vinfo.un.value.level[AUDIO_MIXER_LEVEL_MONO];
     }
 
-    vinfo.dev = master_mute_idx;
-    vinfo.type = AUDIO_MIXER_ENUM;
-    if (ioctl(mixfd, AUDIO_MIXER_READ, &vinfo) == -1)
-        goto out;
+    if (master_mute_idx != -1) {
+        vinfo.dev = master_mute_idx;
+        vinfo.type = AUDIO_MIXER_ENUM;
+        if (ioctl(mixfd, AUDIO_MIXER_READ, &vinfo) == -1)
+            goto out;
 
-    if (master_mute_idx != -1 && vinfo.un.ord) {
-        START_COLOR("color_degraded");
-        fmt = fmt_muted;
-        pbval = 0;
+        if (vinfo.un.ord) {
+            START_COLOR("color_degraded");
+            fmt = fmt_muted;
+            pbval = 0;
+        }
     }
 
 #else
