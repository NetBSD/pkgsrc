$NetBSD: patch-lib_ext2fs_ext2fsP.h,v 1.1 2024/08/03 07:33:29 wiz Exp $

Handle character devices on NetBSD like on FreeBSD.
PR 58545 by RVP.

--- lib/ext2fs/ext2fsP.h.orig	2021-08-19 02:53:01.000000000 +0000
+++ lib/ext2fs/ext2fsP.h
@@ -19,7 +19,7 @@
 
 static inline int ext2fsP_is_disk_device(mode_t mode)
 {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__)
 	return S_ISBLK(mode) || S_ISCHR(mode);
 #else
 	return S_ISBLK(mode);
