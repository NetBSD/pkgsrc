$NetBSD: patch-libfsimage_ufs_ufs.h,v 1.1 2016/12/29 23:12:23 wiz Exp $

--- libfsimage/ufs/ufs.h.orig	2013-07-14 19:44:35.000000000 +0000
+++ libfsimage/ufs/ufs.h
@@ -4,7 +4,7 @@
  */
 
 #ifndef _GRUB_UFS_H
-#define _GRUB_UFS_H_
+#define _GRUB_UFS_H
 
 /* ufs specific constants */
 #define UFS_SBLOCK	16
