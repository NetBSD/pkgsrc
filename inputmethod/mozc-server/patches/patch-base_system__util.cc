$NetBSD: patch-base_system__util.cc,v 1.4 2016/05/16 11:51:49 ryoon Exp $

--- base/system_util.cc.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/system_util.cc
@@ -372,11 +372,11 @@ string SystemUtil::GetServerDirectory() 
 #elif defined(OS_MACOSX)
   return MacUtil::GetServerDirectory();
 
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 #if defined(MOZC_SERVER_DIRECTORY)
   return MOZC_SERVER_DIRECTORY;
 #else
-  return "/usr/lib/mozc";
+  return "@PREFIX@/lib/mozc";
 #endif  // MOZC_SERVER_DIRECTORY
 
 #endif  // OS_WIN, OS_MACOSX, OS_LINUX, ...
@@ -450,7 +450,7 @@ string SystemUtil::GetUserNameAsString()
   return ppw->pw_name;
 
 #else  // OS_ANDROID
-  // OS_MACOSX, OS_LINUX or OS_NACL
+  // OS_MACOSX, OS_LINUX, OS_NACL or OS_NETBSD
   struct passwd pw, *ppw;
   char buf[1024];
   CHECK_EQ(0, getpwuid_r(geteuid(), &pw, buf, sizeof(buf), &ppw));
@@ -610,7 +610,7 @@ string GetSessionIdString() {
 #endif  // OS_WIN
 
 string SystemUtil::GetDesktopNameAsString() {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   const char *display = getenv("DISPLAY");
   if (display == NULL) {
     return "";
@@ -691,7 +691,7 @@ bool SystemUtil::IsPlatformSupported() {
 #if defined(OS_MACOSX)
   // TODO(yukawa): support Mac.
   return true;
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   // TODO(yukawa): support Linux.
   return true;
 #elif defined(OS_WIN)
@@ -930,10 +930,13 @@ string SystemUtil::GetOSVersionString() 
 #elif defined(OS_LINUX) || defined(OS_NACL)
   const string ret = "Linux";
   return ret;
+#elif defined(OS_NETBSD)
+  const string ret = "NetBSD";
+  return ret;
 #else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
   const string ret = "Unknown";
   return ret;
-#endif  // OS_WIN, OS_MACOSX, OS_LINUX
+#endif  // OS_WIN, OS_MACOSX, OS_LINUX, OS_NETBSD
 }
 
 bool SystemUtil::MacOSVersionIsGreaterOrEqual(int32 major,
@@ -977,7 +980,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
     return 0;
   }
   return total_memory;
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const long page_size = sysconf(_SC_PAGESIZE);
   const long number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
@@ -992,7 +995,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
 #endif  // defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
 #else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
 #error "unknown platform"
-#endif  // OS_WIN, OS_MACOSX, OS_LINUX
+#endif  // OS_WIN, OS_MACOSX, OS_LINUX, OS_NETBSD
 }
 
 bool SystemUtil::IsLittleEndian() {
