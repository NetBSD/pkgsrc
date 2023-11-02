$NetBSD: patch-deps_v8_src_base_platform_platform-posix.cc,v 1.1 2023/11/02 13:16:54 adam Exp $

Use sysconf(_SC_THREAD_STACK_MIN) instead of PTHREAD_STACK_MIN.
Cast explicitly.
Remove legacy madvise(2) prototypes, prefer posix_madvise(2) if available.

Avoid using a random hint, some low numbers cause spurious ENOMEM on netbsd
(PR port-arm/55533)

--- deps/v8/src/base/platform/platform-posix.cc.orig	2023-04-17 23:15:54.000000000 +0200
+++ deps/v8/src/base/platform/platform-posix.cc	2023-05-03 14:19:05.405513040 +0200
@@ -75,14 +75,6 @@
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#if defined(V8_OS_SOLARIS)
-#if (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE > 2) || defined(__EXTENSIONS__)
-extern "C" int madvise(caddr_t, size_t, int);
-#else
-extern int madvise(caddr_t, size_t, int);
-#endif
-#endif
-
 #ifndef MADV_FREE
 #define MADV_FREE MADV_DONTNEED
 #endif
@@ -391,6 +383,10 @@
 #endif
 #endif
 #endif
+
+#if V8_OS_NETBSD
+  raw_addr = 0;
+#endif
   return reinterpret_cast<void*>(raw_addr);
 }
 
@@ -553,14 +549,11 @@
     // MADV_FREE_REUSABLE sometimes fails, so fall back to MADV_DONTNEED.
     ret = madvise(address, size, MADV_DONTNEED);
   }
-#elif defined(_AIX) || defined(V8_OS_SOLARIS)
-  int ret = madvise(reinterpret_cast<caddr_t>(address), size, MADV_FREE);
+#elif defined(POSIX_MADV_DONTNEED)
+  int ret = posix_madvise(address, size, POSIX_MADV_DONTNEED);
   if (ret != 0 && errno == ENOSYS) {
     return true;  // madvise is not available on all systems.
   }
-  if (ret != 0 && errno == EINVAL) {
-    ret = madvise(reinterpret_cast<caddr_t>(address), size, MADV_DONTNEED);
-  }
 #else
   int ret = madvise(address, size, MADV_DONTNEED);
 #endif
@@ -802,6 +795,8 @@
   return static_cast<int>(syscall(__NR_gettid));
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
+#elif V8_OS_NETBSD || V8_OS_FREEBSD
+  return static_cast<int>(reinterpret_cast<intptr_t>(pthread_self()));
 #elif V8_OS_AIX
   return static_cast<int>(thread_self());
 #elif V8_OS_FUCHSIA
@@ -1075,7 +1070,11 @@
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
       start_semaphore_(nullptr) {
+#if V8_OS_NETBSD
+  const int min_stack_size = sysconf(_SC_THREAD_STACK_MIN);
+#else
   const int min_stack_size = static_cast<int>(PTHREAD_STACK_MIN);
+#endif
   if (stack_size_ > 0) stack_size_ = std::max(stack_size_, min_stack_size);
   set_name(options.name());
 }
@@ -1091,7 +1090,7 @@
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   static_assert(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_DARWIN
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
