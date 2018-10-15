$NetBSD: patch-Source_Core_VideoCommon_DriverDetails.cpp,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/VideoCommon/DriverDetails.cpp.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/VideoCommon/DriverDetails.cpp
@@ -33,6 +33,8 @@ const u32 m_os = OS_ALL | OS_OSX;
 const u32 m_os = OS_ALL | OS_LINUX;
 #elif __FreeBSD__
 const u32 m_os = OS_ALL | OS_FREEBSD;
+#elif __NetBSD__
+const u32 m_os = OS_ALL | OS_NETBSD;
 #elif __OpenBSD__
 const u32 m_os = OS_ALL | OS_OPENBSD;
 #elif __HAIKU__
