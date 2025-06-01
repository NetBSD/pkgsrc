$NetBSD: patch-crypto_threads__pthread.c,v 1.1 2025/06/01 16:47:42 he Exp $

Fix multiple definition of fallback_atomic_exchange_n_uint64_t()
and missing definition of fallback_atomic_compare_exchange_n_uint64_t().

--- crypto/threads_pthread.c.orig	2025-02-11 14:29:27.000000000 +0000
+++ crypto/threads_pthread.c
@@ -199,7 +199,7 @@ IMPL_fallback_atomic_exchange_n(prcu_cb_
 #  define ATOMIC_EXCHANGE_N(t, p, v, o) fallback_atomic_exchange_n_##t(p, v)
 
 #  define IMPL_fallback_atomic_compare_exchange_n(t)                                  \
-    static ossl_inline int fallback_atomic_compare_exchange_n_##t(t *p, t *e, t d, s, f) \
+    static ossl_inline int fallback_atomic_compare_exchange_n_##t(t *p, t *e, t d, int s, int f) \
     {                                                                                 \
         int ret = 1;                                                                 \
         pthread_mutex_lock(&atomic_sim_lock);                                         \
@@ -211,7 +211,7 @@ IMPL_fallback_atomic_exchange_n(prcu_cb_
         return ret;                                                                   \
     }
 
-IMPL_fallback_atomic_exchange_n(uint64_t)
+IMPL_fallback_atomic_compare_exchange_n(uint64_t)
 
 #  define ATOMIC_COMPARE_EXCHANGE_N(t, p, e, d, s, f) fallback_atomic_compare_exchange_n_##t(p, e, d, s, f)
 
