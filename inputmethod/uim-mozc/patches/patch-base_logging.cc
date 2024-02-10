$NetBSD: patch-base_logging.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- base/logging.cc.orig	2023-10-26 12:00:50.000000000 +0000
+++ base/logging.cc
@@ -114,10 +114,10 @@ std::string Logging::GetLogMessageHeader
 #if defined(__wasm__)
   return absl::StrCat(timestamp, ::getpid(), " ",
                       static_cast<unsigned int>(pthread_self()));
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__NetBSD__)
   return absl::StrCat(timestamp, ::getpid(), " ",
                       // It returns unsigned long.
-                      pthread_self());
+                      (unsigned long)pthread_self());
 #elif defined(__APPLE__)
 #ifdef __LP64__
   return absl::StrCat(timestamp, ::getpid(), " ",
