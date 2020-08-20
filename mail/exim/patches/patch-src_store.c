$NetBSD: patch-src_store.c,v 1.1 2020/08/20 16:40:57 gavan Exp $

--- src/store.c.orig	2020-05-30 20:35:38.000000000 +0000
+++ src/store.c
@@ -188,14 +188,14 @@ for (int pool = POOL_TAINT_BASE; pool < 
   if ((b = current_block[pool]))
     {
     uschar * bc = US b + ALIGNED_SIZEOF_STOREBLOCK;
-    if (US p >= bc && US p <= bc + b->length) return TRUE;
+    if (US p >= bc && US p < bc + b->length) return TRUE;
     }
 
 for (int pool = POOL_TAINT_BASE; pool < nelem(chainbase); pool++)
   for (b = chainbase[pool]; b; b = b->next)
     {
     uschar * bc = US b + ALIGNED_SIZEOF_STOREBLOCK;
-    if (US p >= bc && US p <= bc + b->length) return TRUE;
+    if (US p >= bc && US p < bc + b->length) return TRUE;
     }
 return FALSE;
 }
