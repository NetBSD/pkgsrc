$NetBSD: patch-Foundation_System_Bindings_Posix.hsc,v 1.2 2021/05/05 16:38:40 pho Exp $

* dirfd(3) is a macro on NetBSD. It doesn't exist as a symbol in libc.

* Suppress linker warnings about compatibility syscall wrappers by
  using "capi" instead of "ccall".

--- Foundation/System/Bindings/Posix.hsc.orig	2019-09-02 03:58:08.000000000 +0000
+++ Foundation/System/Bindings/Posix.hsc
@@ -27,8 +27,8 @@ import Foundation.System.Bindings.PosixD
 #include <fcntl.h>
 #include <errno.h>
 
-data CDir
-data CDirent
+data {-# CTYPE "dirent.h" "DIR" #-} CDir
+data {-# CTYPE "dirent.h" "struct dirent" #-} CDirent
 
 sysPosix_E2BIG
     , sysPosix_EACCES
@@ -312,7 +312,7 @@ foreign import ccall unsafe "madvise"
     sysPosixMadvise :: Ptr a -> CSize -> CMemAdvice -> IO CInt
 #endif
 
-foreign import ccall unsafe "msync"
+foreign import capi unsafe "sys/mman.h msync"
     sysPosixMsync :: Ptr a -> CSize -> CMemSyncFlags -> IO CInt
 
 foreign import ccall unsafe "mprotect"
@@ -361,13 +361,13 @@ foreign import ccall unsafe "ftruncate"
 -- directories
 --------------------------------------------------------------------------------
 
-foreign import ccall unsafe "opendir"
+foreign import capi unsafe "dirent.h opendir"
     sysPosixOpendir :: Ptr CChar -> IO (Ptr CDir)
 foreign import ccall unsafe "fdopendir"
     sysPosixFdopendir :: CFd -> IO (Ptr CDir)
-foreign import ccall unsafe "readdir"
+foreign import capi unsafe "dirent.h readdir"
     sysPosixReaddir :: Ptr CDir -> IO (Ptr CDirent)
-foreign import ccall unsafe "readdir_r"
+foreign import capi unsafe "dirent.h readdir_r"
     sysPosixReaddirR :: Ptr CDir -> Ptr CDirent -> Ptr (Ptr CDirent) -> IO CInt
 foreign import ccall unsafe "telldir"
     sysPosixTelldir :: Ptr CDir -> IO CLong
@@ -377,5 +377,5 @@ foreign import ccall unsafe "rewinddir"
     sysPosixRewinddir :: Ptr CDir -> IO ()
 foreign import ccall unsafe "closedir"
     sysPosixClosedir :: Ptr CDir -> IO CInt
-foreign import ccall unsafe "dirfd"
+foreign import capi unsafe "dirent.h dirfd"
     sysPosixDirfd :: Ptr CDir -> IO CFd
