$NetBSD: patch-libraries_unix_System_Posix_Env_ByteString.hsc,v 1.1 2023/01/21 04:49:25 pho Exp $

Suppress linker warnings about compatibility symbols by using "capi"
instead of "ccall".

--- libraries/unix/System/Posix/Env/ByteString.hsc.orig	2022-12-23 16:19:54.000000000 +0000
+++ libraries/unix/System/Posix/Env/ByteString.hsc
@@ -153,7 +153,7 @@ putEnv (PS fp o l) = withForeignPtr fp $
   pokeByteOff buf l (0::Word8)
   throwErrnoIfMinus1_ "putenv" (c_putenv (castPtr buf))
 
-foreign import ccall unsafe "putenv"
+foreign import capi unsafe "HsUnix.h putenv"
    c_putenv :: CString -> IO CInt
 
 {- |The 'setEnv' function inserts or resets the environment variable name in
