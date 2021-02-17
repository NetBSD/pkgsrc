$NetBSD: patch-base_run__level.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- base/run_level.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ base/run_level.cc
@@ -38,10 +38,10 @@
 #include <unistd.h>
 #endif  // __APPLE__
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NETBSD)
 #include <sys/types.h>
 #include <unistd.h>
-#endif  // OS_LINUX || OS_ANDROID
+#endif  // OS_LINUX || OS_ANDROID || OS_NETBSD
 
 #include "base/const.h"
 #include "base/logging.h"
