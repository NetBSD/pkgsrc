$NetBSD: patch-Source_Core_VideoCommon_DriverDetails.h,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/VideoCommon/DriverDetails.h.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/VideoCommon/DriverDetails.h
@@ -28,6 +28,7 @@ enum OS
   OS_FREEBSD = (1 << 5),
   OS_OPENBSD = (1 << 6),
   OS_HAIKU = (1 << 7),
+  OS_NETBSD = (1 << 8),
 };
 // Enum of known vendors
 // Tegra and Nvidia are separated out due to such substantial differences
