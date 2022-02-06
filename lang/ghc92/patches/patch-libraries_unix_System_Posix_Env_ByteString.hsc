$NetBSD: patch-libraries_unix_System_Posix_Env_ByteString.hsc,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/Env/ByteString.hsc.orig	2016-11-17 22:08:50.000000000 +0000
+++ libraries/unix/System/Posix/Env/ByteString.hsc
@@ -130,7 +130,7 @@ putEnv :: ByteString {- ^ "key=value" -}
 putEnv keyvalue = B.useAsCString keyvalue $ \s ->
   throwErrnoIfMinus1_ "putenv" (c_putenv s)
 
-foreign import ccall unsafe "putenv"
+foreign import capi unsafe "stdlib.h putenv"
    c_putenv :: CString -> IO CInt
 
 {- |The 'setEnv' function inserts or resets the environment variable name in
