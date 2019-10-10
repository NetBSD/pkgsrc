$NetBSD: patch-libclamav_fmap.c,v 1.2 2019/10/10 15:41:30 prlw1 Exp $

rename gets to my_gets to avoid conflict with fortify/ssp - they use
macros to override libc functions

--- libclamav/fmap.c.orig	2019-10-01 17:24:09.000000000 +0000
+++ libclamav/fmap.c
@@ -278,7 +278,7 @@ extern cl_fmap_t *cl_fmap_open_handle(vo
     m->unmap           = use_aging ? unmap_mmap : unmap_malloc;
     m->need            = handle_need;
     m->need_offstr     = handle_need_offstr;
-    m->gets            = handle_gets;
+    m->my_gets         = handle_gets;
     m->unneed_off      = handle_unneed_off;
     return m;
 }
@@ -674,7 +674,7 @@ extern cl_fmap_t *cl_fmap_open_memory(co
     m->unmap       = unmap_malloc;
     m->need        = mem_need;
     m->need_offstr = mem_need_offstr;
-    m->gets        = mem_gets;
+    m->my_gets     = mem_gets;
     m->unneed_off  = mem_unneed_off;
     return m;
 }
