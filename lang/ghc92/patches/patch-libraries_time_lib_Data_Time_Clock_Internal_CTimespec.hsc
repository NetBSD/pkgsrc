$NetBSD: patch-libraries_time_lib_Data_Time_Clock_Internal_CTimespec.hsc,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility symbols.

--- libraries/time/lib/Data/Time/Clock/Internal/CTimespec.hsc.orig	2020-01-04 02:21:30.506303962 +0000
+++ libraries/time/lib/Data/Time/Clock/Internal/CTimespec.hsc
@@ -1,3 +1,4 @@
+{-# LANGUAGE CApiFFI #-}
 module Data.Time.Clock.Internal.CTimespec where
 
 #include "HsTimeConfig.h"
@@ -29,9 +30,9 @@ instance Storable CTimespec where
         #{poke struct timespec, tv_sec } p s
         #{poke struct timespec, tv_nsec} p ns
 
-foreign import ccall unsafe "time.h clock_gettime"
+foreign import capi unsafe "time.h clock_gettime"
     clock_gettime :: ClockID -> Ptr CTimespec -> IO CInt
-foreign import ccall unsafe "time.h clock_getres"
+foreign import capi unsafe "time.h clock_getres"
     clock_getres :: ClockID -> Ptr CTimespec -> IO CInt
 
 -- | Get the resolution of the given clock.
