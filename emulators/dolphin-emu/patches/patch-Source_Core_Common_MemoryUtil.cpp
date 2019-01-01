$NetBSD: patch-Source_Core_Common_MemoryUtil.cpp,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/Common/MemoryUtil.cpp.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Common/MemoryUtil.cpp
@@ -20,7 +20,7 @@
 #include <stdio.h>
 #include <sys/mman.h>
 #include <sys/types.h>
-#if defined __APPLE__ || defined __FreeBSD__
+#if defined __APPLE__ || defined __FreeBSD__ || defined __NetBSD__
 #include <sys/sysctl.h>
 #else
 #include <sys/sysinfo.h>
@@ -249,7 +249,7 @@ size_t MemPhysical()
 	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
 	GlobalMemoryStatusEx(&memInfo);
 	return memInfo.ullTotalPhys;
-#elif defined __APPLE__ || defined __FreeBSD__
+#elif defined __APPLE__ || defined __FreeBSD__ || defined __NetBSD__
 	int mib[2];
 	size_t physical_memory;
 	mib[0] = CTL_HW;
@@ -257,6 +257,8 @@ size_t MemPhysical()
 	mib[1] = HW_MEMSIZE;
 #elif defined __FreeBSD__
 	mib[1] = HW_REALMEM;
+#elif defined __NetBSD__
+	mib[1] = HW_PHYSMEM;
 #endif
 	size_t length = sizeof(size_t);
 	sysctl(mib, 2, &physical_memory, &length, NULL, 0);
