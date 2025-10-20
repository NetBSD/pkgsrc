$NetBSD: patch-dbinc_atomic.h,v 1.3 2025/10/20 23:31:37 mrg Exp $

Don't define inline functions in the protected namespace.
This conflicts with Clang builtins.

Avoid overlap with stdatomic.h, the C++ binding uses <atomic>.

Add missing prototype for atomic_compare_exchange() in one case.


--- dbinc/atomic.h.orig	2010-04-12 13:25:22.000000000 -0700
+++ dbinc/atomic.h	2025-10-20 15:41:35.592099178 -0700
@@ -70,7 +70,7 @@ typedef struct {
  * These have no memory barriers; the caller must include them when necessary.
  */
 #define	atomic_read(p)		((p)->value)
-#define	atomic_init(p, val)	((p)->value = (val))
+#define	db_atomic_init(p, val)	((p)->value = (val))
 
 #ifdef HAVE_ATOMIC_SUPPORT
 
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
@@ -206,10 +202,14 @@ static inline int __atomic_compare_excha
 #define	atomic_dec(env, p)	(--(p)->value)
 #define	atomic_compare_exchange(env, p, oldval, newval)		\
 	(DB_ASSERT(env, atomic_read(p) == (oldval)),		\
-	atomic_init(p, (newval)), 1)
+	db_atomic_init(p, (newval)), 1)
 #else
 #define atomic_inc(env, p)	__atomic_inc(env, p)
 #define atomic_dec(env, p)	__atomic_dec(env, p)
+int atomic_compare_exchange(ENV *env,
+                            db_atomic_t *v,
+                            atomic_value_t oldval,
+			    atomic_value_t newval);
 #endif
 #endif
 
