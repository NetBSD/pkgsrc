$NetBSD: patch-base_logging.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- base/logging.cc.orig	2012-08-31 05:37:06.000000000 +0000
+++ base/logging.cc
@@ -59,6 +59,10 @@
 #include "base/singleton.h"
 #include "base/util.h"
 
+#if defined(OS_NETBSD)
+#include <lwp.h>
+#endif
+
 DEFINE_bool(colored_log, true, "Enables colored log messages on tty devices");
 DEFINE_bool(logtostderr,
             false,
@@ -106,12 +110,7 @@ string Logging::GetLogMessageHeader() {
   char buf[512];
   snprintf(buf, sizeof(buf),
            "%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d %u "
-#if !defined(OS_LINUX) || defined(__native_client__)
-// = OS_WINDOWS or OS_MACOSX or __native_client__
-           "%u",
-#else
            "%lu",
-#endif
            1900 + tm_time.tm_year,
            1 + tm_time.tm_mon,
            tm_time.tm_mday,
@@ -124,6 +123,9 @@ string Logging::GetLogMessageHeader() {
 #elif defined(OS_MACOSX)
            ::getpid(),
            reinterpret_cast<uint32>(pthread_self())
+#elif defined(OS_NETBSD)
+           ::getpid(),
+           _lwp_self()
 #else  // = OS_LINUX
            ::getpid(),
            // In NaCl it returns uint32, otherwise it returns unsigned long.
