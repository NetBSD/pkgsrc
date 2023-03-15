$NetBSD: patch-util_osdep.c,v 1.1 2023/03/15 11:49:20 jperkin Exp $

Don't use OFD locking on SunOS.
https://github.com/omniosorg/omnios-extra/blob/master/build/qemu/patches/0002-illumos-OFD-locking-must-span-the-entire-file.patch

--- util/osdep.c.orig	2022-12-14 16:28:45.000000000 +0000
+++ util/osdep.c
@@ -31,6 +31,10 @@
 #include "qemu/hw-version.h"
 #include "monitor/monitor.h"
 
+#if defined(__sun)
+#undef F_OFD_SETLK
+#endif
+
 static const char *hw_version = QEMU_HW_VERSION;
 
 int socket_set_cork(int fd, int v)
