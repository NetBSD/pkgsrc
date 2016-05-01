$NetBSD: patch-smtpd_queue__fs.c,v 1.1 2016/05/01 05:56:40 mef Exp $

NetBSD use statvfs, not statfs.

--- smtpd/queue_fs.c.orig	2016-02-02 07:40:06.000000000 +0000
+++ smtpd/queue_fs.c
@@ -30,6 +30,12 @@
 #ifdef HAVE_SYS_STATFS_H
 #include <sys/statfs.h>
 #endif
+#ifdef HAVE_SYS_STATVFS_H
+#include <sys/statvfs.h>
+#ifdef __NetBSD__
+#define statfs statvfs
+#endif
+#endif
 
 #include <ctype.h>
 #include <dirent.h>
