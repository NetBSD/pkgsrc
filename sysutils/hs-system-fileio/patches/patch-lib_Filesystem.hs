$NetBSD: patch-lib_Filesystem.hs,v 1.1 2022/02/24 01:21:55 pho Exp $

Use the correct symbol for opendir(3) by using CApiFFI, required on NetBSD.

--- lib/Filesystem.hs.orig	2022-02-21 08:32:13.199111538 +0000
+++ lib/Filesystem.hs
@@ -1,5 +1,6 @@
 {-# LANGUAGE CPP #-}
 {-# LANGUAGE ForeignFunctionInterface #-}
+{-# LANGUAGE CApiFFI #-}
 
 -- |
 -- Module: Filesystem
@@ -351,7 +352,7 @@ readDir (Dir _ p) dirent = do
 			return (Just bytes)
 		else return Nothing
 
-foreign import ccall unsafe "opendir"
+foreign import capi unsafe "dirent.h opendir"
 	c_opendir :: CString -> IO (Ptr ())
 
 foreign import ccall unsafe "closedir"
