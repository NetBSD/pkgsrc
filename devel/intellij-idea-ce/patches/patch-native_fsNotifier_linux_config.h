$NetBSD: patch-native_fsNotifier_linux_config.h,v 1.1 2013/11/24 10:44:34 ryoon Exp $

* Workaround for NetBSD. This should be fixed.

--- native/fsNotifier/linux/config.h.orig	2013-11-23 23:41:00.000000000 +0000
+++ native/fsNotifier/linux/config.h
@@ -0,0 +1 @@
+#define HAVE_SYS_STATVFS_H 1
