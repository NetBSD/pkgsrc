$NetBSD: patch-glib_gatomic.c,v 1.2 2020/03/04 15:11:48 wiz Exp $

Ignore __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 as is already done
for android and linux. PR pkg/54298

--- glib/gatomic.c.orig	2020-02-27 16:12:52.000000000 +0000
+++ glib/gatomic.c
@@ -94,8 +94,6 @@
  * implement the atomic operations in a lock-free manner.
  */
 
-#if defined (__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4)
-
 /**
  * g_atomic_int_get:
  * @atomic: a pointer to a #gint or #guint
@@ -658,14 +656,6 @@ gsize
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
 
