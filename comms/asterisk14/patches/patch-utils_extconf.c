$NetBSD: patch-utils_extconf.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- utils/extconf.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ utils/extconf.c
@@ -593,6 +593,10 @@ static void  __attribute__((destructor))
 #include "libkern/OSAtomic.h"
 #endif
 
+#if defined(HAVE_SYS_ATOMIC_H)
+#include <sys/atomic.h>
+#endif
+
 /*! \brief Atomically add v to *p and return * the previous value of *p.
  * This can be used to handle reference counts, and the return value
  * can be used to generate unique identifiers.
@@ -606,12 +610,18 @@ AST_INLINE_API(int ast_atomic_fetchadd_i
 #elif defined(HAVE_OSX_ATOMICS) && (SIZEOF_INT == 4)
 AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
 {
-	return OSAtomicAdd32(v, (int32_t *) p);
+	return OSAtomicAdd32(v, (int32_t *) p) - v;
 })
 #elif defined(HAVE_OSX_ATOMICS) && (SIZEOF_INT == 8)
 AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
 {
-	return OSAtomicAdd64(v, (int64_t *) p);
+	return OSAtomicAdd64(v, (int64_t *) p) - v;
+})
+#elif defined(HAVE_SYS_ATOMIC_H)
+AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
+{
+	return atomic_add_int_nv((unsigned int *)p, v) - v;
+})
 #elif defined (__i386__) || defined(__x86_64__)
 AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
 {
@@ -653,6 +663,12 @@ AST_INLINE_API(int ast_atomic_dec_and_te
 AST_INLINE_API(int ast_atomic_dec_and_test(volatile int *p),
 {
 	return OSAtomicAdd64( -1, (int64_t *) p) == 0;
+})
+#elif defined(HAVE_SYS_ATOMIC_H)
+AST_INLINE_API(int ast_atomic_dec_and_test(volatile int *p),
+{
+	return atomic_dec_uint_nv((unsigned int *)p) == 0;
+})
 #else
 AST_INLINE_API(int ast_atomic_dec_and_test(volatile int *p),
 {
@@ -2537,13 +2553,13 @@ static int ast_true(const char *s)
 static struct timeval tvfix(struct timeval a)
 {
 	if (a.tv_usec >= ONE_MILLION) {
-		ast_log(LOG_WARNING, "warning too large timestamp %ld.%ld\n",
-			(long)a.tv_sec, (long int) a.tv_usec);
+		ast_log(LOG_WARNING, "warning too large timestamp %jd.%ld\n",
+			(intmax_t)a.tv_sec, (long int) a.tv_usec);
 		a.tv_sec += a.tv_usec / ONE_MILLION;
 		a.tv_usec %= ONE_MILLION;
 	} else if (a.tv_usec < 0) {
-		ast_log(LOG_WARNING, "warning negative timestamp %ld.%ld\n",
-			(long)a.tv_sec, (long int) a.tv_usec);
+		ast_log(LOG_WARNING, "warning negative timestamp %jd.%ld\n",
+			(intmax_t)a.tv_sec, (long int) a.tv_usec);
 		a.tv_usec = 0;
 	}
 	return a;
