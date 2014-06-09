$NetBSD: patch-include_sound_asound.h,v 1.1 2014/06/09 12:21:07 ryoon Exp $

--- include/sound/asound.h.orig	2013-07-08 12:31:36.000000000 +0000
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
 
 /*
  *  protocol version
