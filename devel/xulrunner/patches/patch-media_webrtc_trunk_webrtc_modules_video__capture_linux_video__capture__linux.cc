$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_linux_video__capture__linux.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/linux/video_capture_linux.cc.orig	2013-05-11 19:19:45.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/linux/video_capture_linux.cc
@@ -12,12 +12,23 @@
 #include <unistd.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <linux/videodev2.h>
 #include <errno.h>
 #include <stdio.h>
 #include <sys/mman.h>
 #include <string.h>
 
+//v4l includes
+#if defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/videoio.h>
+#elif defined(__sun)
+#include <sys/videodev2.h>
+#else
+#include <linux/videodev2.h>
+#endif
+#ifdef HAVE_LIBV4L2
+#include <libv4l2.h>
+#endif
+
 #include <new>
 
 #include "ref_count.h"
@@ -26,6 +37,15 @@
 #include "critical_section_wrapper.h"
 #include "video_capture_linux.h"
 
+#ifdef HAVE_LIBV4L2
+#define open	v4l2_open
+#define close	v4l2_close
+#define dup	v4l2_dup
+#define ioctl	v4l2_ioctl
+#define mmap	v4l2_mmap
+#define munmap	v4l2_munmap
+#endif
+
 namespace webrtc
 {
 namespace videocapturemodule
