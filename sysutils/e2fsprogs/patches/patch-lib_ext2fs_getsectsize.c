$NetBSD: patch-lib_ext2fs_getsectsize.c,v 1.1 2026/05/10 07:52:13 vins Exp $

Fix implicit declaration of ioctl on *BSD. 

--- lib/ext2fs/getsectsize.c.orig	2026-05-10 07:22:00.580778643 +0000
+++ lib/ext2fs/getsectsize.c
@@ -29,8 +29,10 @@
 #ifdef HAVE_SYS_DISK_H
 #include <sys/disk.h>
 #endif
-#ifdef HAVE_LINUX_FD_H
+#ifdef HAVE_SYS_IOCTL_H
 #include <sys/ioctl.h>
+#endif
+#ifdef HAVE_LINUX_FD_H
 #include <linux/fd.h>
 #endif
 
