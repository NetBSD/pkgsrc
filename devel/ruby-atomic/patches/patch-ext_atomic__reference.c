$NetBSD: patch-ext_atomic__reference.c,v 1.1 2015/02/01 13:53:50 taca Exp $

* Utilize atomic_ops(3) if available.
* Try to include proper header file.

--- ext/atomic_reference.c.orig	2014-08-19 08:53:02.000000000 +0000
+++ ext/atomic_reference.c
@@ -11,12 +11,17 @@
 // limitations under the License.
 
 #include <ruby.h>
-#if defined(__sun)
-#include <atomic.h>
-#endif
 
-#ifdef HAVE_LIBKERN_OSATOMIC_H
-#include <libkern/OSAtomic.h>
+#ifdef HAVE_SYS_ATOMIC_H
+#include <sys/atomic.h>
+#else
+# ifdef HAVE_ATOMIC_H
+#  include <atomic.h>
+# else
+#  ifdef HAVE_LIBKERN_OSATOMIC_H
+#    include <libkern/OSAtomic.h>
+#  endif
+# endif
 #endif
 
 static void ir_mark(void *value) {
@@ -53,7 +58,11 @@ static VALUE ir_get_and_set(VALUE self, 
 }
 
 static VALUE ir_compare_and_set(volatile VALUE self, VALUE expect_value, VALUE new_value) {
-#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1050
+#if defined(__NetBSD__)
+    if (atomic_cas_ptr((volatile void *) &DATA_PTR(self), expect_value, new_value)) {
+	return Qtrue;
+    }
+#elif __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1050
     if (OSAtomicCompareAndSwap64(expect_value, new_value, &DATA_PTR(self))) {
 	return Qtrue;
     }
