$NetBSD: patch-src_intel_vulkan_anv__queue.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

* Define ETIME if missing
* Drop header that was never used (modified for Linux inclusion)

FreeBSD Bugzilla - Bug 225415: graphics/mesa-dri: update to 18.0.0
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415

--- src/intel/vulkan/anv_queue.c.orig	2018-02-09 02:17:59.000000000 +0000
+++ src/intel/vulkan/anv_queue.c
@@ -26,8 +26,14 @@
  */
 
 #include <fcntl.h>
+#include <errno.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include <unistd.h>
+#if defined(__linux__)
 #include <sys/eventfd.h>
+#endif
 
 #include "anv_private.h"
 #include "vk_util.h"
