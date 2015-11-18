$NetBSD: patch-xbmc_linux_XMemUtils.cpp,v 1.2 2015/11/18 23:27:23 jmcneill Exp $

--- xbmc/linux/XMemUtils.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/linux/XMemUtils.cpp
@@ -29,6 +29,10 @@
 #include <mach/mach.h>
 #endif
 
+#if defined(TARGET_NETBSD)
+#include <uvm/uvm_extern.h>
+#endif
+
 #undef ALIGN
 #define ALIGN(value, alignment) (((value)+(alignment-1))&~(alignment-1))
 
@@ -55,7 +59,7 @@ void _aligned_free(void *p) {
 
 #ifndef TARGET_WINDOWS
 
-#if defined(TARGET_POSIX) && !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD)
+#if defined(TARGET_POSIX) && !defined(TARGET_DARWIN) && !defined(TARGET_FREEBSD) && !defined(TARGET_NETBSD)
 static FILE* procMeminfoFP = NULL;
 #endif
 
@@ -139,6 +143,29 @@ void GlobalMemoryStatusEx(LPMEMORYSTATUS
 
   if (sysctlbyname("vm.stats.vm.v_swappgsout", &swap_free, &len, NULL, 0) == 0)
     lpBuffer->ullAvailPageFile = swap_free * pagesize;
+#elif defined(TARGET_NETBSD)
+  struct uvmexp_sysctl uvmexp;
+  int64_t filemin = 0;
+  int filemin_pct;
+  size_t len;
+
+  /* sysctl vm.filemin */
+  len = sizeof(filemin_pct);
+  if (sysctlbyname("vm.filemin", &filemin_pct, &len, NULL, 0) == 0)
+  {
+    /* sysctl vm.uvmexp2 */
+    len = sizeof(uvmexp);
+    if (sysctlbyname("vm.uvmexp2", &uvmexp, &len, NULL, 0) == 0)
+    {
+      lpBuffer->ullTotalPhys = (uvmexp.active + uvmexp.inactive + uvmexp.free) * uvmexp.pagesize;
+      lpBuffer->ullTotalVirtual = (uvmexp.active + uvmexp.inactive + uvmexp.free) * uvmexp.pagesize;
+      filemin = MIN(uvmexp.filepages, ((uvmexp.active + uvmexp.inactive + uvmexp.free) * filemin_pct) / 100);
+      lpBuffer->ullAvailPhys = (uvmexp.free + uvmexp.filepages - filemin) * uvmexp.pagesize;
+      lpBuffer->ullAvailVirtual = (uvmexp.free + uvmexp.filepages - filemin) * uvmexp.pagesize;
+      lpBuffer->ullAvailPageFile = (uvmexp.swpages - uvmexp.swpginuse) * uvmexp.pagesize;
+    }
+  }
+
 #else
   struct sysinfo info;
   char name[32];
