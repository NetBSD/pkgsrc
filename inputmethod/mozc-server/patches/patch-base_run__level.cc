$NetBSD: patch-base_run__level.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- base/run_level.cc.orig	2013-03-29 04:33:43.000000000 +0000
+++ base/run_level.cc
@@ -34,10 +34,10 @@
 #include <aclapi.h>
 #endif  // OS_WIN
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 #include <unistd.h>
 #include <sys/types.h>
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
 #include "base/const.h"
 #include "base/logging.h"
