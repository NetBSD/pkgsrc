$NetBSD: patch-libraries_base_src_System_CPUTime_Posix_Times.hsc,v 1.1 2025/01/29 13:21:53 pho Exp $

Use the correct symbol by going through the C header as opposed to directly
referencing a symbol in libc.

--- libraries/base/src/System/CPUTime/Posix/Times.hsc.orig	2025-01-09 08:51:54.813962596 +0000
+++ libraries/base/src/System/CPUTime/Posix/Times.hsc
@@ -30,7 +30,7 @@ getCPUTime = allocaBytes (#const sizeof(
                         `div` fromIntegral clockTicks)
 
 type CTms = ()
-foreign import ccall unsafe times :: Ptr CTms -> IO CClock
+foreign import capi unsafe "sys/times.h times" times :: Ptr CTms -> IO CClock
 
 getCpuTimePrecision :: IO Integer
 getCpuTimePrecision =
