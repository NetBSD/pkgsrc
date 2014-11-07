$NetBSD: patch-base_run__level.cc,v 1.3 2014/11/07 23:28:36 ryoon Exp $

--- base/run_level.cc.orig	2014-11-03 05:13:02.000000000 +0000
+++ base/run_level.cc
@@ -38,10 +38,10 @@
 #include <unistd.h>
 #endif  // OS_MACOSX
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 #include <unistd.h>
 #include <sys/types.h>
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
 #include "base/const.h"
 #include "base/logging.h"
