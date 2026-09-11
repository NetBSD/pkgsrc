$NetBSD: patch-tests_contrib_test_atomic.c,v 1.1 2026/09/11 12:53:14 drixter Exp $

Patch from upstream to work on SmartOS #980

--- tests/contrib/test_atomic.c.orig	2026-09-10 17:48:19.686990159 +0000
+++ tests/contrib/test_atomic.c
@@ -6,6 +6,7 @@
 #include <pthread.h>
 #include <signal.h>
 #include <tap/basic.h>
+#include <stdint.h>
 
 #include "contrib/atomic.h"
 #include "knot/server/dthreads.h"
@@ -49,11 +50,10 @@ static int thread_add(struct dthread *th
 
 static int thread_set(struct dthread *thread)
 {
-	u_int64_t val = (dt_get_id(thread) % 2) ? UPPER : LOWER;
-
+	uint64_t val = (dt_get_id(thread) % 2) ? UPPER : LOWER;
 	for (int i = 0; i < CYCLES2; i++) {
 		ATOMIC_SET(atomic_var, val);
-		volatile u_int64_t read = ATOMIC_GET(atomic_var);
+		volatile uint64_t read = ATOMIC_GET(atomic_var);
 		if (read != UPPER && read != LOWER) {
 			// Non-atomic counter, won't be accurate!
 			// However, it's sufficient for fault detection.
