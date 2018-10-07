$NetBSD: patch-src_intel_vulkan_anv__gem.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

* Define ETIME if missing

FreeBSD Bugzilla - Bug 225415: graphics/mesa-dri: update to 18.0.0
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415

--- src/intel/vulkan/anv_gem.c.orig	2018-02-09 02:17:59.000000000 +0000
+++ src/intel/vulkan/anv_gem.c
@@ -26,6 +26,9 @@
 #include <sys/mman.h>
 #include <string.h>
 #include <errno.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 #include <unistd.h>
 #include <fcntl.h>
 
