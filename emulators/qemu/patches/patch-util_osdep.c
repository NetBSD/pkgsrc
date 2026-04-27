$NetBSD: patch-util_osdep.c,v 1.2 2026/04/27 10:25:01 adam Exp $

Don't use OFD locking on SunOS.
https://github.com/omniosorg/omnios-extra/blob/master/build/qemu/patches/0002-illumos-OFD-locking-must-span-the-entire-file.patch

--- util/osdep.c.orig	2026-04-21 19:36:27.000000000 +0000
+++ util/osdep.c
@@ -31,6 +31,10 @@
 #include "qemu/hw-version.h"
 #include "monitor/monitor.h"
 
+#if defined(__sun)
+#undef F_OFD_SETLK
+#endif
+
 int socket_set_cork(int fd, int v)
 {
 #if defined(SOL_TCP) && defined(TCP_CORK)
