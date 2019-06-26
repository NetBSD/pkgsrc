$NetBSD: patch-glib_gatomic.h,v 1.1 2019/06/26 10:42:50 prlw1 Exp $

Ignore __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 as is already done
for android and linux. PR pkg/54298

--- glib/gatomic.h.orig	2019-06-10 17:47:20.000000000 +0000
+++ glib/gatomic.h
@@ -82,7 +82,7 @@ gint                    g_atomic_int_exc
 
 G_END_DECLS
 
-#if defined(G_ATOMIC_LOCK_FREE) && defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4)
+#if defined(G_ATOMIC_LOCK_FREE)
 
 /* We prefer the new C11-style atomic extension of GCC if available */
 #if defined(__ATOMIC_SEQ_CST) && !defined(__clang__)
@@ -250,7 +250,7 @@ G_END_DECLS
     (gsize) __sync_fetch_and_xor ((atomic), (val));                          \
   }))
 
-#else /* defined(G_ATOMIC_LOCK_FREE) && defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4) */
+#else /* defined(G_ATOMIC_LOCK_FREE) */
 
 #define g_atomic_int_get(atomic) \
   (g_atomic_int_get ((gint *) (atomic)))
