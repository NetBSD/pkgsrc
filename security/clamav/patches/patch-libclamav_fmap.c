$NetBSD: patch-libclamav_fmap.c,v 1.4 2021/02/28 17:14:10 taca Exp $

rename gets to my_gets to avoid conflict with fortify/ssp - they use
macros to override libc functions

--- libclamav/fmap.c.orig	2021-02-01 20:49:26.000000000 +0000
+++ libclamav/fmap.c
@@ -424,7 +424,7 @@ extern cl_fmap_t *cl_fmap_open_handle(vo
     m->unmap           = unmap_handle;
     m->need            = handle_need;
     m->need_offstr     = handle_need_offstr;
-    m->gets            = handle_gets;
+    m->my_gets         = handle_gets;
     m->unneed_off      = handle_unneed_off;
     m->handle_is_fd    = 1;
 
@@ -849,7 +849,7 @@ fmap_t *fmap_open_memory(const void *sta
     m->unmap       = unmap_malloc;
     m->need        = mem_need;
     m->need_offstr = mem_need_offstr;
-    m->gets        = mem_gets;
+    m->my_gets     = mem_gets;
     m->unneed_off  = mem_unneed_off;
 
     if (NULL != name) {
