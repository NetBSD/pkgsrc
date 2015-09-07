$NetBSD: patch-src_third__party_v8-3.25_src_platform_semaphore.cc,v 1.1 2015/09/07 11:52:56 fhajny Exp $

Work around lack of sem_timedwait(3) in NetBSD < 6.99.4.
Adapted from d4f11c0cf476dd854eaebec1cbacb1afc7bea18e of the Chromium V8 sources.

--- src/third_party/v8-3.25/src/platform/semaphore.cc.orig	2015-08-24 00:39:52.000000000 +0000
+++ src/third_party/v8-3.25/src/platform/semaphore.cc
@@ -32,9 +32,14 @@
 #include <mach/task.h>
 #endif
 
+#if V8_OS_NETBSD
+#include <sys/param.h>  // for __NetBSD_Version__
+#endif
+
 #include <errno.h>
 
 #include "checks.h"
+#include "platform/elapsed-timer.h"
 #include "platform/time.h"
 
 namespace v8 {
@@ -129,6 +134,17 @@ void Semaphore::Wait() {
 
 
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
@@ -152,6 +168,7 @@ bool Semaphore::WaitFor(const TimeDelta&
     ASSERT_EQ(-1, result);
     ASSERT_EQ(EINTR, errno);
   }
+#endif
 }
 
 #elif V8_OS_WIN
