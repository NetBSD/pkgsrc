$NetBSD: patch-mixer.c,v 1.1 2013/10/14 13:33:31 roy Exp $

--- mixer.c.orig	2000-01-28 16:29:40.000000000 +0000
+++ mixer.c
@@ -57,9 +57,9 @@ void open_sound_device(void)
     int format;
     int stereo = 1;
     int rate = 44100;
-    if ((audio_fd = open("/dev/dsp", O_WRONLY , 0)) == -1)
+    if ((audio_fd = open("/dev/sound", O_WRONLY , 0)) == -1)
     {
-        perror("/dev/dsp");
+        perror("/dev/sound");
         return;
         /*exit(1);  */
     }
