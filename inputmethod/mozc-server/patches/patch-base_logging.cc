$NetBSD: patch-base_logging.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- base/logging.cc.orig	2013-07-17 02:38:04.000000000 +0000
+++ base/logging.cc
@@ -61,6 +61,10 @@
 #include "base/system_util.h"
 #include "base/util.h"
 
+#if defined(OS_NETBSD)
+#include <lwp.h>
+#endif
+
 DEFINE_bool(colored_log, true, "Enables colored log messages on tty devices");
 DEFINE_bool(logtostderr,
             false,
@@ -110,7 +114,7 @@ string Logging::GetLogMessageHeader() {
            "%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d %u "
 #if defined(__native_client__)
            "%p",
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
            "%lu",
 #elif defined(OS_MACOSX) && defined(__LP64__)
            "%llu",
@@ -137,6 +141,9 @@ string Logging::GetLogMessageHeader() {
            ::getpid(),
            // pthread_self() returns __nc_basic_thread_data*.
            static_cast<void*>(pthread_self())
+#elif defined(OS_NETBSD)
+	   ::getpid(),
+	   _lwp_self()
 #else  // = OS_LINUX
            ::getpid(),
            // It returns unsigned long.
