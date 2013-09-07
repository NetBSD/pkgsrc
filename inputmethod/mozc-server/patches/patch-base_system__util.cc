$NetBSD: patch-base_system__util.cc,v 1.3 2013/09/07 18:42:14 ryoon Exp $

--- base/system_util.cc.orig	2013-08-28 05:26:13.000000000 +0000
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
@@ -493,7 +493,7 @@ string SystemUtil::GetUserNameAsString()
   return ppw->pw_name;
 
 #else  // OS_ANDROID
-  // OS_MACOSX or OS_LINUX
+  // OS_MACOSX or OS_LINUX, OS_NETBSD
   struct passwd pw, *ppw;
   char buf[1024];
   CHECK_EQ(0, getpwuid_r(geteuid(), &pw, buf, sizeof(buf), &ppw));
@@ -653,7 +653,7 @@ string GetSessionIdString() {
 #endif  // OS_WIN
 
 string SystemUtil::GetDesktopNameAsString() {
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   const char *display = getenv("DISPLAY");
   if (display == NULL) {
     return "";
@@ -683,7 +683,7 @@ string SystemUtil::GetDesktopNameAsStrin
   }
 
   return (session_id + "." + window_station_name + "." + desktop_name);
-#endif  // OS_LINUX, OS_MACOSX, OS_WIN
+#endif  // OS_LINUX, OS_MACOSX, OS_WIN, OS_NETBSD
 }
 
 #ifdef OS_WIN
@@ -858,7 +858,7 @@ bool SystemUtil::IsPlatformSupported() {
 #if defined(OS_MACOSX)
   // TODO(yukawa): support Mac.
   return true;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   // TODO(yukawa): support Linux.
   return true;
 #elif defined(OS_WIN)
@@ -1157,10 +1157,13 @@ string SystemUtil::GetOSVersionString() 
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
@@ -1204,7 +1207,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
     return 0;
   }
   return total_memory;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const long page_size = sysconf(_SC_PAGESIZE);
   const long number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
