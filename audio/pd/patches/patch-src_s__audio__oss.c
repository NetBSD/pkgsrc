$NetBSD: patch-src_s__audio__oss.c,v 1.2 2011/10/05 20:02:48 wiz Exp $

Use proper soundcard.h include on NetBSD and add missing argument
to ioctl().
https://sourceforge.net/tracker/?func=detail&aid=3411732&group_id=55736&atid=478072

--- src/s_audio_oss.c.orig	2011-03-07 01:33:39.000000000 +0000
+++ src/s_audio_oss.c
@@ -5,7 +5,7 @@
 
 /* this file inputs and outputs audio using the OSS API available on linux. */
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 # include <sys/soundcard.h>
 #else
 # include <linux/soundcard.h>
@@ -120,7 +120,7 @@ typedef struct _multidev {
 
 int oss_reset(int fd) {
      int err;
-     if ((err = ioctl(fd,SNDCTL_DSP_RESET)) < 0)
+     if ((err = ioctl(fd,SNDCTL_DSP_RESET,0)) < 0)
           error("OSS: Could not reset");
      return err;
 }
