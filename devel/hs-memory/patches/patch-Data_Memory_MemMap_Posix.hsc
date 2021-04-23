$NetBSD: patch-Data_Memory_MemMap_Posix.hsc,v 1.1 2021/04/23 09:35:57 pho Exp $

Suppress a linker warning about compatibility symbol by using "capi"
instead of "ccall".

--- Data/Memory/MemMap/Posix.hsc.orig	2019-09-02 02:59:04.000000000 +0000
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
