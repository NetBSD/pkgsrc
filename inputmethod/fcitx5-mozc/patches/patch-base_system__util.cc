$NetBSD: patch-base_system__util.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

--- base/system_util.cc.orig	2021-02-15 05:04:33.000000000 +0000
+++ base/system_util.cc
@@ -275,7 +275,7 @@ std::string UserProfileDirectoryImpl::Ge
 # endif  //  GOOGLE_JAPANESE_INPUT_BUILD
 
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   // 1. If "$HOME/.mozc" already exists,
   //    use "$HOME/.mozc" for backward compatibility.
   // 2. If $XDG_CONFIG_HOME is defined
@@ -422,7 +422,7 @@ std::string SystemUtil::GetServerDirecto
   return MacUtil::GetServerDirectory();
 #endif  // __APPLE__
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
 # if defined(MOZC_SERVER_DIRECTORY)
   return MOZC_SERVER_DIRECTORY;
 # else
@@ -499,12 +499,12 @@ std::string SystemUtil::GetUserNameAsStr
   return ppw->pw_name;
 #endif  // OS_ANDROID
 
-#if defined(__APPLE__) || defined(OS_LINUX) || defined(OS_WASM)
+#if defined(__APPLE__) || defined(OS_LINUX) || defined(OS_WASM) || defined(OS_NETBSD)
   struct passwd pw, *ppw;
   char buf[1024];
   CHECK_EQ(0, getpwuid_r(geteuid(), &pw, buf, sizeof(buf), &ppw));
   return pw.pw_name;
-#endif  // __APPLE__ || OS_LINUX || OS_WASM
+#endif  // __APPLE__ || OS_LINUX || OS_WASM || OS_NETBSD
 
   // If none of the above platforms is specified, the compiler raises an error
   // because of no return value.
@@ -662,13 +662,13 @@ string GetSessionIdString() {
 #endif  // OS_WIN
 
 std::string SystemUtil::GetDesktopNameAsString() {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
   const char *display = Environ::GetEnv("DISPLAY");
   if (display == nullptr) {
     return "";
   }
   return display;
-#endif  // OS_LINUX || OS_ANDROID || OS_WASM
+#endif  // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
 
 #if defined(__APPLE__)
   return "";
@@ -862,10 +862,13 @@ std::string SystemUtil::GetOSVersionStri
 #elif defined(OS_LINUX)
   const std::string ret = "Linux";
   return ret;
-#else   // !OS_WIN && !__APPLE__ && !OS_LINUX
+#elif defined(OS_NETBSD)
+  const std::string ret = "NetBSD";
+  return ret;
+#else   // !OS_WIN && !__APPLE__ && !OS_LINUX && !OS_NETBSD
   const string ret = "Unknown";
   return ret;
-#endif  // OS_WIN, __APPLE__, OS_LINUX
+#endif  // OS_WIN, __APPLE__, OS_LINUX, OS_NETBSD
 }
 
 void SystemUtil::DisableIME() {
@@ -901,7 +904,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
   return total_memory;
 #endif  // __APPLE__
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_WASM) || defined(OS_NETBSD)
 # if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const int32 page_size = sysconf(_SC_PAGESIZE);
   const int32 number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
@@ -914,7 +917,7 @@ uint64 SystemUtil::GetTotalPhysicalMemor
 # else   // defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   return 0;
 # endif  // defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
-#endif   // OS_LINUX || OS_ANDROID || OS_WASM
+#endif   // OS_LINUX || OS_ANDROID || OS_WASM || OS_NETBSD
 
   // If none of the above platforms is specified, the compiler raises an error
   // because of no return value.
