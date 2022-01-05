$NetBSD: patch-cpucycles_fakenanoseconds.c,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Part of Debian 0008-add-cpucycles-fakenanoseconds.patch:
Provide a fakenanoseconds implementation for portability.

--- cpucycles/fakenanoseconds.c.orig	2022-01-05 13:32:14.000000000 +0000
+++ cpucycles/fakenanoseconds.c
@@ -0,0 +1,23 @@
+#include <time.h>
+
+/* XXX Measured numbers are not CPU cycles but nanoseconds !!! */
+
+static long long faketime = 0;
+
+long long cpucycles_fakenanoseconds(void) {
+
+    struct timespec t;
+    long long tm;
+
+    if (clock_gettime(CLOCK_MONOTONIC,&t) != 0) return -1;
+
+    tm = t.tv_sec * 1000000000LL + t.tv_nsec;
+    if (tm > faketime) faketime = tm;
+    ++faketime;
+
+    return faketime;
+}
+
+long long cpucycles_fakenanoseconds_persecond(void) {
+    return 1000000000LL;
+}
