$NetBSD: patch-base_system__util.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- base/system_util.cc.orig	2013-07-17 02:38:04.000000000 +0000
+++ base/system_util.cc
@@ -421,14 +421,14 @@ string SystemUtil::GetServerDirectory() 
 #elif defined(OS_MACOSX)
   return MacUtil::GetServerDirectory();
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(MOZC_SERVER_DIRECTORY)
   return MOZC_SERVER_DIRECTORY;
 #else
-  return "/usr/lib/mozc";
+  return "@PREFIX@/libexec";
 #endif  // MOZC_SERVER_DIRECTORY
 
-#endif  // OS_WIN, OS_MACOSX, OS_LINUX
+#endif  // OS_WIN, OS_MACOSX, OS_LINUX, OS_NETBSD
 }
 
 string SystemUtil::GetServerPath() {
@@ -616,7 +616,7 @@ bool GetCurrentSessionId(DWORD *session_
 #endif  // OS_WIN
 
 string SystemUtil::GetDesktopNameAsString() {
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   const char *display = getenv("DISPLAY");
   if (display == NULL) {
     return "";
@@ -815,7 +815,7 @@ bool SystemUtil::IsPlatformSupported() {
 #if defined(OS_MACOSX)
   // TODO(yukawa): support Mac.
   return true;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   // TODO(yukawa): support Linux.
   return true;
 #elif defined(OS_WIN)
@@ -1104,10 +1104,13 @@ string SystemUtil::GetOSVersionString() 
 #elif defined(OS_LINUX)
   const string ret = "Linux";
   return ret;
-#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
+#elif defined(OS_NETBSD)
+  const string ret = "NetBSD";
+  return ret;
+#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX && !OS_NETBSD
   const string ret = "Unknown";
   return ret;
-#endif  // OS_WIN, OS_MACOSX, OS_LINUX
+#endif  // OS_WIN, OS_MACOSX, OS_LINUX, OS_NETBSD
 }
 
 bool SystemUtil::MacOSVersionIsGreaterOrEqual(int32 major,
@@ -1151,7 +1154,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
     return 0;
   }
   return total_memory;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const long page_size = sysconf(_SC_PAGESIZE);
   const long number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
