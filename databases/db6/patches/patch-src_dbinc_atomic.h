$NetBSD: patch-src_dbinc_atomic.h,v 1.3 2017/01/26 11:03:17 adam Exp $

--- src/dbinc/atomic.h.orig	2016-03-28 19:45:54.000000000 +0000
+++ src/dbinc/atomic.h
@@ -70,7 +70,7 @@ typedef struct {
  * These have no memory barriers; the caller must include them when necessary.
  */
 #define	atomic_read(p)		((p)->value)
-#define	atomic_init(p, val)	((p)->value = (val))
+#define	db_atomic_init(p, val)	((p)->value = (val))
 
 #ifdef HAVE_ATOMIC_SUPPORT
 
@@ -225,7 +225,7 @@ static inline int __atomic_compare_excha
 #define	atomic_dec(env, p)	(--(p)->value)
 #define	atomic_compare_exchange(env, p, oldval, newval)		\
 	(DB_ASSERT(env, atomic_read(p) == (oldval)),		\
-	atomic_init(p, (newval)), 1)
+	db_atomic_init(p, (newval)), 1)
 #else
 #define	atomic_inc(env, p)	__atomic_inc_int(env, p)
 #define	atomic_dec(env, p)	__atomic_dec_int(env, p)
