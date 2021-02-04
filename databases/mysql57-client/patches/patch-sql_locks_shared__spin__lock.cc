$NetBSD: patch-sql_locks_shared__spin__lock.cc,v 1.1 2021/02/04 20:26:10 adam Exp $

Fix buidling on Darwin.
https://bugs.mysql.com/bug.php?id=102288

--- sql/locks/shared_spin_lock.cc.orig	2021-02-04 09:40:46.000000000 +0000
+++ sql/locks/shared_spin_lock.cc
@@ -239,7 +239,11 @@ lock::Shared_spin_lock &lock::Shared_spi
   {
     this->spin_exclusive_lock();
   }
+#if defined(__APPLE__) || defined(__NetBSD__)
+  my_atomic_store64(&this->m_exclusive_owner, reinterpret_cast<int64>(self));
+#else
   my_atomic_store64(&this->m_exclusive_owner, self);
+#endif
   return (*this);
 }
 
