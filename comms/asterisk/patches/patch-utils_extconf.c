$NetBSD: patch-utils_extconf.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- utils/extconf.c.orig	2012-08-01 02:26:53.000000000 +0000
+++ utils/extconf.c
@@ -795,6 +795,10 @@ static void  __attribute__((destructor))
 #include "libkern/OSAtomic.h"
 #endif
 
+#if defined(HAVE_SYS_ATOMIC_H)
+#include <sys/atomic.h>
+#endif
+
 /*! \brief Atomically add v to *p and return * the previous value of *p.
  * This can be used to handle reference counts, and the return value
  * can be used to generate unique identifiers.
@@ -808,12 +812,18 @@ AST_INLINE_API(int ast_atomic_fetchadd_i
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
@@ -855,6 +865,12 @@ AST_INLINE_API(int ast_atomic_dec_and_te
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
