$NetBSD: patch-src_fch__buckets.c,v 1.1 2012/04/17 17:41:40 joerg Exp $

--- src/fch_buckets.c.orig	2012-04-17 16:58:34.000000000 +0000
+++ src/fch_buckets.c
@@ -183,7 +183,7 @@ cmph_uint32 * fch_buckets_get_indexes_so
 	// calculating offset considering a decreasing order of buckets size.
 	value = nbuckets_size[buckets->max_size];
 	nbuckets_size[buckets->max_size] = sum;
-	for(i = (int)buckets->max_size - 1; i >= 0; i--)
+	for(i = buckets->max_size; i-- > 0; )
 	{
 		sum += value;
 		value = nbuckets_size[i];
