$NetBSD: patch-libraries_unix_System_Posix_Env_PosixString.hsc,v 1.1 2024/04/28 05:58:58 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/Env/PosixString.hsc.orig	2023-10-23 10:24:23.010158238 +0000
+++ libraries/unix/System/Posix/Env/PosixString.hsc
@@ -146,7 +146,7 @@ putEnv (PS sbs) = do
  where l = B.length sbs
 
 
-foreign import ccall unsafe "putenv"
+foreign import capi unsafe "HsUnix.h putenv"
    c_putenv :: CString -> IO CInt
 
 {- |The 'setEnv' function inserts or resets the environment variable name in
