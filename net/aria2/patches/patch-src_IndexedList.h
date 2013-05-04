$NetBSD: patch-src_IndexedList.h,v 1.1 2013/05/04 12:50:38 joerg Exp $

--- src/IndexedList.h.orig	2013-05-03 11:55:44.000000000 +0000
+++ src/IndexedList.h
@@ -68,7 +68,7 @@ struct IndexedListIterator {
   typedef ValueType value_type;
   typedef PointerType pointer;
   typedef ReferenceType reference;
-  typedef typename SeqIteratorType::size_type size_type;
+  typedef typename SeqType::size_type size_type;
   typedef typename SeqIteratorType::difference_type difference_type;
   typedef IndexedListIterator SelfType;
 
