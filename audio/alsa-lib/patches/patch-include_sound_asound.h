$NetBSD: patch-include_sound_asound.h,v 1.5 2017/02/22 14:48:09 wiz Exp $

Include sys/time.h for struct timespec.

--- include/sound/asound.h.orig	2016-12-20 14:43:20.000000000 +0000
+++ include/sound/asound.h
@@ -27,6 +27,7 @@
 #include <linux/types.h>
 #else
 #include <sys/ioctl.h>
+#include <sys/time.h>
 #endif
 
 #ifndef __KERNEL__
