$NetBSD: patch-libraries_unix_System_Posix_Env_ByteString.hsc,v 1.1 2019/12/31 07:10:30 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/Env/ByteString.hsc.orig	2019-12-31 00:06:05.528517546 +0000
+++ libraries/unix/System/Posix/Env/ByteString.hsc
@@ -4,6 +4,7 @@
 {-# OPTIONS_GHC -fno-warn-trustworthy-safe #-}
 #endif
 #endif
+{-# LANGUAGE CApiFFI #-}
 
 -----------------------------------------------------------------------------
 -- |
@@ -118,7 +119,7 @@ putEnv :: ByteString -> IO ()
 putEnv keyvalue = B.useAsCString keyvalue $ \s ->
   throwErrnoIfMinus1_ "putenv" (c_putenv s)
 
-foreign import ccall unsafe "putenv"
+foreign import capi unsafe "stdlib.h putenv"
    c_putenv :: CString -> IO CInt
 
 {- |The 'setEnv' function inserts or resets the environment variable name in
