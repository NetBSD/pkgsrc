$NetBSD: patch-glib_gatomic.c,v 1.1 2019/06/26 10:42:50 prlw1 Exp $

Ignore __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 as is already done
for android and linux. PR pkg/54298

--- glib/gatomic.c.orig	2019-06-10 17:47:20.000000000 +0000
+++ glib/gatomic.c
@@ -94,8 +94,6 @@
  * implement the atomic operations in a lock-free manner.
  */
 
-#if defined (__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4)
-
 #if defined(__ATOMIC_SEQ_CST) && !defined(__clang__)
 /* The implementation used in this code path in gatomic.h assumes
  * 4-byte int */
@@ -667,14 +665,6 @@ gsize
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
 
