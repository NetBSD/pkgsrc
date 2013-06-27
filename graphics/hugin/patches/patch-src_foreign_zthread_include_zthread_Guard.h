$NetBSD: patch-src_foreign_zthread_include_zthread_Guard.h,v 1.1 2013/06/27 15:51:49 joerg Exp $

--- src/foreign/zthread/include/zthread/Guard.h.orig	2013-06-25 21:56:26.000000000 +0000
+++ src/foreign/zthread/include/zthread/Guard.h
@@ -108,7 +108,7 @@ class CompoundScope {
   }
 
   template <class LockType>
-  static void createScope(LockHolder<LockType>& l, unsigned long ms) {
+  static bool createScope(LockHolder<LockType>& l, unsigned long ms) {
 
     if(Scope1::createScope(l, ms))
       if(!Scope2::createScope(l, ms)) {
@@ -428,7 +428,7 @@ public:
   template <class U, class V>
   Guard(Guard<U, V>& g) : LockHolder<LockType>(g) {
 
-    LockingPolicy::shareScope(*this, extract(g));
+    LockingPolicy::shareScope(*this, this->extract(g));
     
   }
 
