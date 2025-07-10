$NetBSD: patch-libraries_haskeline_System_Console_Haskeline_Backend_Posix.hsc,v 1.1 2025/07/10 14:07:33 jperkin Exp $

Correct include for ioctl() on illumos.

--- libraries/haskeline/System/Console/Haskeline/Backend/Posix.hsc.orig	2024-05-10 05:07:46.000000000 +0000
+++ libraries/haskeline/System/Console/Haskeline/Backend/Posix.hsc
@@ -69,7 +69,11 @@ ehOut = eH . hOut
 posixLayouts :: Handles -> [IO (Maybe Layout)]
 posixLayouts _ = error "System.Console.Haskeline.Backend.Posix.posixLayouts"
 #else
+#if defined(__illumos__)
+foreign import capi "stropts.h ioctl" ioctl :: FD -> CULong -> Ptr a -> IO CInt
+#else
 foreign import capi "sys/ioctl.h ioctl" ioctl :: FD -> CULong -> Ptr a -> IO CInt
+#endif
 
 posixLayouts :: Handles -> [IO (Maybe Layout)]
 posixLayouts h = [ioctlLayout $ ehOut h, envLayout]
