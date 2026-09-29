$NetBSD: patch-thirdparty_thread-pool_bs__thread__pool.hpp,v 1.1 2026/09/29 16:11:57 bouyer Exp $

Add NetBSD support.

--- thirdparty/thread-pool/bs_thread_pool.hpp.orig	2026-07-21 19:13:55.000000000 +0000
+++ thirdparty/thread-pool/bs_thread_pool.hpp
@@ -82,7 +82,7 @@ import std;
         #include <windows.h>
         #undef min
         #undef max
-    #elif defined(__linux__) || defined(__APPLE__)
+    #elif defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
         #include <pthread.h>
         #include <sched.h>
         #include <sys/resource.h>
@@ -90,13 +90,15 @@ import std;
         #if defined(__linux__)
             #include <sys/syscall.h>
             #include <sys/sysinfo.h>
+        #elif defined(__NetBSD__)
+            #include <sys/syscall.h>
         #endif
     #else
         #undef BS_THREAD_POOL_NATIVE_EXTENSIONS
     #endif
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
     // On Linux, <sys/sysmacros.h> defines macros called `major` and `minor`. We undefine them here so the `version` struct can work.
     #ifdef major
         #undef major
@@ -577,7 +579,7 @@ enum class os_thread_priority
     highest = THREAD_PRIORITY_HIGHEST,
     realtime = THREAD_PRIORITY_TIME_CRITICAL
 };
-    #elif defined(__linux__) || defined(__APPLE__)
+    #elif defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
 /**
  * @brief An enum containing pre-defined OS-specific process priority values for portability.
  */
@@ -645,6 +647,25 @@ enum class os_thread_priority
     for (std::size_t i = 0; i < affinity.size(); ++i)
         affinity[i] = CPU_ISSET(i, &cpu_set);
     return affinity;
+    #elif defined(__NetBSD__)
+    cpuset_t *cpuset = cpuset_create();
+    cpuset_zero(cpuset);
+    if (sched_getaffinity_np(getpid(), cpuset_size(cpuset), cpuset) != 0)
+    {
+        cpuset_destroy(cpuset);
+        return std::nullopt;
+    }
+    const long num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
+    if (num_cpus < 1)
+    {
+        cpuset_destroy(cpuset);
+        return std::nullopt;
+    }
+    std::vector<bool> affinity(static_cast<std::size_t>(num_cpus));
+    for (std::size_t i = 0; i < affinity.size(); ++i)
+        affinity[i] = cpuset_isset(i, cpuset);
+    cpuset_destroy(cpuset);
+    return affinity;
     #elif defined(__APPLE__)
     return std::nullopt;
     #endif
@@ -672,6 +693,15 @@ inline bool set_os_process_affinity(const std::vector<
             CPU_SET(i, &cpu_set);
     }
     return sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpu_set) == 0;
+    #elif defined(__NetBSD__)
+    cpuset_t *cpuset = cpuset_create();
+    cpuset_zero(cpuset);
+    for (std::size_t i = 0; i < std::min<std::size_t>(affinity.size(), cpuset_size(cpuset)); ++i)
+    {
+        if (affinity[i])
+            cpuset_set(i, cpuset);
+    }
+    return sched_setaffinity_np(getpid(), cpuset_size(cpuset), cpuset) == 0;
     #elif defined(__APPLE__)
     return affinity[0] && false; // NOLINT(readability-simplify-boolean-expr) // Using `affinity` to suppress unused parameter warning.
     #endif
