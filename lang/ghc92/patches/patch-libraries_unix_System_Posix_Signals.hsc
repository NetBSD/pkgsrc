$NetBSD: patch-libraries_unix_System_Posix_Signals.hsc,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility symbols.

--- libraries/unix/System/Posix/Signals.hsc.orig	2016-04-20 10:08:26.000000000 +0000
+++ libraries/unix/System/Posix/Signals.hsc
@@ -590,7 +590,7 @@ awaitSignal maybe_sigset = do
   -- XXX My manpage says it can also return EFAULT. And why is ignoring
   -- EINTR the right thing to do?
 
-foreign import ccall unsafe "sigsuspend"
+foreign import capi unsafe "signal.h sigsuspend"
   c_sigsuspend :: Ptr CSigset -> IO CInt
 
 #if defined(darwin_HOST_OS) && __GLASGOW_HASKELL__ < 706
@@ -615,5 +615,5 @@ foreign import capi unsafe "signal.h sig
   c_sigismember :: Ptr CSigset -> CInt -> IO CInt
 #endif
 
-foreign import ccall unsafe "sigpending"
+foreign import capi unsafe "signal.h sigpending"
   c_sigpending :: Ptr CSigset -> IO CInt
