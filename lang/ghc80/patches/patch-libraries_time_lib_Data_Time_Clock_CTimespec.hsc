$NetBSD: patch-libraries_time_lib_Data_Time_Clock_CTimespec.hsc,v 1.1 2020/01/03 15:24:08 pho Exp $

Suppress linker warnings about compatibility symbols.

--- libraries/time/lib/Data/Time/Clock/CTimespec.hsc.orig	2020-01-03 10:48:43.269574197 +0000
+++ libraries/time/lib/Data/Time/Clock/CTimespec.hsc
@@ -1,4 +1,5 @@
 -- #hide
+{-# LANGUAGE CApiFFI #-}
 module Data.Time.Clock.CTimespec where
 
 #include "HsTimeConfig.h"
@@ -27,7 +28,7 @@ instance Storable CTimespec where
         #{poke struct timespec, tv_sec } p s
         #{poke struct timespec, tv_nsec} p ns
 
-foreign import ccall unsafe "time.h clock_gettime"
+foreign import capi unsafe "time.h clock_gettime"
     clock_gettime :: #{type clockid_t} -> Ptr CTimespec -> IO CInt
 
 -- | Get the current POSIX time from the system clock.
