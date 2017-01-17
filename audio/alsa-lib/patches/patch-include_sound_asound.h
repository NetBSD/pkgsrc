$NetBSD: patch-include_sound_asound.h,v 1.4 2017/01/17 15:21:05 wiz Exp $

Include sys/time.h for struct timespec.

--- include/sound/asound.h.orig	2016-03-31 13:10:39.000000000 +0000
+++ include/sound/asound.h
@@ -27,6 +27,7 @@
 #include <linux/types.h>
 #else
 #include <sys/ioctl.h>
+#include <sys/time.h>
 #endif
 
 #ifndef __KERNEL__
