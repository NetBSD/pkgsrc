$NetBSD: patch-base_gsmalloc.c,v 1.1 2015/09/23 08:25:09 he Exp $

In gs_heap_alloc_bytes(), add a sanity check to ensure we don't overflow the
variable holding the actual number of bytes we allocate.

Fixes CVE-2015-3228.

--- base/gsmalloc.c.orig	2012-08-08 08:01:36.000000000 +0000
+++ base/gsmalloc.c
@@ -178,7 +178,7 @@ gs_heap_alloc_bytes(gs_memory_t * mem, u
     } else {
         uint added = size + sizeof(gs_malloc_block_t);
 
-        if (mmem->limit - added < mmem->used)
+        if (added <= size || mmem->limit - added < mmem->used)
             set_msg("exceeded limit");
         else if ((ptr = (byte *) Memento_label(malloc(added), cname)) == 0)
             set_msg("failed");
