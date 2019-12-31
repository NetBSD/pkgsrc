$NetBSD: patch-libraries_unix_System_Posix_Env.hsc,v 1.1 2019/12/31 07:10:30 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/Env.hsc.orig	2019-12-31 00:05:02.553011557 +0000
+++ libraries/unix/System/Posix/Env.hsc
@@ -3,6 +3,7 @@
 #elif __GLASGOW_HASKELL__ >= 703
 {-# LANGUAGE Trustworthy #-}
 #endif
+{-# LANGUAGE CApiFFI #-}
 -----------------------------------------------------------------------------
 -- |
 -- Module      :  System.Posix.Env
@@ -142,7 +143,7 @@ putEnv keyvalue = do s <- newFilePath ke
       newFilePath fp = getFileSystemEncoding >>= \enc -> GHC.newCString enc fp
 #endif
 
-foreign import ccall unsafe "putenv"
+foreign import capi unsafe "stdlib.h putenv"
    c_putenv :: CString -> IO CInt
 
 {- |The 'setEnv' function inserts or resets the environment variable name in
