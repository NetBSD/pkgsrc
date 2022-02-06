$NetBSD: patch-libraries_unix_System_Posix_Files_Common.hsc,v 1.1 2022/02/06 05:36:16 pho Exp $

Suppress linker warnings about compatibility syscall wrappers by using
"capi" instead of "ccall".

--- libraries/unix/System/Posix/Files/Common.hsc.orig	2016-04-20 10:08:26.000000000 +0000
+++ libraries/unix/System/Posix/Files/Common.hsc
@@ -1,4 +1,5 @@
 {-# LANGUAGE Trustworthy #-}
+{-# LANGUAGE CApiFFI #-}
 
 -----------------------------------------------------------------------------
 -- |
@@ -448,16 +449,16 @@ toCTimeVal t = CTimeVal sec (truncate $ 
     (sec, frac) = if (frac' < 0) then (sec' - 1, frac' + 1) else (sec', frac')
     (sec', frac') = properFraction $ toRational t
 
-foreign import ccall unsafe "utimes"
+foreign import capi unsafe "sys/time.h utimes"
     c_utimes :: CString -> Ptr CTimeVal -> IO CInt
 
 #ifdef HAVE_LUTIMES
-foreign import ccall unsafe "lutimes"
+foreign import capi unsafe "sys/time.h lutimes"
     c_lutimes :: CString -> Ptr CTimeVal -> IO CInt
 #endif
 
 #if HAVE_FUTIMES
-foreign import ccall unsafe "futimes"
+foreign import capi unsafe "sys/time.h futimes"
     c_futimes :: CInt -> Ptr CTimeVal -> IO CInt
 #endif
 
