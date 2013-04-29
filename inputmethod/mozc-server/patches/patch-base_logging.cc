$NetBSD: patch-base_logging.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- base/logging.cc.orig	2013-03-29 04:33:43.000000000 +0000
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
+#elif defined(OS_LINUX) || defined (OS_NETBSD)
            "%lu",
 #else  // = OS_WIN or OS_MACOSX
            "%u",
@@ -131,6 +135,9 @@ string Logging::GetLogMessageHeader() {
            ::getpid(),
            // pthread_self() returns __nc_basic_thread_data*.
            static_cast<void*>(pthread_self())
+#elif defined(OS_NETBSD)
+	   ::getpid(),
+	   _lwp_self()
 #else  // = OS_LINUX
            ::getpid(),
            // It returns unsigned long.
