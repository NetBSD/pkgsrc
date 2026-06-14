$NetBSD: patch-gdc__pie.c,v 1.1 2026/06/14 15:56:38 nia Exp $

Fix arguments of qsort comparator function to appease modern GCC.

--- gdc_pie.c.orig	2004-12-17 18:12:13.000000000 +0000
+++ gdc_pie.c
@@ -77,9 +77,10 @@ static int
  * comparing across 0-360 line
 \* ------------------------------------------------------- */
 static int
-ocmpr( struct tmp_slice_t *a,
-	   struct tmp_slice_t *b )
+ocmpr( const void *arg1, const void *arg2 )
 {
+	const struct tmp_slice_t *a = arg1;
+	const struct tmp_slice_t *b = arg2;
 	if( RAD_DIST1(a->angle) < RAD_DIST2(b->angle) )
 		return 1;
 	if( RAD_DIST1(a->angle) > RAD_DIST2(b->angle) )
