$NetBSD: patch-audio.c,v 1.3 2019/12/14 18:34:18 nia Exp $

Use /dev/audio instead of /dev/sound - less surprising preservation of
pause state.

--- audio.c.orig	2019-10-31 19:30:39.000000000 +0000
+++ audio.c
@@ -5056,7 +5056,7 @@ int mus_audio_open_output(int dev, int s
 {
   int line, encode;
 
-  line = open("/dev/sound", O_WRONLY); /* /dev/audio assumes mono 8-bit mulaw */
+  line = open("/dev/audio", O_WRONLY); /* /dev/audio assumes mono 8-bit mulaw */
   if (line == -1)
     {
       if (errno == EBUSY) 
@@ -5123,9 +5123,9 @@ static int netbsd_sample_types(int ur_de
   dev = MUS_AUDIO_DEVICE(ur_dev);
   AUDIO_INITINFO(&info);
 
-  audio_fd = open("/dev/sound", O_RDONLY | O_NONBLOCK, 0);
+  audio_fd = open("/dev/audio", O_RDONLY | O_NONBLOCK, 0);
   if (audio_fd == -1) 
-    return_error_exit(MUS_AUDIO_CANT_READ, -1, mus_format("can't open /dev/sound: %s", strerror(errno)));
+    return_error_exit(MUS_AUDIO_CANT_READ, -1, mus_format("can't open /dev/audio: %s", strerror(errno)));
   err = ioctl(audio_fd, AUDIO_GETINFO, &info); 
   if (err == -1) 
     {
@@ -5161,11 +5161,11 @@ int mus_audio_open_input(int ur_dev, int
 				 mus_sample_type_name(samp_type)));
 
   if (dev != MUS_AUDIO_DUPLEX_DEFAULT)
-    audio_fd = open("/dev/sound", O_RDONLY, 0);
-  else audio_fd = open("/dev/sound", O_RDWR, 0);
+    audio_fd = open("/dev/audio", O_RDONLY, 0);
+  else audio_fd = open("/dev/audio", O_RDWR, 0);
   if (audio_fd == -1) 
     return_error_exit(MUS_AUDIO_CANT_OPEN, -1,
-		      mus_format("can't open /dev/sound: %s",
+		      mus_format("can't open /dev/audio: %s",
 				 strerror(errno)));
 
   AUDIO_INITINFO(&info);
