$NetBSD: patch-base_run__level.cc,v 1.2 2014/07/19 09:03:04 ryoon Exp $

--- base/run_level.cc.orig	2014-07-06 07:03:03.000000000 +0000
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
