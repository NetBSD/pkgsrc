$NetBSD: patch-Source_Core_VideoCommon_DriverDetails.h,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/VideoCommon/DriverDetails.h.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/VideoCommon/DriverDetails.h
@@ -17,6 +17,7 @@ namespace DriverDetails
 		OS_OSX     = (1 << 3),
 		OS_ANDROID = (1 << 4),
 		OS_FREEBSD = (1 << 5),
+		OS_NETBSD  = (1 << 6),
 	};
 	// Enum of known vendors
 	// Tegra and Nvidia are separated out due to such substantial differences
