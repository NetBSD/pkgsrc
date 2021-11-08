$NetBSD: patch-libclamav_fmap.c,v 1.5 2021/11/08 14:49:23 taca Exp $

rename gets to my_gets to avoid conflict with fortify/ssp - they use
macros to override libc functions

--- libclamav/fmap.c.orig	2021-11-02 15:47:47.000000000 +0000
+++ libclamav/fmap.c
@@ -426,7 +426,7 @@ extern cl_fmap_t *cl_fmap_open_handle(vo
     m->unmap           = unmap_handle;
     m->need            = handle_need;
     m->need_offstr     = handle_need_offstr;
-    m->gets            = handle_gets;
+    m->my_gets         = handle_gets;
     m->unneed_off      = handle_unneed_off;
     m->handle_is_fd    = 1;
     m->have_maphash    = false;
@@ -853,7 +853,7 @@ fmap_t *fmap_open_memory(const void *sta
     m->unmap       = unmap_malloc;
     m->need        = mem_need;
     m->need_offstr = mem_need_offstr;
-    m->gets        = mem_gets;
+    m->my_gets     = mem_gets;
     m->unneed_off  = mem_unneed_off;
 
     if (NULL != name) {
