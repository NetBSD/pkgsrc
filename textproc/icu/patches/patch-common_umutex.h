$NetBSD: patch-common_umutex.h,v 1.1 2014/03/04 12:07:16 obache Exp $

* Add NetBSD MI atomic_ops(3) support

--- common/umutex.h.orig	2013-10-04 20:49:16.000000000 +0000
+++ common/umutex.h
@@ -117,6 +117,34 @@ inline int32_t umtx_atomic_dec(u_atomic_
 U_NAMESPACE_END
 
 
+#elif U_HAVE_NETBSD_ATOMIC_OPS
+/*
+ * NetBSD MI atomic_ops(3)
+ */
+
+U_NAMESPACE_BEGIN
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
+U_NAMESPACE_END
+
+
 #elif U_HAVE_GCC_ATOMICS
 /*
  * gcc atomic ops. These are available on several other compilers as well.
