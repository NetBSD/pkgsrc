$NetBSD: patch-libraries_time_lib_Data_Time_Clock_Internal_CTimeval.hs,v 1.1 2022/02/06 05:36:16 pho Exp $

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

--- libraries/time/lib/Data/Time/Clock/Internal/CTimeval.hs.orig	2021-10-28 20:42:10.000000000 +0000
+++ libraries/time/lib/Data/Time/Clock/Internal/CTimeval.hs
@@ -1,3 +1,4 @@
+{-# LANGUAGE CApiFFI #-}
 {-# LANGUAGE Safe #-}
 
 module Data.Time.Clock.Internal.CTimeval where
@@ -21,7 +22,7 @@ instance Storable CTimeval where
         pokeElemOff (castPtr p) 0 s
         pokeElemOff (castPtr p) 1 mus
 
-foreign import ccall unsafe "time.h gettimeofday" gettimeofday :: Ptr CTimeval -> Ptr () -> IO CInt
+foreign import capi unsafe "sys/time.h gettimeofday" gettimeofday :: Ptr CTimeval -> Ptr () -> IO CInt
 
 -- | Get the current POSIX time from the system clock.
 getCTimeval :: IO CTimeval
