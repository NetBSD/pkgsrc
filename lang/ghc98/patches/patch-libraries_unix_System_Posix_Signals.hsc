$NetBSD: patch-libraries_unix_System_Posix_Signals.hsc,v 1.1 2024/04/28 05:58:58 pho Exp $

Suppress linker warnings about compatibility symbols.

--- libraries/unix/System/Posix/Signals.hsc.orig	2023-09-21 11:31:41.000000000 +0000
+++ libraries/unix/System/Posix/Signals.hsc
@@ -848,7 +848,7 @@ awaitSignal maybe_sigset = do
 
 #if defined(HAVE_SIGNAL_H)
 
-foreign import ccall unsafe "sigsuspend"
+foreign import capi unsafe "signal.h sigsuspend"
   c_sigsuspend :: Ptr CSigset -> IO CInt
 
 foreign import capi unsafe "signal.h sigdelset"
@@ -860,7 +860,7 @@ foreign import capi unsafe "signal.h sig
 foreign import capi unsafe "signal.h sigismember"
   c_sigismember :: Ptr CSigset -> CInt -> IO CInt
 
-foreign import ccall unsafe "sigpending"
+foreign import capi unsafe "signal.h sigpending"
   c_sigpending :: Ptr CSigset -> IO CInt
 
 #endif // HAVE_SIGNAL_H
