$NetBSD: patch-include_asterisk_lock.h,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- include/asterisk/lock.h.orig	2011-01-31 07:52:48.000000000 +0000
+++ include/asterisk/lock.h
@@ -569,7 +569,7 @@ static void  __attribute__((destructor))
 
 #define gethostbyname __gethostbyname__is__not__reentrant__use__ast_gethostbyname__instead__
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__DragonFly__)
 #define pthread_create __use_ast_pthread_create_instead__
 #endif
 
@@ -591,6 +591,10 @@ int ast_atomic_fetchadd_int_slow(volatil
 #include "libkern/OSAtomic.h"
 #endif
 
+#if defined(HAVE_SYS_ATOMIC_H)
+#include <sys/atomic.h>
+#endif
+
 /*! \brief Atomically add v to *p and return * the previous value of *p.
  * This can be used to handle reference counts, and the return value
  * can be used to generate unique identifiers.
@@ -610,6 +614,12 @@ AST_INLINE_API(int ast_atomic_fetchadd_i
 AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
 {
 	return OSAtomicAdd64(v, (int64_t *) p) - v;
+})
+#elif defined(HAVE_SYS_ATOMIC_H)
+AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
+{
+	return atomic_add_int_nv((unsigned int *)p, v) - v;
+})
 #elif defined (__i386__) || defined(__x86_64__)
 #ifdef sun
 AST_INLINE_API(int ast_atomic_fetchadd_int(volatile int *p, int v),
@@ -656,6 +666,12 @@ AST_INLINE_API(int ast_atomic_dec_and_te
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
