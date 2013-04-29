$NetBSD: patch-base_system__util.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- base/system_util.cc.orig	2013-03-29 04:33:43.000000000 +0000
+++ base/system_util.cc
@@ -421,7 +421,7 @@ string SystemUtil::GetServerDirectory() 
 #elif defined(OS_MACOSX)
   return MacUtil::GetServerDirectory();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   // TODO(mazda): Not to use hardcoded path.
   return kMozcServerDirectory;
 #endif  // OS_WIN, OS_MACOSX, OS_LINUX
@@ -610,7 +610,7 @@ bool GetCurrentSessionId(DWORD *session_
 #endif  // OS_WIN
 
 string SystemUtil::GetDesktopNameAsString() {
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   const char *display = getenv("DISPLAY");
   if (display == NULL) {
     return "";
@@ -809,7 +809,7 @@ bool SystemUtil::IsPlatformSupported() {
 #if defined(OS_MACOSX)
   // TODO(yukawa): support Mac.
   return true;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   // TODO(yukawa): support Linux.
   return true;
 #elif defined(OS_WIN)
@@ -1098,6 +1098,9 @@ string SystemUtil::GetOSVersionString() 
 #elif defined(OS_LINUX)
   const string ret = "Linux";
   return ret;
+#elif defined(OS_NETBSD)
+  const string ret = "NetBSD";
+  return ret;
 #else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
   const string ret = "Unknown";
   return ret;
@@ -1145,7 +1148,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
     return 0;
   }
   return total_memory;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const long page_size = sysconf(_SC_PAGESIZE);
   const long number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
