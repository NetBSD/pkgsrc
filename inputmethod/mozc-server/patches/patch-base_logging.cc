$NetBSD: patch-base_logging.cc,v 1.4 2016/05/16 11:51:49 ryoon Exp $

--- base/logging.cc.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/logging.cc
@@ -61,6 +61,10 @@
 #include "base/mutex.h"
 #include "base/singleton.h"
 
+#if defined(OS_NETBSD)
+#include <lwp.h>
+#endif
+
 DEFINE_bool(colored_log, true, "Enables colored log messages on tty devices");
 DEFINE_bool(logtostderr,
             false,
@@ -102,7 +106,7 @@ string Logging::GetLogMessageHeader() {
            "%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d %u "
 #if defined(OS_NACL)
            "%p",
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
            "%lu",
 #elif defined(OS_MACOSX) && defined(__LP64__)
            "%llu",
@@ -129,6 +133,9 @@ string Logging::GetLogMessageHeader() {
            ::getpid(),
            // pthread_self() returns __nc_basic_thread_data*.
            static_cast<void*>(pthread_self())
+#elif defined(OS_NETBSD)
+          ::getpid(),
+          (unsigned long)_lwp_self()
 #else  // = OS_LINUX
            ::getpid(),
            // It returns unsigned long.
