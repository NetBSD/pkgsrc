$NetBSD: patch-base_system__util.cc,v 1.5 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- base/system_util.cc.orig	2017-11-02 13:32:45.000000000 +0000
+++ base/system_util.cc
@@ -372,7 +372,7 @@ string SystemUtil::GetServerDirectory() 
 #elif defined(OS_MACOSX)
   return MacUtil::GetServerDirectory();
 
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 #if defined(MOZC_SERVER_DIRECTORY)
   return MOZC_SERVER_DIRECTORY;
 #else
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
@@ -812,6 +812,9 @@ string SystemUtil::GetOSVersionString() 
 #elif defined(OS_LINUX) || defined(OS_NACL)
   const string ret = "Linux";
   return ret;
+#elif defined(OS_NETBSD)
+  const string ret = "NetBSD";
+  return ret;
 #else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
   const string ret = "Unknown";
   return ret;
@@ -847,7 +850,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
     return 0;
   }
   return total_memory;
-#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const long page_size = sysconf(_SC_PAGESIZE);
   const long number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
@@ -862,7 +865,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
 #endif  // defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
 #else  // !(defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX))
 #error "unknown platform"
-#endif  // OS_WIN, OS_MACOSX, OS_LINUX
+#endif  // OS_WIN, OS_MACOSX, OS_LINUX, OS_NETBSD
 }
 
 }  // namespace mozc
