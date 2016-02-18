$NetBSD: patch-include_sound_asound.h,v 1.2 2016/02/18 15:15:57 wiz Exp $

--- include/sound/asound.h.orig	2015-11-09 07:39:18.000000000 +0000
+++ include/sound/asound.h
@@ -23,8 +23,14 @@
 #ifndef _UAPI__SOUND_ASOUND_H
 #define _UAPI__SOUND_ASOUND_H
 
+#if defined(__linux__)
 #include <linux/types.h>
-
+#else
+#include <sys/ioctl.h>
+#define __bitwise
+typedef uint32_t __u32;
+typedef int __kernel_pid_t;
+#endif
 #ifndef __KERNEL__
 #include <stdlib.h>
 #endif
@@ -415,7 +421,11 @@ struct snd_pcm_sw_params {
 
 struct snd_pcm_channel_info {
 	unsigned int channel;
+#ifdef __linux__
 	__kernel_off_t offset;		/* mmap offset */
+#else
+	off_t offset;		/* mmap offset */
+#endif
 	unsigned int first;		/* offset to first sample in bits */
 	unsigned int step;		/* samples distance in bits */
 };
