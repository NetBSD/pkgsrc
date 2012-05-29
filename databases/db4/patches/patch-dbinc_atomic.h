$NetBSD: patch-dbinc_atomic.h,v 1.1 2012/05/29 20:18:28 joerg Exp $

Don't define inline functions in the protected namespace.
This conflicts with Clang builtins.

--- dbinc/atomic.h.orig	2012-05-24 10:38:34.000000000 +0000
+++ dbinc/atomic.h
@@ -141,11 +141,7 @@ typedef LONG volatile *interlocked_val;
 
 #if defined(HAVE_ATOMIC_X86_GCC_ASSEMBLY)
 /* x86/x86_64 gcc  */
-#define	atomic_inc(env, p)	__atomic_inc(p)
-#define	atomic_dec(env, p)	__atomic_dec(p)
-#define	atomic_compare_exchange(env, p, o, n)	\
-	__atomic_compare_exchange((p), (o), (n))
-static inline int __atomic_inc(db_atomic_t *p)
+static inline int atomic_inc(ENV *unused, db_atomic_t *p)
 {
 	int	temp;
 
@@ -156,7 +152,7 @@ static inline int __atomic_inc(db_atomic
 	return (temp + 1);
 }
 
-static inline int __atomic_dec(db_atomic_t *p)
+static inline int atomic_dec(ENV *unused, db_atomic_t *p)
 {
 	int	temp;
 
@@ -176,7 +172,7 @@ static inline int __atomic_dec(db_atomic
  * http://gcc.gnu.org/onlinedocs/gcc-4.1.0/gcc/Atomic-Builtins.html
  * which configure could be changed to use.
  */
-static inline int __atomic_compare_exchange(
+static inline int atomic_compare_exchange(ENV *unused,
 	db_atomic_t *p, atomic_value_t oldval, atomic_value_t newval)
 {
 	atomic_value_t was;
