$NetBSD: patch-libraries_ghc-internal_src_GHC_Internal_System_Environment.hs,v 1.1 2025/01/29 13:21:53 pho Exp $

Use the correct symbol by going through the C header as opposed to directly
referencing a symbol in libc.

--- libraries/ghc-internal/src/GHC/Internal/System/Environment.hs.orig	2025-01-09 08:57:57.755161331 +0000
+++ libraries/ghc-internal/src/GHC/Internal/System/Environment.hs
@@ -1,5 +1,6 @@
 {-# LANGUAGE Trustworthy #-}
 {-# LANGUAGE CPP #-}
+{-# LANGUAGE CApiFFI #-}
 
 -----------------------------------------------------------------------------
 -- |
@@ -267,7 +268,7 @@ putEnv keyvalue = do
   -- environment.
   throwErrnoIf_ (/= 0) "putenv" (c_putenv s)
 
-foreign import ccall unsafe "putenv" c_putenv :: CString -> IO CInt
+foreign import capi unsafe "stdlib.h putenv" c_putenv :: CString -> IO CInt
 #endif
 
 -- | @unsetEnv name@ removes the specified environment variable from the
