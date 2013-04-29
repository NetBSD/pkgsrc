$NetBSD: patch-base_cpu__stats.cc,v 1.1 2013/04/29 09:52:16 ryoon Exp $

--- base/cpu_stats.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/cpu_stats.cc
@@ -123,13 +123,13 @@ float CPUStats::GetSystemCPULoad() {
 
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // NOT IMPLEMENTED
   // TODO(taku): implement Linux version
   // can take the info from /proc/stats
   const uint64 total_times = 0;
   const uint64 cpu_times = 0;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   return UpdateCPULoad(total_times,
                        cpu_times,
@@ -178,11 +178,11 @@ float CPUStats::GetCurrentProcessCPULoad
       TimeValueTToInt64(task_times_info.system_time);
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // not implemented
   const uint64 total_times = 0;
   const uint64 cpu_times = 0;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
   return UpdateCPULoad(total_times,
                        cpu_times,
@@ -210,9 +210,9 @@ size_t CPUStats::GetNumberOfProcessors()
   return static_cast<size_t>(basic_info.avail_cpus);
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Not implemented
   return 1;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 }
 }  // namespace mozc
