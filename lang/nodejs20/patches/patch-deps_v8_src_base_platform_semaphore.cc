$NetBSD: patch-deps_v8_src_base_platform_semaphore.cc,v 1.1 2023/11/02 13:16:54 adam Exp $

Work around lack of sem_timedwait(3) in NetBSD < 6.99.4.
Adapted from d4f11c0cf476dd854eaebec1cbacb1afc7bea18e of the Chromium V8 sources.

--- deps/v8/src/base/platform/semaphore.cc.orig	2016-10-25 13:26:03.000000000 +0000
+++ deps/v8/src/base/platform/semaphore.cc
@@ -11,6 +11,10 @@
 
 #include <errno.h>
 
+#if V8_OS_NETBSD
+#include <sys/param.h>	// for __NetBSD_Version__
+#endif
+
 #include "src/base/logging.h"
 #include "src/base/platform/elapsed-timer.h"
 #include "src/base/platform/time.h"
