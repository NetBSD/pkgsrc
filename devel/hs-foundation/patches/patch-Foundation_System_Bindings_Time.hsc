$NetBSD: patch-Foundation_System_Bindings_Time.hsc,v 1.1 2021/05/05 16:38:40 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall".

--- Foundation/System/Bindings/Time.hsc.orig	2021-05-05 16:28:40.081345013 +0000
+++ Foundation/System/Bindings/Time.hsc
@@ -3,6 +3,7 @@
 -- Maintainer  :  Haskell foundation
 --
 
+{-# LANGUAGE CApiFFI #-}
 module Foundation.System.Bindings.Time where
 
 import Basement.Compat.Base
@@ -116,11 +117,11 @@ foreign import ccall unsafe "foundation_
 foreign import ccall unsafe "foundation_time_clock_gettime"
     sysTimeClockGetTime :: CClockId -> Ptr CTimeSpec -> IO CInt
 #else
-foreign import ccall unsafe "clock_getres"
+foreign import capi unsafe "time.h clock_getres"
     sysTimeClockGetRes :: CClockId -> Ptr CTimeSpec -> IO CInt
-foreign import ccall unsafe "clock_gettime"
+foreign import capi unsafe "time.h clock_gettime"
     sysTimeClockGetTime :: CClockId -> Ptr CTimeSpec -> IO CInt
 #endif
 
-foreign import ccall unsafe "gettimeofday"
+foreign import capi unsafe "sys/time.h gettimeofday"
     sysTimeGetTimeOfDay :: Ptr CTimeVal -> Ptr CTimeZone -> IO CInt
