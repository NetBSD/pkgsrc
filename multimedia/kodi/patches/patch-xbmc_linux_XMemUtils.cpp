$NetBSD: patch-xbmc_linux_XMemUtils.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

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
 
@@ -139,6 +143,31 @@ void GlobalMemoryStatusEx(LPMEMORYSTATUS
 
   if (sysctlbyname("vm.stats.vm.v_swappgsout", &swap_free, &len, NULL, 0) == 0)
     lpBuffer->ullAvailPageFile = swap_free * pagesize;
+#elif defined(TARGET_NETBSD)
+  struct uvmexp_sysctl uvmexp;
+  int64_t physmem = 0, mem_inactive = 0, mem_cache = 0, mem_free = 0;
+  int pagesize;
+  size_t len;
+
+  /* sysctl hw.physmem64 */
+  len = sizeof(physmem);
+  if (sysctlbyname("hw.physmem64", &physmem, &len, NULL, 0) == 0) {
+    lpBuffer->ullTotalPhys = physmem;
+    lpBuffer->ullTotalVirtual = physmem;
+  }
+
+  /* sysctl vm.uvmexp2 */
+  len = sizeof(uvmexp);
+  if (sysctlbyname("vm.uvmexp2", &uvmexp, &len, NULL, 0) == 0) {
+    pagesize = getpagesize();
+    mem_inactive = uvmexp.inactive * pagesize;
+    mem_cache = uvmexp.filepages * pagesize;
+    mem_free = uvmexp.free * pagesize;
+    lpBuffer->ullAvailPhys = mem_inactive + mem_cache + mem_free;
+    lpBuffer->ullAvailVirtual = mem_inactive + mem_cache + mem_free;
+  }
+
+  /* TODO: lpBuffer->ullAvailPageFile */
 #else
   struct sysinfo info;
   char name[32];
