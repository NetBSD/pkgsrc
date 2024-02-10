$NetBSD: patch-base_system__util.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- base/system_util.cc.orig	2023-10-26 12:00:50.000000000 +0000
+++ base/system_util.cc
@@ -278,7 +278,7 @@ std::string UserProfileDirectoryImpl::Ge
   return FileUtil::JoinPath(dir, "Mozc");
 #endif  //  GOOGLE_JAPANESE_INPUT_BUILD
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
   // 1. If "$HOME/.mozc" already exists,
   //    use "$HOME/.mozc" for backward compatibility.
   // 2. If $XDG_CONFIG_HOME is defined
@@ -429,9 +429,9 @@ std::string SystemUtil::GetServerDirecto
   return MacUtil::GetServerDirectory();
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
 #ifndef MOZC_SERVER_DIR
-#define MOZC_SERVER_DIR "/usr/lib/mozc"
+#define MOZC_SERVER_DIR "@PREFIX@/libexec"
 #endif  // MOZC_SERVER_DIR
   return MOZC_SERVER_DIR;
 #endif  // __linux__ || __wasm__
@@ -471,7 +471,7 @@ std::string SystemUtil::GetDocumentDirec
 #if defined(__linux__)
 
 #ifndef MOZC_DOCUMENT_DIR
-#define MOZC_DOCUMENT_DIR "/usr/lib/mozc/documents"
+#define MOZC_DOCUMENT_DIR "@PREFIX@/libexec/documents"
 #endif  // MOZC_DOCUMENT_DIR
   return MOZC_DOCUMENT_DIR;
 
@@ -661,7 +661,7 @@ std::string GetSessionIdString() {
 #endif  // _WIN32
 
 std::string SystemUtil::GetDesktopNameAsString() {
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
   const char *display = Environ::GetEnv("DISPLAY");
   if (display == nullptr) {
     return "";
@@ -834,6 +834,9 @@ std::string SystemUtil::GetOSVersionStri
 #elif defined(__linux__)
   const std::string ret = "Linux";
   return ret;
+#elif defined(__NetBSD__)
+  const std::string ret = "NetBSD";
+  return ret;
 #else   // !_WIN32 && !__APPLE__ && !__linux__
   const std::string ret = "Unknown";
   return ret;
@@ -873,7 +876,7 @@ uint64_t SystemUtil::GetTotalPhysicalMem
   return total_memory;
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__NetBSD__)
 #if defined(_SC_PAGESIZE) && defined(_SC_PHYS_PAGES)
   const int32_t page_size = sysconf(_SC_PAGESIZE);
   const int32_t number_of_phyisical_pages = sysconf(_SC_PHYS_PAGES);
