$NetBSD: patch-sql_resourcegroups_platform_thread__attrs__api__apple.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

* support getting the cpu count on netbsd, openbsd and irix

--- sql/resourcegroups/platform/thread_attrs_api_apple.cc.orig	2021-03-22 08:44:50.000000000 +0000
+++ sql/resourcegroups/platform/thread_attrs_api_apple.cc
@@ -84,14 +84,28 @@ bool set_thread_priority(int, my_thread_
 
 uint32_t num_vcpus_using_affinity() { return 0; }
 
+
+#ifdef IRIX5
+#include <sys/sysmp.h>
+
+uint32_t num_vcpus_using_config() {
+  return sysmp(MP_NAPROCS);
+}
+#else
+
 uint32_t num_vcpus_using_config() {
+#ifdef HW_AVAILCPU
   int name[2] = {CTL_HW, HW_AVAILCPU};
+#else
+  int name[2] = {CTL_HW, HW_NCPUONLINE};
+#endif
   int ncpu;
 
   size_t size = sizeof(ncpu);
   sysctl(name, 2, &ncpu, &size, nullptr, 0);
   return ncpu;
 }
+#endif
 
 bool can_thread_priority_be_set() {
   assert(0);
