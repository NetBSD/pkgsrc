$NetBSD: patch-audio.c,v 1.1 2012/01/11 20:21:54 hans Exp $

No midi support on SunOS.

--- audio.c.orig	2008-04-09 14:10:30.000000000 +0200
+++ audio.c	2012-01-02 16:13:15.136170006 +0100
@@ -2927,8 +2927,10 @@ static void oss_describe_audio_state_1(v
   int fd;
   int status = 0, level, i, recsrc, devmask, recmask, stereodevs, caps;
   int numdevs = 0, rate = 0, channels = 0, blocksize = 0, formats = 0, deffmt = 0, min_rate = 0, max_rate = 0;
+#ifndef __sun
   struct synth_info sinfo;
   struct midi_info minfo;
+#endif
   const char *sound_device_names[] = SOUND_DEVICE_LABELS;
   char dsp_name[LABEL_BUFFER_SIZE];
   char version[LABEL_BUFFER_SIZE];
@@ -2996,6 +2998,7 @@ static void oss_describe_audio_state_1(v
     }
   pprint("\n\n");
 
+#ifndef __sun
   fd = open(SYNTH_NAME, O_RDWR, 0);
   if (fd == -1) fd = open(SYNTH_NAME, O_RDONLY, 0);
   if (fd == -1) 
@@ -3050,6 +3053,7 @@ static void oss_describe_audio_state_1(v
     }
   if (fd != -1) close(fd);
   pprint("--------------------------------\n");
+#endif
 
 MIXER_INFO:
   mus_snprintf(dsp_name, LABEL_BUFFER_SIZE, "%s%d", MIXER_NAME, dsp_num);
