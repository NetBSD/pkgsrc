$NetBSD: patch-ipc_chromium_src_base_sys__info__posix.cc,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/ipc/chromium/src/base/sys_info_posix.cc.orig	2012-08-25 00:31:11.000000000 +0000
+++ mozilla/ipc/chromium/src/base/sys_info_posix.cc
@@ -18,6 +18,11 @@
 #include <mach/mach_init.h>
 #endif
 
+#if defined(OS_NETBSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
+
 #include "base/logging.h"
 #include "base/string_util.h"
 
@@ -26,7 +31,11 @@ namespace base {
 int SysInfo::NumberOfProcessors() {
   // It seems that sysconf returns the number of "logical" processors on both
   // mac and linux.  So we get the number of "online logical" processors.
+#ifdef _SC_NPROCESSORS_ONLN
   static long res = sysconf(_SC_NPROCESSORS_ONLN);
+#else
+  static long res = 1;
+#endif
   if (res == -1) {
     NOTREACHED();
     return 1;
@@ -52,6 +61,20 @@ int64 SysInfo::AmountOfPhysicalMemory() 
   }
 
   return static_cast<int64>(hostinfo.max_mem);
+#elif defined(OS_NETBSD)
+  int mib[2];
+  int rc;
+  int64_t memSize;
+  size_t len = sizeof(memSize);
+
+  mib[0] = CTL_HW;
+  mib[1] = HW_PHYSMEM64;
+  rc = sysctl( mib, 2, &memSize, &len, NULL, 0 );
+  if (-1 != rc)  {
+    return memSize;
+  }
+  return 0;
+
 #else
   long pages = sysconf(_SC_PHYS_PAGES);
   long page_size = sysconf(_SC_PAGE_SIZE);
