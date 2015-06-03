$NetBSD: patch-deps_v8_src_base_platform_semaphore.cc,v 1.3 2015/06/03 18:23:24 fhajny Exp $
Work around lack of sem_timedwait(3) in NetBSD < 6.99.4.
Adapted from d4f11c0cf476dd854eaebec1cbacb1afc7bea18e of the Chromium V8 sources.

--- deps/v8/src/base/platform/semaphore.cc.orig	2015-03-31 22:13:01.000000000 +0000
+++ deps/v8/src/base/platform/semaphore.cc	2015-05-14 12:47:08.000000000 +0000
@@ -9,9 +9,14 @@
 #include <mach/task.h>
 #endif
 
+#if V8_OS_NETBSD
+#include <sys/param.h>  // for __NetBSD_Version__
+#endif
+
 #include <errno.h>
 
 #include "src/base/logging.h"
+#include "src/base/platform/elapsed-timer.h"
 #include "src/base/platform/time.h"
 
 namespace v8 {
@@ -106,6 +111,17 @@
 
 
 bool Semaphore::WaitFor(const TimeDelta& rel_time) {
+#if V8_OS_NACL || (V8_OS_NETBSD && __NetBSD_Version__ - 0 < 699000400)
+  // PNaCL and older NetBSD doesn't support sem_timedwait, do ugly busy waiting.
+  ElapsedTimer timer;
+  timer.Start();
+  do {
+    int result = sem_trywait(&native_handle_);
+    if (result == 0) return true;
+      DCHECK(errno == EAGAIN || errno == EINTR);
+  } while (!timer.HasExpired(rel_time));
+  return false;
+#else
   // Compute the time for end of timeout.
   const Time time = Time::NowFromSystemTime() + rel_time;
   const struct timespec ts = time.ToTimespec();
@@ -129,6 +145,7 @@
     DCHECK_EQ(-1, result);
     DCHECK_EQ(EINTR, errno);
   }
+#endif
 }
 
 #elif V8_OS_WIN
