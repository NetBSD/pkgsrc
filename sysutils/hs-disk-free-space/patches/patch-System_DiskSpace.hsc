$NetBSD: patch-System_DiskSpace.hsc,v 1.1 2024/05/05 12:39:47 pho Exp $

Use capi calling convention. On NetBSD statvfs(2) isn't a regular symbol in
libc.

--- System/DiskSpace.hsc.orig	2024-05-05 12:36:08.046949584 +0000
+++ System/DiskSpace.hsc
@@ -1,3 +1,4 @@
+{-# LANGUAGE CApiFFI #-}
 {-# LANGUAGE CPP #-}
 
 {- |
@@ -20,7 +21,7 @@ import Foreign.C
 
 #include <sys/statvfs.h>
 
-foreign import ccall safe statvfs :: CString -> Ptr a -> IO CInt
+foreign import capi safe "sys/statvfs.h statvfs" statvfs :: CString -> Ptr a -> IO CInt
 
 type FsBlkCnt = #type fsblkcnt_t
 
