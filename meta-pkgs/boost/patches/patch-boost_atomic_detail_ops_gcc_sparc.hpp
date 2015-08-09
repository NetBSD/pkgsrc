$NetBSD: patch-boost_atomic_detail_ops_gcc_sparc.hpp,v 1.1 2015/08/09 07:59:05 mrg Exp $

provide a fence_before_store() for sparc, which fixes the build.

--- boost/atomic/detail/ops_gcc_sparc.hpp.orig	2015-08-09 05:20:41.000000000 +1000
+++ boost/atomic/detail/ops_gcc_sparc.hpp	2015-08-08 17:54:11.000000000 +1000
@@ -34,6 +34,12 @@
 
 struct gcc_sparc_cas_base
 {
+    static BOOST_FORCEINLINE void fence_before_store(memory_order order) BOOST_NOEXCEPT
+    {
+        if ((order & memory_order_release) != 0)
+            hardware_full_fence();
+    }
+
     static BOOST_FORCEINLINE void fence_before(memory_order order) BOOST_NOEXCEPT
     {
         if (order == memory_order_seq_cst)
@@ -55,6 +61,11 @@
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
