$NetBSD: patch-Source_Core_Common_MemoryUtil.cpp,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Common/MemoryUtil.cpp.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Common/MemoryUtil.cpp
@@ -19,7 +19,7 @@
 #include <stdio.h>
 #include <sys/mman.h>
 #include <sys/types.h>
-#if defined __APPLE__ || defined __FreeBSD__ || defined __OpenBSD__
+#if defined __APPLE__ || defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
 #include <sys/sysctl.h>
 #elif defined __HAIKU__
 #include <OS.h>
@@ -156,7 +156,7 @@ size_t MemPhysical()
   memInfo.dwLength = sizeof(MEMORYSTATUSEX);
   GlobalMemoryStatusEx(&memInfo);
   return memInfo.ullTotalPhys;
-#elif defined __APPLE__ || defined __FreeBSD__ || defined __OpenBSD__
+#elif defined __APPLE__ || defined __FreeBSD__ || defined __NetBSD__ || defined __OpenBSD__
   int mib[2];
   size_t physical_memory;
   mib[0] = CTL_HW;
@@ -164,7 +164,7 @@ size_t MemPhysical()
   mib[1] = HW_MEMSIZE;
 #elif defined __FreeBSD__
   mib[1] = HW_REALMEM;
-#elif defined __OpenBSD__
+#elif defined __NetBSD__ || defined __OpenBSD__
   mib[1] = HW_PHYSMEM;
 #endif
   size_t length = sizeof(size_t);
