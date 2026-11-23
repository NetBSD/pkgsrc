$NetBSD: patch-src_util_futex.c,v 1.1 2026/11/23 10:29:52 adam Exp $

* Add futex support functions for NetBSD.

--- src/util/futex.c.orig	2026-10-23 06:41:48.873423635 +0000
+++ src/util/futex.c
@@ -151,6 +151,38 @@ int futex_wait(uint32_t *addr, int32_t value, const st
    return GetLastError() == ERROR_TIMEOUT ? ETIMEDOUT : -1;
 }
 
+#elif defined(__NetBSD__)
+#include <unistd.h>
+#include <sys/syscall.h>
+#include <sys/futex.h>
+#include <sys/time.h>
+
+static int futex(uint32_t *uaddr, int op, int val, const struct timespec *timeout,
+                 int *uaddr2, int val3)
+{
+   return syscall(SYS___futex, uaddr, op, val, timeout, uaddr2, val3);
+}
+
+int futex_wake(uint32_t *addr, int32_t count)
+{
+   return futex(addr, FUTEX_WAKE, count, NULL, NULL, 0);
+}
+
+int futex_wait(uint32_t *addr, int32_t value, const struct timespec *timeout)
+{
+   struct timespec tsnow, tsrel;
+
+   if (timeout == NULL)
+      return futex(addr, FUTEX_WAIT, value, NULL, NULL, 0);
+
+   clock_gettime(CLOCK_MONOTONIC, &tsnow);
+   if (timespeccmp(&tsnow, timeout, <))
+      timespecsub(timeout, &tsnow, &tsrel);
+   else
+      timespecclear(&tsrel);
+   return futex(addr, FUTEX_WAIT, value, &tsrel, NULL, 0);
+}
+
 #else
 #error UTIL_FUTEX_SUPPORTED is not implemented but the header told it is supported on this platform
 #endif
