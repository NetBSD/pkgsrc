$NetBSD: patch-boost_atomic_detail_ops_gcc_sparc.hpp,v 1.2 2017/01/01 15:32:47 adam Exp $

provide a fence_before_store() for sparc, which fixes the build.

--- boost/atomic/detail/ops_gcc_sparc.hpp.orig	2017-01-01 02:18:57.000000000 +0000
+++ boost/atomic/detail/ops_gcc_sparc.hpp
@@ -36,6 +36,12 @@ struct gcc_sparc_cas_base
 {
     static BOOST_CONSTEXPR_OR_CONST bool is_always_lock_free = true;
 
+    static BOOST_FORCEINLINE void fence_before_store(memory_order order) BOOST_NOEXCEPT
+    {
+        if ((order & memory_order_release) != 0)
+            hardware_full_fence();
+    }
+
     static BOOST_FORCEINLINE void fence_before(memory_order order) BOOST_NOEXCEPT
     {
         if (order == memory_order_seq_cst)
@@ -57,6 +63,11 @@ struct gcc_sparc_cas_base
         if (order == memory_order_seq_cst)
             __asm__ __volatile__ ("membar #Sync" ::: "memory");
     }
+
+    static BOOST_FORCEINLINE void hardware_full_fence() BOOST_NOEXCEPT
+    {
+        __asm__ __volatile__ ("membar #Sync" ::: "memory");
+    }
 };
 
 template< bool Signed >
