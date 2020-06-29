$NetBSD: patch-src_dbinc_atomic.h,v 1.4 2020/06/29 13:24:55 ryoon Exp $

--- src/dbinc/atomic.h.orig	2017-04-13 14:06:20.000000000 +0000
+++ src/dbinc/atomic.h
@@ -73,7 +73,7 @@ typedef struct {
  * These have no memory barriers; the caller must include them when necessary.
  */
 #define	atomic_read(p)		((p)->value)
-#define	atomic_init(p, val)	((p)->value = (val))
+#define	db_atomic_init(p, val)	((p)->value = (val))
 
 #ifdef HAVE_ATOMIC_SUPPORT
 
@@ -226,7 +226,7 @@ static inline int __atomic_compare_excha
 #define	atomic_add(env, p, val)	((p)->value += (val))
 #define	atomic_compare_exchange(env, p, oldval, newval)		\
 	(DB_ASSERT(env, atomic_read(p) == (oldval)),		\
-	atomic_init(p, (newval)), 1)
+	db_atomic_init(p, (newval)), 1)
 #else
 #define	atomic_inc(env, p)	__atomic_add_int(env, p, 1)
 #define	atomic_dec(env, p)	__atomic_add_int(env, p, -1)
