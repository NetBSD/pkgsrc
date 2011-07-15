$NetBSD: patch-lib_libdvbapi_dvbaudio.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libdvbapi/dvbaudio.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libdvbapi/dvbaudio.c
@@ -25,7 +25,11 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifdef __NetBSD__
+#include <dev/dtv/dtvio.h>
+#else
 #include <linux/dvb/audio.h>
+#endif
 #include <errno.h>
 #include "dvbaudio.h"
 
@@ -46,5 +50,9 @@ int dvbaudio_open(int adapter, int audio
 
 int dvbaudio_set_bypass(int fd, int bypass)
 {
+#ifdef AUDIO_SET_BYPASS_MODE
 	return ioctl(fd, AUDIO_SET_BYPASS_MODE, bypass);
+#else
+	return -1;
+#endif
 }
