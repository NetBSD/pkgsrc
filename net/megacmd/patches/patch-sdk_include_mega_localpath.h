$NetBSD: patch-sdk_include_mega_localpath.h,v 1.1 2026/02/11 17:04:10 kikadf Exp $

* Add filesystem support to BSDs

--- sdk/include/mega/localpath.h.orig	2026-02-08 19:23:32.037218658 +0100
+++ sdk/include/mega/localpath.h
@@ -33,6 +33,10 @@ enum FileSystemType
     FS_SMB = 12,
     FS_SMB2 = 13,
     FS_LIFS = 14,
+    FS_FFS = 15,
+    FS_HAMMER = 16,
+    FS_UFS = 17,
+    FS_ZFS = 18,
 };
 
 #ifdef WIN32
