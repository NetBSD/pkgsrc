$NetBSD: patch-libraries_base_System_Environment.hs,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall".

--- libraries/base/System/Environment.hs.orig	2018-02-25 20:02:28.000000000 +0000
+++ libraries/base/System/Environment.hs
@@ -1,5 +1,6 @@
 {-# LANGUAGE Safe #-}
 {-# LANGUAGE CPP #-}
+{-# LANGUAGE CApiFFI #-}
 
 -----------------------------------------------------------------------------
 -- |
@@ -246,7 +247,7 @@ putEnv keyvalue = do
   -- environment.
   throwErrnoIf_ (/= 0) "putenv" (c_putenv s)
 
-foreign import ccall unsafe "putenv" c_putenv :: CString -> IO CInt
+foreign import capi unsafe "stdlib.h putenv" c_putenv :: CString -> IO CInt
 #endif
 
 -- | @unsetEnv name@ removes the specified environment variable from the
