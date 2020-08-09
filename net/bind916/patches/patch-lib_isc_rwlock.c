$NetBSD: patch-lib_isc_rwlock.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/rwlock.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/rwlock.c
@@ -142,6 +142,9 @@ isc_rwlock_destroy(isc_rwlock_t *rwl) {
 #define RWLOCK_MAX_ADAPTIVE_COUNT 100
 #endif /* ifndef RWLOCK_MAX_ADAPTIVE_COUNT */
 
+#ifdef __lint__
+# define isc_rwlock_pause()
+#else
 #if defined(_MSC_VER)
 #include <intrin.h>
 #define isc_rwlock_pause() YieldProcessor()
@@ -152,7 +155,7 @@ isc_rwlock_destroy(isc_rwlock_t *rwl) {
 #define isc_rwlock_pause() __asm__ __volatile__("rep; nop")
 #elif defined(__ia64__)
 #define isc_rwlock_pause() __asm__ __volatile__("hint @pause")
-#elif defined(__arm__) && HAVE_ARM_YIELD
+#elif defined(__arm__) && (defined(_ARM_ARCH_6) || HAVE_ARM_YIELD)
 #define isc_rwlock_pause() __asm__ __volatile__("yield")
 #elif defined(sun) && (defined(__sparc) || defined(__sparc__))
 #define isc_rwlock_pause() smt_pause()
@@ -164,6 +167,7 @@ isc_rwlock_destroy(isc_rwlock_t *rwl) {
 #else /* if defined(_MSC_VER) */
 #define isc_rwlock_pause()
 #endif /* if defined(_MSC_VER) */
+#endif
 
 static isc_result_t
 isc__rwlock_lock(isc_rwlock_t *rwl, isc_rwlocktype_t type);
