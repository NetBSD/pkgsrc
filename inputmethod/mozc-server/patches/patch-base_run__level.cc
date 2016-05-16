$NetBSD: patch-base_run__level.cc,v 1.4 2016/05/16 11:51:49 ryoon Exp $

--- base/run_level.cc.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/run_level.cc
@@ -38,10 +38,10 @@
 #include <unistd.h>
 #endif  // OS_MACOSX
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 #include <unistd.h>
 #include <sys/types.h>
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 
 #include "base/const.h"
 #include "base/logging.h"
