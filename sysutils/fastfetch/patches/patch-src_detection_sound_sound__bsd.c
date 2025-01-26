$NetBSD: patch-src_detection_sound_sound__bsd.c,v 1.3 2025/01/26 09:14:05 vins Exp $

* Default sound unit detection on NetBSD, via audiocfg(1). 
* Fix undefined macros on NetBSD.

--- src/detection/sound/sound_bsd.c.orig	2025-01-13 07:57:52.000000000 +0000
+++ src/detection/sound/sound_bsd.c
@@ -5,13 +5,39 @@
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
+
+#if defined(__FreeBSD) || defined(__DragonFly__)
     int defaultDev = ffSysctlGetInt("hw.snd.default_unit", -1);
 
     if (defaultDev == -1)
         return "sysctl(hw.snd.default_unit) failed";
+#elif defined(__NetBSD__)
+    const char* const cmd = "audiocfg list | grep [*] | cut -d: -f1";
+    char buf[32];
+    long defaultDev = -1;
+
+    FILE* f = popen(cmd, "r");
+    if (f == NULL)
+        return "popen() failed";
+
+    while (fgets(buf, sizeof buf, f) != NULL) {
+	defaultDev = strtol(buf, NULL, 10);
+        if (defaultDev == -1)
+	    return "audiocfg: failed to get default sound unit";
+
+    if (pclose(f) != 0)
+        return "pclose() failed";
+#endif
+    }
 
     for (int idev = 0; idev <= 9; ++idev)
     {
@@ -26,7 +52,7 @@ const char* ffDetectSound(FFlist* device
             continue;
 
         uint32_t mutemask = 0;
-        ioctl(fd, SOUND_MIXER_READ_MUTE, &mutemask); // doesn't seem to be available on DragonFly
+        ioctl(fd, SOUND_MIXER_READ_MUTE, &mutemask);
 
         struct oss_card_info ci = { .card = idev };
         if (ioctl(fd, SNDCTL_CARDINFO, &ci) < 0)
