$NetBSD: patch-base_logging.cc,v 1.6 2021/02/15 14:50:23 ryoon Exp $

* NetBSD support

--- base/logging.cc.orig	2021-02-15 05:04:33.000000000 +0000
+++ base/logging.cc
@@ -62,6 +62,10 @@
 #include "absl/flags/flag.h"
 #include "absl/strings/str_cat.h"
 
+#if defined(OS_NETBSD)
+#include <lwp.h>
+#endif
+
 ABSL_FLAG(bool, colored_log, true,
           "Enables colored log messages on tty devices");
 ABSL_FLAG(bool, logtostderr, false,
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
