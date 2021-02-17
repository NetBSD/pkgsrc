$NetBSD: patch-base_logging.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

--- base/logging.cc.orig	2021-02-17 12:18:42.000000000 +0000
+++ base/logging.cc
@@ -53,6 +53,10 @@
 #include <sstream>
 #include <string>
 
+#if defined(OS_NETBSD)
+#include <lwp.h>
+#endif
+
 #ifdef OS_ANDROID
 #include "base/const.h"
 #endif  // OS_ANDROID
@@ -112,6 +116,9 @@ string Logging::GetLogMessageHeader() {
   return absl::StrCat(timestamp, ::getpid(), " ",
                       // It returns unsigned long.
                       pthread_self());
+# elif defined(OS_NETBSD)
+  return absl::StrCat(timestamp, ::getpid(), " ",
+                      (unsigned long)_lwp_self());
 # elif defined(__APPLE__)
 #  ifdef __LP64__
   return absl::StrCat(timestamp, ::getpid(), " ",
