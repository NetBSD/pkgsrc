$NetBSD: patch-lib_fuzzer_FuzzerUtilLinux.cpp,v 1.1 2024/07/06 15:45:06 adam Exp $

Fix a typo.

--- lib/fuzzer/FuzzerUtilLinux.cpp.orig	2024-07-03 12:00:43.939003953 +0000
+++ lib/fuzzer/FuzzerUtilLinux.cpp
@@ -44,7 +44,7 @@ void SetThreadName(std::thread &thread, 
 #if LIBFUZZER_LINUX || LIBFUZZER_FREEBSD
   (void)pthread_setname_np(thread.native_handle(), name.c_str());
 #elif LIBFUZZER_NETBSD
-  (void)pthread_set_name_np(thread.native_handle(), "%s", name.c_str());
+  (void)pthread_setname_np(thread.native_handle(), "%s", (void *)name.c_str());
 #endif
 }
 
