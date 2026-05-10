$NetBSD: patch-misc_create__inode.c,v 1.4 2026/05/10 07:52:13 vins Exp $

Fix build on SunOS.

--- misc/create_inode.c.orig	2026-03-06 17:17:36.000000000 +0000
+++ misc/create_inode.c
@@ -30,6 +30,9 @@
 #ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
 #endif
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 #if defined(HAVE_LINUX_FSVERITY_H) && defined(HAVE_FS_IOC_READ_VERITY_METADATA)
 #include <linux/fsverity.h>
 #include <linux/fs.h>
