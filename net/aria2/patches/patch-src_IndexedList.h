$NetBSD: patch-src_IndexedList.h,v 1.2 2013/06/09 02:11:34 ryoon Exp $

--- src/IndexedList.h.orig	2013-05-26 07:23:55.000000000 +0000
+++ src/IndexedList.h
@@ -64,7 +64,7 @@ struct IndexedListIterator {
   typedef ValueType value_type;
   typedef PointerType pointer;
   typedef ReferenceType reference;
-  typedef typename SeqIteratorType::size_type size_type;
+  typedef typename SeqType::size_type size_type;
   typedef typename SeqIteratorType::difference_type difference_type;
   typedef IndexedListIterator SelfType;
 
