$NetBSD: patch-cachecleaner.hh,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- cachecleaner.hh.orig	2010-09-21 16:22:09.000000000 +0000
+++ cachecleaner.hh
@@ -18,7 +18,7 @@ template <typename T> void pruneCollecti
 //  cout<<"Need to trim "<<toTrim<<" from cache to meet target!\n";
 
   typedef typename T::template nth_index<1>::type sequence_t;
-  sequence_t& sidx=collection.get<1>();
+  sequence_t& sidx=get<1>(collection);
 
   unsigned int tried=0, lookAt, erased=0;
 
@@ -62,8 +62,8 @@ template <typename T> void pruneCollecti
 template <typename T> void moveCacheItemToFrontOrBack(T& collection, typename T::iterator& iter, bool front)
 {
   typedef typename T::template nth_index<1>::type sequence_t;
-  sequence_t& sidx=collection.get<1>();
-  typename sequence_t::iterator si=collection.project<1>(iter);
+  sequence_t& sidx=get<1>(collection);
+  typename sequence_t::iterator si=project<1>(collection, iter);
   if(front)
     sidx.relocate(sidx.begin(), si); // at the beginning of the delete queue
   else
