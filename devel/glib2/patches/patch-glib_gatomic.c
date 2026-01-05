$NetBSD: patch-glib_gatomic.c,v 1.3 2026/01/05 12:44:55 adam Exp $

Ignore __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 as is already done
for android and linux. PR pkg/54298

--- glib/gatomic.c.orig	2025-12-08 15:46:06.000000000 +0000
+++ glib/gatomic.c
@@ -53,8 +53,6 @@
  * implement the atomic operations in a lock-free manner.
  */
 
-#if defined (__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4)
-
 /**
  * g_atomic_int_get:
  * @atomic: (type gconstpointer): a pointer to a #gint or #guint
@@ -836,14 +834,6 @@ guintptr
   return InterlockedXor (atomic, val);
 #endif
 }
-#else
-
-/* This error occurs when `meson configure` decided that we should be capable
- * of lock-free atomics but we find at compile-time that we are not.
- */
-#error G_ATOMIC_LOCK_FREE defined, but incapable of lock-free atomics.
-
-#endif /* defined (__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4) */
 
 #else /* G_ATOMIC_LOCK_FREE */
 
