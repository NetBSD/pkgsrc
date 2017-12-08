$NetBSD: patch-misc_create__inode.c,v 1.2 2017/12/08 08:12:58 adam Exp $

Fix build on SunOS.

--- misc/create_inode.c.orig	2017-10-16 05:45:45.000000000 +0000
+++ misc/create_inode.c
@@ -25,6 +25,9 @@
 #ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
 #endif
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 
 #include <ext2fs/ext2fs.h>
 #include <ext2fs/ext2_types.h>