@@ -690,7 +720,7 @@ inline bool set_os_process_affinity(const std::vector<
     if (priority == 0)
         return std::nullopt;
     return static_cast<os_process_priority>(priority);
-    #elif defined(__linux__) || defined(__APPLE__)
+    #elif defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
     // On Linux/macOS there is no direct analogue of `GetPriorityClass()` on Windows, so instead we get the "nice" value. The usual range is -20 to 19 or 20, with higher values corresponding to lower priorities. However, we are only using 6 pre-defined values for portability, so if the value was set via any means other than `BS::set_os_process_priority()`, it may not match one of our pre-defined values. Note that `getpriority()` returns -1 on error, but since this does not correspond to any of our pre-defined values, this function will return `std::nullopt` anyway.
     const int nice_val = getpriority(PRIO_PROCESS, static_cast<id_t>(getpid()));
     switch (nice_val)
@@ -724,7 +754,7 @@ inline bool set_os_process_priority(const os_process_p
     #if defined(_WIN32)
     // On Windows, this is straightforward.
     return SetPriorityClass(GetCurrentProcess(), static_cast<DWORD>(priority)) != 0;
-    #elif defined(__linux__) || defined(__APPLE__)
+    #elif defined(__linux__) || defined(__APPLE__) || defined(__NetBSD__)
     // On Linux/macOS there is no direct analogue of `SetPriorityClass()` on Windows, so instead we set the "nice" value. The usual range is -20 to 19 or 20, with higher values corresponding to lower priorities. However, we are only using 6 pre-defined values for portability. Note that the "nice" values are only relevant for the `SCHED_OTHER` policy, but we do not set that policy here, as it is per-thread rather than per-process.
     // Also, it's important to note that a non-root user cannot decrease the nice value (i.e. increase the process priority), only increase it. This can cause confusing behavior. For example, if the current priority is `BS::os_process_priority::normal` and the user sets it to `BS::os_process_priority::idle`, they cannot change it back `BS::os_process_priority::normal`.
     return setpriority(PRIO_PROCESS, static_cast<id_t>(getpid()), static_cast<int>(priority)) == 0;
@@ -806,6 +836,25 @@ class [[nodiscard]] this_thread (public)
         for (std::size_t i = 0; i < affinity.size(); ++i)
             affinity[i] = CPU_ISSET(i, &cpu_set);
         return affinity;
+    #elif defined(__NetBSD__)
+	cpuset_t *cpuset = cpuset_create();;
+	cpuset_zero(cpuset);
+	if (pthread_getaffinity_np(pthread_self(), cpuset_size(cpuset), cpuset) != 0)
+        {
+            cpuset_destroy(cpuset);
+            return std::nullopt;
+        }
+        const long num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
+        if (num_cpus < 1)
+        {
+            cpuset_destroy(cpuset);
+            return std::nullopt;
+        }
+        std::vector<bool> affinity(static_cast<std::size_t>(num_cpus));
+        for (std::size_t i = 0; i < affinity.size(); ++i)
+            affinity[i] = cpuset_isset(i, cpuset);
+	cpuset_destroy(cpuset);
+        return affinity;
     #elif defined(__APPLE__)
         return std::nullopt;
     #endif
@@ -833,6 +882,17 @@ class [[nodiscard]] this_thread (public)
                 CPU_SET(i, &cpu_set);
         }
         return pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpu_set) == 0;
+    #elif defined(__NetBSD__)
+        cpuset_t *cpuset = cpuset_create();
+        cpuset_zero(cpuset);
+        for (std::size_t i = 0; i < std::min<std::size_t>(affinity.size(), cpuset_size(cpuset)); ++i)
+        {
+            if (affinity[i])
+                cpuset_set(i, cpuset);
+        }
+	bool rc = pthread_setaffinity_np(pthread_self(), cpuset_size(cpuset), cpuset) == 0;
+	cpuset_destroy(cpuset);
+        return rc;
     #elif defined(__APPLE__)
         return affinity[0] && false; // NOLINT(readability-simplify-boolean-expr) // Using `affinity` to suppress unused parameter warning.
     #endif
@@ -865,10 +925,12 @@ class [[nodiscard]] this_thread (public)
         if (result == 0)
             return std::nullopt;
         return name;
-    #elif defined(__linux__) || defined(__APPLE__)
+#elif defined(__linux__) || defined(__NetBSD__) || defined(__APPLE__)
         #ifdef __linux__
         // On Linux thread names are limited to 16 characters, including the null terminator.
         constexpr std::size_t buffer_size = 16;
+	#elif __NetBSD__
+        constexpr std::size_t buffer_size = PTHREAD_MAX_NAMELEN_NP;
         #else
         // On macOS thread names are limited to 64 characters, including the null terminator.
         constexpr std::size_t buffer_size = 64;
