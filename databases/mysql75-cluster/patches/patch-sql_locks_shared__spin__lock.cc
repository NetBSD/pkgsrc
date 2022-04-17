$NetBSD: patch-sql_locks_shared__spin__lock.cc,v 1.1 2022/04/17 04:07:14 jnemeth Exp $

--- sql/locks/shared_spin_lock.cc.orig	2021-09-14 09:08:08.000000000 +0000
+++ sql/locks/shared_spin_lock.cc
@@ -239,7 +239,7 @@ lock::Shared_spin_lock &lock::Shared_spi
   {
     this->spin_exclusive_lock();
   }
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
   my_atomic_store64(&this->m_exclusive_owner, reinterpret_cast<int64>(self));
 #else
   my_atomic_store64(&this->m_exclusive_owner, self);
