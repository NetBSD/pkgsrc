$NetBSD: patch-Foundation_System_Bindings_Posix.hsc,v 1.1 2021/05/05 16:18:07 pho Exp $

dirfd(3) is a macro on NetBSD. It doesn't exist as a symbol in libc.

--- Foundation/System/Bindings/Posix.hsc.orig	2021-05-05 16:09:20.261233488 +0000
+++ Foundation/System/Bindings/Posix.hsc
@@ -27,7 +27,7 @@ import Foundation.System.Bindings.PosixD
 #include <fcntl.h>
 #include <errno.h>
 
-data CDir
+data {-# CTYPE "dirent.h" "DIR" #-} CDir
 data CDirent
 
 sysPosix_E2BIG
@@ -377,5 +377,5 @@ foreign import ccall unsafe "rewinddir"
     sysPosixRewinddir :: Ptr CDir -> IO ()
 foreign import ccall unsafe "closedir"
     sysPosixClosedir :: Ptr CDir -> IO CInt
-foreign import ccall unsafe "dirfd"
+foreign import capi unsafe "dirent.h dirfd"
     sysPosixDirfd :: Ptr CDir -> IO CFd
