$NetBSD: patch-common_umutex.h,v 1.2 2019/04/03 00:13:00 ryoon Exp $

* Add NetBSD MI atomic_ops(3) support

--- common/umutex.h.orig	2019-03-27 18:47:14.000000000 +0000
+++ common/umutex.h
@@ -60,6 +60,31 @@ template struct std::atomic<int32_t>;
 
 U_NAMESPACE_BEGIN
 
+#if U_HAVE_NETBSD_ATOMIC_OPS
+/*
+ * NetBSD MI atomic_ops(3)
+ */
+#include <sys/atomic.h>
+typedef volatile uint32_t u_atomic_int32_t;
+#define ATOMIC_INT32_T_INITIALIZER(val) val
+
+inline int32_t umtx_loadAcquire(u_atomic_int32_t &var) {
+    return atomic_cas_32(&var, 0, 0);
+}
+
+inline void umtx_storeRelease(u_atomic_int32_t &var, int32_t val) {
+    atomic_swap_32(&var, val);
+}
+
+inline int32_t umtx_atomic_inc(u_atomic_int32_t *p) {
+    return atomic_inc_32_nv(p);
+}
+
+inline int32_t umtx_atomic_dec(u_atomic_int32_t *p) {
+    return atomic_dec_32_nv(p);
+}
+#else
+
 /****************************************************************************
  *
  *   Low Level Atomic Operations, ICU wrappers for.
@@ -84,7 +109,7 @@ inline int32_t umtx_atomic_inc(u_atomic_
 inline int32_t umtx_atomic_dec(u_atomic_int32_t *var) {
     return var->fetch_sub(1) - 1;
 }
-
+#endif
 
 /*************************************************************************************************
  *
