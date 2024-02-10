$NetBSD: patch-base_cpu__stats.cc,v 1.2 2024/02/10 12:26:01 ryoon Exp $

--- base/cpu_stats.cc.orig	2023-10-26 12:00:50.000000000 +0000
+++ base/cpu_stats.cc
@@ -116,7 +116,7 @@ float CPUStats::GetSystemCPULoad() {
 
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
   // NOT IMPLEMENTED
   // TODO(taku): implement Linux version
   // can take the info from /proc/stats
@@ -169,7 +169,7 @@ float CPUStats::GetCurrentProcessCPULoad
                              TimeValueTToInt64(task_times_info.system_time);
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
   // not implemented
   const uint64_t total_times = 0;
   const uint64_t cpu_times = 0;
@@ -200,7 +200,7 @@ size_t CPUStats::GetNumberOfProcessors()
   return static_cast<size_t>(basic_info.avail_cpus);
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
   // Not implemented
   return 1;
 #endif  // __linux__ || __wasm__
