$NetBSD: patch-src_include_access_htup.h,v 1.1 2012/10/07 10:24:54 marino Exp $

Fixes GCC 4.7 warning and error
Also see comments about similar problems in patch-src_include_access_ihup.h
htup.h:464:2: warning: variably modified 'mt_padding' at file scope
       [enabled by default]
relscan.h:51:15: error: variably modified 'rs_vistuples' at file scope

The relscan.h error is caused by the MaxHeapTuplesPerPage definition found
in htup.h.  Use enum method to satisfy gcc.

--- src/include/access/htup.h.orig	2012-09-19 21:50:31.000000000 +0000
+++ src/include/access/htup.h
@@ -16,6 +16,7 @@
 
 #include "access/tupdesc.h"
 #include "access/tupmacs.h"
+#include "storage/bufpage.h"
 #include "storage/itemptr.h"
 #include "storage/relfilenode.h"
 
@@ -405,9 +406,10 @@ do { \
  * pointers to this anyway, to avoid excessive line-pointer bloat and not
  * require increases in the size of work arrays.
  */
-#define MaxHeapTuplesPerPage	\
-	((int) ((BLCKSZ - SizeOfPageHeaderData) / \
-			(MAXALIGN(offsetof(HeapTupleHeaderData, t_bits)) + sizeof(ItemIdData))))
+#define MaxHeapTuplesPerPageInt \
+	(BLCKSZ - SizeOfPageHeaderData) / \
+		(MAXALIGN(offsetof(HeapTupleHeaderData, t_bits)) + \
+		sizeof(ItemIdData))
 
 /*
  * MaxAttrSize is a somewhat arbitrary upper limit on the declared size of
@@ -452,11 +454,16 @@ do { \
  */
 #define MINIMAL_TUPLE_OFFSET \
 	((offsetof(HeapTupleHeaderData, t_infomask2) - sizeof(uint32)) / MAXIMUM_ALIGNOF * MAXIMUM_ALIGNOF)
-#define MINIMAL_TUPLE_PADDING \
+#define MINIMAL_TUPLE_PADDING_MACRO \
 	((offsetof(HeapTupleHeaderData, t_infomask2) - sizeof(uint32)) % MAXIMUM_ALIGNOF)
 #define MINIMAL_TUPLE_DATA_OFFSET \
 	offsetof(MinimalTupleData, t_infomask2)
 
+enum {
+	MINIMAL_TUPLE_PADDING = MINIMAL_TUPLE_PADDING_MACRO,
+	MaxHeapTuplesPerPage = MaxHeapTuplesPerPageInt
+};
+
 typedef struct MinimalTupleData
 {
 	uint32		t_len;			/* actual length of minimal tuple */