@@ -901,6 +963,8 @@ class [[nodiscard]] this_thread (public)
     #elif defined(__linux__)
         // On Linux this is straightforward.
         return pthread_setname_np(pthread_self(), name.data()) == 0;
+    #elif defined(__NetBSD__)
+        return pthread_setname_np(pthread_self(), "%s", (void*)name.data()) == 0;
     #elif defined(__APPLE__)
         // On macOS, unlike Linux, a thread can only set a name for itself, so the signature is different.
         return pthread_setname_np(name.data()) == 0;
@@ -920,7 +984,7 @@ class [[nodiscard]] this_thread (public)
         if (priority == THREAD_PRIORITY_ERROR_RETURN)
             return std::nullopt;
         return static_cast<os_thread_priority>(priority);
-    #elif defined(__linux__)
+    #elif defined(__linux__) || defined(__NetBSD__)
         // On Linux, we distill the choices of scheduling policy, priority, and "nice" value into 7 pre-defined levels, for simplicity and portability. The total number of possible combinations of policies and priorities is much larger, so if the value was set via any means other than `BS::this_thread::set_os_thread_priority()`, it may not match one of our pre-defined values.
         int policy = 0;
         struct sched_param param = {};
@@ -946,7 +1010,11 @@ class [[nodiscard]] this_thread (public)
         if (policy == SCHED_OTHER)
         {
             // For SCHED_OTHER, the result depends on the "nice" value. The usual range is -20 to 19 or 20, with higher values corresponding to lower priorities. Note that `getpriority()` returns -1 on error, but since this does not correspond to any of our pre-defined values, this function will return `std::nullopt` anyway.
+        #ifdef __NetBSD__
+            const int nice_val = getpriority(PRIO_PROCESS, static_cast<id_t>(syscall(SYS__lwp_self)));
+        #else
             const int nice_val = getpriority(PRIO_PROCESS, static_cast<id_t>(syscall(SYS_gettid)));
+        #endif
             switch (nice_val)
             {
             case PRIO_MIN + 2:
@@ -1013,7 +1081,7 @@ class [[nodiscard]] this_thread (public)
     #if defined(_WIN32)
         // On Windows, this is straightforward.
         return SetThreadPriority(GetCurrentThread(), static_cast<int>(priority)) != 0;
-    #elif defined(__linux__)
+    #elif defined(__linux__) || defined(__NetBSD__)
         // On Linux, we distill the choices of scheduling policy, priority, and "nice" value into 7 pre-defined levels, for simplicity and portability. The total number of possible combinations of policies and priorities is much larger, but allowing more fine-grained control would not be portable.
         int policy = 0;
         struct sched_param param = {};
@@ -1054,17 +1122,23 @@ class [[nodiscard]] this_thread (public)
             param.sched_priority = 0;
             nice_val = PRIO_MAX - 3;
             break;
+	#ifdef __linux__
         case os_thread_priority::idle:
             // "Idle" pre-defined priority on Linux: We use the policy `SCHED_IDLE`, priority must be 0, and we don't touch the "nice" value.
             policy = SCHED_IDLE;
             param.sched_priority = 0;
             break;
+        #endif
         default:
             return false;
         }
         bool success = (pthread_setschedparam(pthread_self(), policy, &param) == 0);
         if (nice_val.has_value())
+        #ifdef __NetBSD__
+            success = success && (setpriority(PRIO_PROCESS, static_cast<id_t>(syscall(SYS__lwp_self)), nice_val.value()) == 0);
+        #else
             success = success && (setpriority(PRIO_PROCESS, static_cast<id_t>(syscall(SYS_gettid)), nice_val.value()) == 0);
+        #endif
         return success;
     #elif defined(__APPLE__)
         // On macOS, unlike Linux, the "nice" value is per-process, not per-thread (in compliance with the POSIX standard). However, unlike Linux, `SCHED_OTHER` on macOS does have a range of priorities. So for `realtime` and `highest` priorities we use `SCHED_FIFO` and `SCHED_RR` respectively as for Linux, but for the other priorities we use `SCHED_OTHER` with a priority in the range given by `sched_get_priority_min(SCHED_OTHER)` to `sched_get_priority_max(SCHED_OTHER)`.
