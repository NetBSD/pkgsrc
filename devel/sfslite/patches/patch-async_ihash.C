$NetBSD: patch-async_ihash.C,v 1.1 2017/09/09 19:45:46 dholland Exp $

Use legal C++ syntax.

--- async/ihash.C~	2009-02-23 16:26:42.000000000 +0000
+++ async/ihash.C
@@ -53,7 +53,7 @@ _ihash_grow (_ihash_table *htp, const si
       nbuckets = 3;
   }
   
-  ntab = New (void * [nbuckets]);
+  ntab = New void * [nbuckets];
   bzero (ntab, nbuckets * sizeof (*ntab));
 
   for (i = 0; i < htp->buckets; i++)
