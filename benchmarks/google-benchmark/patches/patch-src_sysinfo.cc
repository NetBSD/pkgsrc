$NetBSD: patch-src_sysinfo.cc,v 1.1 2020/01/24 16:13:03 minskim Exp $

Make sure HOST_NAME_MAX is always defined.
https://github.com/google/benchmark/commit/7411874d9563b18c56f8a81e02e77c6ffc5c3851

--- src/sysinfo.cc.orig	2019-05-13 19:42:18.000000000 +0000
+++ src/sysinfo.cc
@@ -429,11 +429,20 @@ std::string GetSystemName() {
 #endif
   return str;
 #else // defined(BENCHMARK_OS_WINDOWS)
+#ifndef HOST_NAME_MAX
 #ifdef BENCHMARK_HAS_SYSCTL // BSD/Mac Doesnt have HOST_NAME_MAX defined
 #define HOST_NAME_MAX 64
+#elif defined(BENCHMARK_OS_NACL)
+#define HOST_NAME_MAX 64
 #elif defined(BENCHMARK_OS_QNX)
 #define HOST_NAME_MAX 154
+#elif defined(BENCHMARK_OS_RTEMS)
+#define HOST_NAME_MAX 256
+#else
+#warning "HOST_NAME_MAX not defined. using 64"
+#define HOST_NAME_MAX 64
 #endif
+#endif // def HOST_NAME_MAX
   char hostname[HOST_NAME_MAX];
   int retVal = gethostname(hostname, HOST_NAME_MAX);
   if (retVal != 0) return std::string("");
