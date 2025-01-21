$NetBSD: patch-misc_create__inode.c,v 1.3 2025/01/21 18:13:57 triaxx Exp $

Fix build on SunOS.

--- misc/create_inode.c.orig	2017-10-16 05:45:45.000000000 +0000
+++ misc/create_inode.c
@@ -30,6 +30,9 @@
 #ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
 #endif
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 
 #include <ext2fs/ext2fs.h>
 #include <ext2fs/ext2_types.h>
