$NetBSD: patch-libraries_base_System_Environment.hs,v 1.1 2019/12/29 16:59:09 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall".

--- libraries/base/System/Environment.hs.orig	2019-12-26 18:13:03.344291616 +0000
+++ libraries/base/System/Environment.hs
@@ -1,5 +1,6 @@
 {-# LANGUAGE Safe #-}
 {-# LANGUAGE CPP #-}
+{-# LANGUAGE CApiFFI #-}
 
 -----------------------------------------------------------------------------
 -- |
@@ -302,7 +303,7 @@ putEnv keyvalue = do
   -- enviroment.
   throwErrnoIf_ (/= 0) "putenv" (c_putenv s)
 
-foreign import ccall unsafe "putenv" c_putenv :: CString -> IO CInt
+foreign import capi unsafe "stdlib.h putenv" c_putenv :: CString -> IO CInt
 #endif
 
 -- | @unSet name@ removes the specified environment variable from the
