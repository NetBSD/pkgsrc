$NetBSD: patch-deps_v8_src_base_platform_semaphore.cc,v 1.4 2015/09/09 00:04:54 ryoon Exp $
Work around lack of sem_timedwait(3) in NetBSD < 6.99.4.
Adapted from d4f11c0cf476dd854eaebec1cbacb1afc7bea18e of the Chromium V8 sources.

--- deps/v8/src/base/platform/semaphore.cc.orig	2015-09-08 15:30:38.000000000 +0000
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
@@ -107,7 +111,7 @@ void Semaphore::Wait() {
 
 
 bool Semaphore::WaitFor(const TimeDelta& rel_time) {
-#if V8_OS_NACL
+#if defined(V8_OS_NACL)  || (defined(V8_OS_NETBSD) && (__NetBSD_Version__ - 0 < 699000400))
   // PNaCL doesn't support sem_timedwait, do ugly busy waiting.
   ElapsedTimer timer;
   timer.Start();
