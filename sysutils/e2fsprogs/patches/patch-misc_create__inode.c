$NetBSD: patch-misc_create__inode.c,v 1.1 2017/09/21 09:48:56 jperkin Exp $

Fix build on SunOS.

--- misc/create_inode.c.orig	2017-01-31 06:08:02.000000000 +0000
+++ misc/create_inode.c
@@ -22,6 +22,9 @@
 #include <attr/xattr.h>
 #endif
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 #include <ext2fs/ext2fs.h>
 #include <ext2fs/ext2_types.h>
 #include <ext2fs/fiemap.h>
