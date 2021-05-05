$NetBSD: patch-Foundation_Foreign_MemoryMap_Posix.hsc,v 1.1 2021/05/05 16:38:40 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall".

--- Foundation/Foreign/MemoryMap/Posix.hsc.orig	2021-05-05 16:31:38.032586413 +0000
+++ Foundation/Foreign/MemoryMap/Posix.hsc
@@ -22,6 +22,7 @@
 
 {-# LANGUAGE ForeignFunctionInterface #-}
 {-# LANGUAGE CPP #-}
+{-# LANGUAGE CApiFFI #-}
 module Foundation.Foreign.MemoryMap.Posix
     ( memoryMap
     , memoryUnmap
@@ -73,7 +74,7 @@ foreign import ccall unsafe "madvise"
     c_madvise :: Ptr a -> CSize -> CInt -> IO CInt
 #endif
 
-foreign import ccall unsafe "msync"
+foreign import capi unsafe "sys/mman.h msync"
     c_msync :: Ptr a -> CSize -> CInt -> IO CInt
 
 foreign import ccall unsafe "mprotect"
