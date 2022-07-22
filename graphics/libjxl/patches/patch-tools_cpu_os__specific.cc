$NetBSD: patch-tools_cpu_os__specific.cc,v 1.1 2022/07/22 20:17:14 wiz Exp $

* add NetBSD support

--- tools/cpu/os_specific.cc.orig	2021-10-04 18:02:44.000000000 +0000
+++ tools/cpu/os_specific.cc
@@ -59,6 +59,15 @@
 #include <OS.h>
 #endif  // JXL_OS_HAIKU
 
+#if JXL_OS_NETBSD
+#include <pthread.h>
+#include <sched.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <unistd.h>
+#endif //JXL_OS_NETBSD
+
 using jxl::Status;
 
 namespace jpegxl {
@@ -82,10 +91,14 @@ static inline void CPU_SET(int cpu, cpu_
 #endif
 
 struct ThreadAffinity {
+#if JXL_OS_NETBSD
+  cpuset_t *set;
+#else
   cpu_set_t set;
+#endif
 };
 
-#if JXL_OS_MAC
+#if JXL_OS_MAC || JXL_OS_NETBSD 
 namespace {
 Status GetSystemValue(const char* name, size_t* value) {
   int64_t value_i64 = 0;
@@ -96,7 +109,9 @@ Status GetSystemValue(const char* name, 
   *value = static_cast<size_t>(value_i64);
   return true;
 }
-
+} // namespace
+#endif
+#if JXL_OS_MAC
 // Returns mask with the lowest N bits set, one per logical processor.
 cpu_set_t SetOfAllLogicalProcessors() {
   size_t logical;
@@ -153,7 +168,14 @@ Status GetProcessorTopologyFromOS(Proces
   pt->logical_per_core = 1;
 
   return true;
+#elif JXL_OS_NETBSD
+  size_t cores;
+  JXL_RETURN_IF_ERROR(GetSystemValue("hw.ncpuonline", &cores));
+  pt->packages = 1;
+  pt->cores_per_package = cores;
+  pt->logical_per_core = 1;
 
+  return true;
 #else
   // Not needed on X64 if the affinity APIs work (DetectProcessorTopology will
   // succeed)
@@ -164,6 +186,19 @@ Status GetProcessorTopologyFromOS(Proces
 ThreadAffinity* GetThreadAffinity() {
   ThreadAffinity* affinity =
       static_cast<ThreadAffinity*>(malloc(sizeof(ThreadAffinity)));
+#if JXL_OS_NETBSD
+  if (affinity != NULL) {
+    affinity->set = cpuset_create();
+    if (affinity->set == NULL) {
+      free(affinity);
+      affinity = NULL;
+    } else {
+      cpuset_zero(affinity->set);
+      const int err = pthread_getaffinity_np(pthread_self(), cpuset_size(affinity->set), affinity->set);
+      JXL_CHECK(err == 0);
+    }
+  }
+#endif
 #if JXL_OS_WIN
   DWORD_PTR process_affinity, system_affinity;
   const BOOL ok = GetProcessAffinityMask(GetCurrentProcess(), &process_affinity,
@@ -195,6 +230,19 @@ ThreadAffinity* OriginalThreadAffinity()
 
 }  // namespace
 
+#if JXL_OS_NETBSD
+bool set_affinity_allowed()
+{
+  if (geteuid() == 0)
+    return true;
+
+  size_t len = 4;
+  int *val =(int*)asysctlbyname("security.models.extensions.user_set_cpu_affinity", &len);
+
+  return (*val == 1);
+}
+#endif
+
 Status SetThreadAffinity(ThreadAffinity* affinity) {
   // Ensure original is initialized before changing.
   const ThreadAffinity* const original = OriginalThreadAffinity();
@@ -224,6 +272,14 @@ Status SetThreadAffinity(ThreadAffinity*
   // As of 2020-06 Haiku does not support pinning threads to cores.
   (void)affinity;
   return false;
+#elif JXL_OS_NETBSD
+  if (!set_affinity_allowed()) 
+     return false;
+
+  const int err = pthread_setaffinity_np(pthread_self(), cpuset_size(affinity->set),
+                                        affinity->set);
+  if (err != 0) return JXL_FAILURE("cpuset_setaffinity_np failed");
+  return true;  
 #else
   printf("Don't know how to SetThreadAffinity on this platform.\n");
   return false;
@@ -255,6 +311,16 @@ Status PinThreadToCPU(const int cpu) {
   CPU_ZERO(&affinity.set);
   CPU_SET(cpu, &affinity.set);
   return SetThreadAffinity(&affinity);
+#elif JXL_OS_NETBSD
+  ThreadAffinity affinity;
+  affinity.set = cpuset_create();
+  if (affinity.set == nullptr)
+    return false;
+  cpuset_zero(affinity.set);
+  cpuset_set(cpu, affinity.set);
+  bool st = SetThreadAffinity(&affinity);
+  cpuset_destroy(affinity.set);
+  return st;
 #else
   return false;
 #endif
@@ -280,7 +346,7 @@ Status PinThreadToRandomCPU() {
 namespace {
 
 size_t DetectTotalMemoryMiB() {
-#if JXL_OS_LINUX || JXL_OS_FREEBSD || JXL_OS_MAC
+#if JXL_OS_LINUX || JXL_OS_FREEBSD || JXL_OS_MAC || JXL_OS_NETBSD
   const long page_size = sysconf(_SC_PAGESIZE);
   const long num_pages = sysconf(_SC_PHYS_PAGES);
   if (page_size == -1 || num_pages == -1) {
