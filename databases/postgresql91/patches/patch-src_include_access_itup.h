$NetBSD: patch-src_include_access_itup.h,v 1.1 2012/10/07 10:24:54 marino Exp $

GCC 4.7 fails on nbtree.h:509:16 with this message:
error: variably modified 'items' at file scope
It does like defining records with "variable" array lengths
Use the enum trick to convertMaxIndexTuplesPerPage into a constant

--- src/include/access/itup.h.orig	2012-09-19 21:50:31.000000000 +0000
+++ src/include/access/itup.h
@@ -133,10 +133,13 @@ typedef IndexAttributeBitMapData *IndexA
  * IndexTupleData struct.  We arrive at the divisor because each tuple
  * must be maxaligned, and it must have an associated item pointer.
  */
-#define MaxIndexTuplesPerPage	\
-	((int) ((BLCKSZ - SizeOfPageHeaderData) / \
-			(MAXALIGN(sizeof(IndexTupleData) + 1) + sizeof(ItemIdData))))
+#define MaxIndexTuplesPerPageInt \
+	(BLCKSZ - SizeOfPageHeaderData) / \
+                (MAXALIGN(sizeof(IndexTupleData) + 1) + sizeof(ItemIdData))
 
+enum {
+	MaxIndexTuplesPerPage = MaxIndexTuplesPerPageInt
+};
 
 /* routines in indextuple.c */
 extern IndexTuple index_form_tuple(TupleDesc tupleDescriptor,
