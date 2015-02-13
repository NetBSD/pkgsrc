$NetBSD: patch-libraries_unix_System_Posix_Signals.hsc,v 1.1 2015/02/13 19:28:40 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall". In Haskell FFI, "ccall" is actually an
interface to C ABI rather than C API. That is, GHC generates direct
references to the symbol even if it's actually defined as a cpp macro
or something like that, because GHC knows nothing about those macros
in foreign headers. Hence the following warnings:

  .../libHSunix-2.6.0.1.a(Signals.o): In function `s4SG_info':
  (.text+0x3a3e): warning: warning: reference to compatibility
  sigsuspend(); include <signal.h> for correct reference
  .../libHSunix-2.6.0.1.a(Signals.o): In function `s5uV_info':
  (.text+0x6adb): warning: warning: reference to compatibility
  sigpending(); include <signal.h> for correct reference

In other words, you can safely use "ccall" only when you are sure the
symbol you want to import is actually a symbol in the ABI sense, which
is not always the case for the POSIX API.

--- libraries/unix/System/Posix/Signals.hsc.orig	2015-02-13 15:40:27.000000000 +0000
+++ libraries/unix/System/Posix/Signals.hsc
@@ -598,7 +598,7 @@ awaitSignal maybe_sigset = do
   -- XXX My manpage says it can also return EFAULT. And why is ignoring
   -- EINTR the right thing to do?
 
-foreign import ccall unsafe "sigsuspend"
+foreign import capi unsafe "signal.h sigsuspend"
   c_sigsuspend :: Ptr CSigset -> IO CInt
 #endif
 
@@ -622,6 +622,6 @@ foreign import capi unsafe "signal.h sig
   c_sigismember :: Ptr CSigset -> CInt -> IO CInt
 #endif /* __HUGS__ */
 
-foreign import ccall unsafe "sigpending"
+foreign import capi unsafe "signal.h sigpending"
   c_sigpending :: Ptr CSigset -> IO CInt
 
