$NetBSD: patch-libraries_base_System_CPUTime_Posix_Times.hsc,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall".

--- libraries/base/System/CPUTime/Posix/Times.hsc.orig	2020-01-04 12:08:39.515726533 +0000
+++ libraries/base/System/CPUTime/Posix/Times.hsc
@@ -27,7 +27,7 @@ getCPUTime = allocaBytes (#const sizeof(
                         `div` fromIntegral clockTicks)
 
 type CTms = ()
-foreign import ccall unsafe times :: Ptr CTms -> IO CClock
+foreign import capi unsafe "sys/times.h times" times :: Ptr CTms -> IO CClock
 
 getCpuTimePrecision :: IO Integer
 getCpuTimePrecision =
