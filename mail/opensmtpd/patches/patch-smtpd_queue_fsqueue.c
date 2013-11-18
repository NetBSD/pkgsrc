$NetBSD: patch-smtpd_queue_fsqueue.c,v 1.1 2013/11/18 22:50:01 pettai Exp $

NetBSD use statvfs, not statfs.

--- smtpd/queue_fsqueue.c.orig	2013-05-16 15:19:59.000000000 +0000
+++ smtpd/queue_fsqueue.c
@@ -26,5 +26,11 @@
 #ifdef HAVE_SYS_STATFS_H
 #include <sys/statfs.h>
 #endif
+#ifdef HAVE_SYS_STATVFS_H
+#include <sys/statvfs.h>
+#ifdef __NetBSD__
+#define statfs statvfs
+#endif
+#endif
 #include <sys/param.h>
 #include <sys/mount.h>
