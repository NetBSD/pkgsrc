$NetBSD: patch-src_detection_sound_sound__bsd.c,v 1.1 2025/01/25 22:16:09 vins Exp $

* Default sound unit detection on NetBSD, via audiocfg(1). 
* Fix undefined macros on NetBSD.

--- src/detection/sound/sound_bsd.c.orig	2025-01-13 07:57:52.000000000 +0000
+++ src/detection/sound/sound_bsd.c
@@ -5,14 +5,38 @@
 #include <fcntl.h>
 #include <sys/soundcard.h>
 
+/* Obsolete macros */
+#ifndef SOUND_MIXER_MUTE	// unavailable on some platforms
+#define SOUND_MIXER_MUTE	SOUND_MIXER_NONE
+#define SOUND_MIXER_READ_MUTE	MIXER_READ(SOUND_MIXER_MUTE)
+#endif
+
 const char* ffDetectSound(FFlist* devices)
 {
     char path[] = "/dev/mixer0";
+#ifdef __NetBSD__
+    const char* const cmd = "audiocfg list | grep [*] | cut -d: -f1";
+    char buf[32];
+    long defaultDev = 0;
+
+    FILE* f = popen(cmd, "r");
+    if (f == NULL)
+        return "popen() failed";
+
+    while (fgets(buf, sizeof buf, f) != NULL) {
+        defaultDev = strtol(buf, NULL, 10);
+
+    if (pclose(f) != 0)
+        return "pclose() failed";
+
+    }
+#else
     int defaultDev = ffSysctlGetInt("hw.snd.default_unit", -1);
 
     if (defaultDev == -1)
         return "sysctl(hw.snd.default_unit) failed";
 
+#endif
     for (int idev = 0; idev <= 9; ++idev)
     {
         path[strlen("/dev/mixer")] = (char) ('0' + idev);
@@ -26,7 +50,7 @@ const char* ffDetectSound(FFlist* device
             continue;
 
         uint32_t mutemask = 0;
-        ioctl(fd, SOUND_MIXER_READ_MUTE, &mutemask); // doesn't seem to be available on DragonFly
+        ioctl(fd, SOUND_MIXER_READ_MUTE, &mutemask);
 
         struct oss_card_info ci = { .card = idev };
         if (ioctl(fd, SNDCTL_CARDINFO, &ci) < 0)
