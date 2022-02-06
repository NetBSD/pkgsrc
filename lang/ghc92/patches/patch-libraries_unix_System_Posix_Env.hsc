$NetBSD: patch-libraries_unix_System_Posix_Env.hsc,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/Env.hsc.orig	2016-11-17 22:08:50.000000000 +0000
+++ libraries/unix/System/Posix/Env.hsc
@@ -156,7 +156,7 @@ putEnv keyvalue = do s <- newFilePath ke
       newFilePath fp = getFileSystemEncoding >>= \enc -> GHC.newCString enc fp
 #endif
 
-foreign import ccall unsafe "putenv"
+foreign import capi unsafe "stdlib.h putenv"
    c_putenv :: CString -> IO CInt
 
 {- |The 'setEnv' function inserts or resets the environment variable name in
