$NetBSD: patch-Data_Memory_MemMap_Posix.hsc,v 1.2 2022/02/11 09:35:09 pho Exp $

Use the correct symbol for msync(2) on NetBSD.

--- Data/Memory/MemMap/Posix.hsc.orig	2022-02-06 19:45:13.938394169 +0000
+++ Data/Memory/MemMap/Posix.hsc
@@ -20,6 +20,7 @@
 #include <sys/mman.h>
 #include <unistd.h>
 
+{-# LANGUAGE CApiFFI #-}
 {-# LANGUAGE ForeignFunctionInterface #-}
 {-# LANGUAGE CPP #-}
 module Data.Memory.MemMap.Posix
@@ -59,7 +60,7 @@ foreign import ccall unsafe "madvise"
     c_madvise :: Ptr a -> CSize -> CInt -> IO CInt
 #endif
 
-foreign import ccall unsafe "msync"
+foreign import capi unsafe "sys/mman.h msync"
     c_msync :: Ptr a -> CSize -> CInt -> IO CInt
 
 foreign import ccall unsafe "mprotect"
