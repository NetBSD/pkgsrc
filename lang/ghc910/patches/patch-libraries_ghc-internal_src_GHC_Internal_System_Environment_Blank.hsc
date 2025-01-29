$NetBSD: patch-libraries_ghc-internal_src_GHC_Internal_System_Environment_Blank.hsc,v 1.1 2025/01/29 13:21:53 pho Exp $

Use the correct symbol by going through the C header as opposed to directly
referencing a symbol in libc.

--- libraries/ghc-internal/src/GHC/Internal/System/Environment/Blank.hsc.orig	2025-01-09 09:01:08.402455355 +0000
+++ libraries/ghc-internal/src/GHC/Internal/System/Environment/Blank.hsc
@@ -211,5 +211,5 @@ putEnv keyvalue = do
   -- environment. #7342
   throwErrnoIf_ (/= 0) "putenv" (c_putenv s)
 
-foreign import ccall unsafe "putenv" c_putenv :: CString -> IO CInt
+foreign import capi unsafe "stdlib.h putenv" c_putenv :: CString -> IO CInt
 #endif
