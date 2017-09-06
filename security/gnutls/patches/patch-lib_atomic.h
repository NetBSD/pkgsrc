$NetBSD: patch-lib_atomic.h,v 1.1 2017/09/06 13:41:26 wiz Exp $

Fix lock arguments.
https://gitlab.com/gnutls/gnutls/commit/72d25d427078d3de5c25c3b5406b0313ffd813ab

--- lib/atomic.h.orig	2017-07-31 06:22:37.000000000 +0000
+++ lib/atomic.h
@@ -47,24 +47,24 @@ typedef struct gnutls_atomic_uint_st *gn
 inline static unsigned gnutls_atomic_val(gnutls_atomic_uint_t x)
 {
 	unsigned int t;
-	gnutls_mutex_lock(x->lock);
+	gnutls_mutex_lock(&x->lock);
 	t = x->value;
-	gnutls_mutex_unlock(x->lock);
+	gnutls_mutex_unlock(&x->lock);
 	return t;
 }
 
 inline static void gnutls_atomic_increment(gnutls_atomic_uint_t x)
 {
-	gnutls_mutex_lock(x->lock);
+	gnutls_mutex_lock(&x->lock);
 	x->value++;
-	gnutls_mutex_unlock(x->lock);
+	gnutls_mutex_unlock(&x->lock);
 }
 
 inline static void gnutls_atomic_decrement(gnutls_atomic_uint_t x)
 {
-	gnutls_mutex_lock(x->lock);
+	gnutls_mutex_lock(&x->lock);
 	x->value--;
-	gnutls_mutex_unlock(x->lock);
+	gnutls_mutex_unlock(&x->lock);
 }
 
 inline static void gnutls_atomic_init(gnutls_atomic_uint_t x)
