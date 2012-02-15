$NetBSD: patch-src_s__audio__oss.c,v 1.3 2012/02/15 22:36:39 hans Exp $

Use proper soundcard.h include on NetBSD and add missing argument
to ioctl().
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

--- src/s_audio_oss.c.orig	2011-03-07 01:33:39.000000000 +0000
+++ src/s_audio_oss.c
@@ -5,12 +5,17 @@
 
 /* this file inputs and outputs audio using the OSS API available on linux. */
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__sun)
 # include <sys/soundcard.h>
 #else
 # include <linux/soundcard.h>
 #endif
 
+#ifdef __sun
+#define SOUND_PCM_GETOSPACE	SNDCTL_DSP_GETOSPACE
+#define SOUND_PCM_GETISPACE	SNDCTL_DSP_GETISPACE
+#endif
+
 #include "m_pd.h"
 #include "s_stuff.h"
 #include <errno.h>
@@ -120,7 +125,7 @@ typedef struct _multidev {
 
 int oss_reset(int fd) {
      int err;
-     if ((err = ioctl(fd,SNDCTL_DSP_RESET)) < 0)
+     if ((err = ioctl(fd,SNDCTL_DSP_RESET,0)) < 0)
           error("OSS: Could not reset");
      return err;
 }
