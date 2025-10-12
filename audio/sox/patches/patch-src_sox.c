$NetBSD: patch-src_sox.c,v 1.2 2025/10/12 04:06:27 mrg Exp $

PR pkg/56800 hitting v or V during sox's play command causes a
segfault

https://sourceforge.net/p/sox/code/ci/4b17639fb7591153dbd3e234eea21b1a2a29fcfa/
from more than 10 years ago changed the sun audio driver for the 14.4 release
to not use stdio (among others) while adjust_volume() in sox.c still used
fileno under the assumption that stdio was being used in the audio driver.

output_muted is not defined on NetBSD.

include <sys/ioctl.h> to get ioctl() prototype.

--- src/sox.c.orig	2014-10-05 19:02:30.000000000 -0700
+++ src/sox.c	2025-10-11 20:54:02.019395172 -0700
@@ -1311,9 +1311,11 @@ static void adjust_volume(int delta)
     putc('\a', stderr);
 }
 #elif defined(HAVE_AUDIOIO_H)
+#include <sys/ioctl.h>
 static void adjust_volume(int delta)
 {
-  int vol1 = 0, vol2 = 0, fd = fileno((FILE*)ofile->ft->fp);
+  int vol1 = 0, vol2 = 0, fd;
+  fd = ofile->ft->fp != NULL ? *((int *)ofile->ft->fp) : -1;
   if (fd >= 0) {
     audio_info_t audio_info;
     if (ioctl(fd, AUDIO_GETINFO, &audio_info) >= 0) {
@@ -1321,7 +1323,9 @@ static void adjust_volume(int delta)
       vol2 = range_limit(vol1 + delta, 0, 100);
       AUDIO_INITINFO(&audio_info);
       audio_info.play.gain = (vol2 * AUDIO_MAX_GAIN + 50) / 100;
+#if defined(__sun)
       audio_info.output_muted = 0;
+#endif
       lsx_debug("%04x %04x", vol1, vol2);
       if (vol1 != vol2 && ioctl(fd, AUDIO_SETINFO, &audio_info) < 0)
         vol2 = vol1;
