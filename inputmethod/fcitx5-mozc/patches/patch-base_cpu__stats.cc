$NetBSD: patch-base_cpu__stats.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- base/cpu_stats.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ base/cpu_stats.cc
@@ -122,13 +122,13 @@ float CPUStats::GetSystemCPULoad() {
 
 #endif  // __APPLE__
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
   // NOT IMPLEMENTED
   // TODO(taku): implement Linux version
   // can take the info from /proc/stats
   const uint64 total_times = 0;
   const uint64 cpu_times = 0;
-#endif  // OS_LINUX || OS_ANDROID || OS_WASM
+#endif  // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
 
   return UpdateCPULoad(total_times, cpu_times, &prev_system_total_times_,
                        &prev_system_cpu_times_);
@@ -175,11 +175,11 @@ float CPUStats::GetCurrentProcessCPULoad
                            TimeValueTToInt64(task_times_info.system_time);
 #endif  // __APPLE__
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
   // not implemented
   const uint64 total_times = 0;
   const uint64 cpu_times = 0;
-#endif  // OS_LINUX || OS_ANDROID || OS_WASM
+#endif  // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
 
   return UpdateCPULoad(total_times, cpu_times,
                        &prev_current_process_total_times_,
@@ -206,9 +206,9 @@ size_t CPUStats::GetNumberOfProcessors()
   return static_cast<size_t>(basic_info.avail_cpus);
 #endif  // __APPLE__
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
   // Not implemented
   return 1;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
 }
 }  // namespace mozc
