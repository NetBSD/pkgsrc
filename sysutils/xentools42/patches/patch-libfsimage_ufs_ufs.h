$NetBSD: patch-libfsimage_ufs_ufs.h,v 1.2 2015/08/23 16:17:12 spz Exp $

--- libfsimage/ufs/ufs.h.orig	2014-09-02 06:22:57.000000000 +0000
+++ libfsimage/ufs/ufs.h
@@ -4,7 +4,7 @@
  */
 
 #ifndef _GRUB_UFS_H
-#define _GRUB_UFS_H_
+#define _GRUB_UFS_H
 
 /* ufs specific constants */
 #define UFS_SBLOCK	16
