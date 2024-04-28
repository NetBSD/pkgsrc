$NetBSD: patch-libraries_unix_System_Posix_Env.hsc,v 1.1 2024/04/28 05:58:58 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/Env.hsc.orig	2023-09-21 11:31:41.000000000 +0000
+++ libraries/unix/System/Posix/Env.hsc
@@ -141,7 +141,7 @@ putEnv keyvalue = do s <- newFilePath ke
                      -- becomes part of the environment. #7342
                      throwErrnoIfMinus1_ "putenv" (c_putenv s)
 
-foreign import ccall unsafe "putenv"
+foreign import capi unsafe "stdlib.h putenv"
    c_putenv :: CString -> IO CInt
 
 {- |The 'setEnv' function inserts or resets the environment variable name in
