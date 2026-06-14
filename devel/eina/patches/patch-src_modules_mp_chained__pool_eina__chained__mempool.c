$NetBSD: patch-src_modules_mp_chained__pool_eina__chained__mempool.c,v 1.1 2026/06/14 13:03:52 nia Exp $

Rename "alignof" variable so it doesn't conflict with a gcc builtin.

--- src/modules/mp/chained_pool/eina_chained_mempool.c.orig	2026-06-14 13:00:40.383117004 +0000
+++ src/modules/mp/chained_pool/eina_chained_mempool.c
@@ -122,7 +122,7 @@ _eina_chained_mp_pool_new(Chained_Mempool *pool)
 {
    Chained_Pool *p;
    unsigned char *ptr;
-   unsigned int alignof;
+   unsigned int my_alignof;
 
    eina_error_set(0);
    p = malloc(pool->alloc_size);
@@ -146,8 +146,8 @@ _eina_chained_mp_pool_new(Chained_Mempool *pool)
    }
 #endif
 
-   alignof = eina_mempool_alignof(sizeof(Chained_Pool));
-   ptr = (unsigned char *)p + alignof;
+   my_alignof = eina_mempool_alignof(sizeof(Chained_Pool));
+   ptr = (unsigned char *)p + my_alignof;
    p->usage = 0;
    p->base = NULL;
 
@@ -155,7 +155,7 @@ _eina_chained_mp_pool_new(Chained_Mempool *pool)
    p->limit = ptr + pool->item_alloc * pool->pool_size;
 
 #ifndef NVALGRIND
-   VALGRIND_MAKE_MEM_NOACCESS(ptr, pool->alloc_size - alignof);
+   VALGRIND_MAKE_MEM_NOACCESS(ptr, pool->alloc_size - my_alignof);
 #endif
 
    return p;
