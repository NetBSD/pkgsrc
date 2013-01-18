$NetBSD: patch-base_util.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- base/util.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/util.cc
@@ -891,7 +891,7 @@ class ClockImpl : public Util::ClockInte
     mach_timebase_info(&timebase_info);
     return static_cast<uint64>(
         1.0e9 * timebase_info.denom / timebase_info.numer);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(HAVE_LIBRT)
     return 1000000000uLL;
 #else
@@ -911,7 +911,7 @@ class ClockImpl : public Util::ClockInte
     return static_cast<uint64>(timestamp.QuadPart);
 #elif defined(OS_MACOSX)
     return static_cast<uint64>(mach_absolute_time());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(HAVE_LIBRT)
     struct timespec timestamp;
     if (-1 == clock_gettime(CLOCK_REALTIME, &timestamp)) {
@@ -1869,9 +1869,9 @@ string Util::GetServerDirectory() {
   return MacUtil::GetServerDirectory();
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   return kMozcServerDirectory;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 }
 
 string Util::GetServerPath() {
@@ -2000,7 +2000,7 @@ bool GetCurrentSessionId(DWORD *session_
 #endif  // OS_WINDOWS
 
 string Util::GetDesktopNameAsString() {
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   const char *display = getenv("DISPLAY");
   if (display == NULL) {
     return "";
@@ -2514,7 +2514,7 @@ bool Util::IsPlatformSupported() {
 #if defined(OS_MACOSX)
   // TODO(yukawa): support Mac.
   return true;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   // TODO(yukawa): support Linux.
   return true;
 #elif defined(OS_WINDOWS)
@@ -2873,6 +2873,9 @@ string Util::GetOSVersionString() {
 #elif defined(OS_LINUX)
   const string ret = "Linux";
   return ret;
+#elif defined(OS_NETBSD)
+  const string ret = "NetBSD";
+  return ret;
 #else
   const string ret = "Unknown";
   return ret;
@@ -2910,7 +2913,7 @@ uint64 Util::GetTotalPhysicalMemory() {
     return 0;
   }
   return total_memory;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const long page_size = sysconf(_SC_PAGESIZE);
   const long number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
