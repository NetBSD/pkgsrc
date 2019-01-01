$NetBSD: patch-Source_Core_VideoCommon_DriverDetails.cpp,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/VideoCommon/DriverDetails.cpp.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/VideoCommon/DriverDetails.cpp
@@ -32,6 +32,8 @@ namespace DriverDetails
 	const u32 m_os = OS_ALL | OS_LINUX;
 #elif __FreeBSD__
 	const u32 m_os = OS_ALL | OS_FREEBSD;
+#elif __NetBSD__
+	const u32 m_os = OS_ALL | OS_NETBSD;
 #endif
 
 	static Vendor m_vendor = VENDOR_UNKNOWN;
