$NetBSD: patch-libraries_time_Data_Time_Clock_CTimeval.hs,v 1.1 2015/02/13 19:28:40 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall". In Haskell FFI, "ccall" is actually an
interface to C ABI rather than C API. That is, GHC generates direct
references to the symbol even if it's actually defined as a cpp macro
or something like that, because GHC knows nothing about those macros
in foreign headers. Hence the following warnings:

  .../libHStime-1.4.0.1.a(CTimeval.o): In function `s1Kp_info':
  (.text+0x2f): warning: warning: reference to compatibility
  gettimeofday(); include <sys/time.h> to generate correct reference

In other words, you can safely use "ccall" only when you are sure the
symbol you want to import is actually a symbol in the ABI sense, which
is not always the case for the POSIX API.

--- libraries/time/Data/Time/Clock/CTimeval.hs.orig	2015-02-13 15:42:45.000000000 +0000
+++ libraries/time/Data/Time/Clock/CTimeval.hs
@@ -1,3 +1,4 @@
+{-# LANGUAGE CApiFFI #-}
 -- #hide
 module Data.Time.Clock.CTimeval where
 
@@ -20,7 +21,7 @@ instance Storable CTimeval where
 		pokeElemOff (castPtr p) 0 s
 		pokeElemOff (castPtr p) 1 mus
 
-foreign import ccall unsafe "time.h gettimeofday" gettimeofday :: Ptr CTimeval -> Ptr () -> IO CInt
+foreign import capi unsafe "sys/time.h gettimeofday" gettimeofday :: Ptr CTimeval -> Ptr () -> IO CInt
 
 -- | Get the current POSIX time from the system clock.
 getCTimeval :: IO CTimeval
