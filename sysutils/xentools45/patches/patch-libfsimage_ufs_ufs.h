$NetBSD: patch-libfsimage_ufs_ufs.h,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- libfsimage/ufs/ufs.h.orig	2015-01-12 17:53:24.000000000 +0100
+++ libfsimage/ufs/ufs.h	2015-01-19 13:16:38.000000000 +0100
@@ -4,7 +4,7 @@
  */
 
 #ifndef _GRUB_UFS_H
-#define _GRUB_UFS_H_
+#define _GRUB_UFS_H
 
 /* ufs specific constants */
 #define UFS_SBLOCK	16
