$NetBSD: patch-libclamav_fmap.c,v 1.1 2017/07/24 09:39:42 maya Exp $

rename gets to my_gets to avoid conflict with fortify/ssp - they use
macros to override libc functions

--- libclamav/fmap.c.orig	2016-04-22 15:02:19.000000000 +0000
+++ libclamav/fmap.c
@@ -274,7 +274,7 @@ extern cl_fmap_t *cl_fmap_open_handle(vo
     m->unmap = use_aging ? unmap_mmap : unmap_malloc;
     m->need = handle_need;
     m->need_offstr = handle_need_offstr;
-    m->gets = handle_gets;
+    m->my_gets = handle_gets;
     m->unneed_off = handle_unneed_off;
     return m;
 }
@@ -664,7 +664,7 @@ extern cl_fmap_t *cl_fmap_open_memory(co
     m->unmap = unmap_malloc;
     m->need = mem_need;
     m->need_offstr = mem_need_offstr;
-    m->gets = mem_gets;
+    m->my_gets = mem_gets;
     m->unneed_off = mem_unneed_off;
     return m;
 }
