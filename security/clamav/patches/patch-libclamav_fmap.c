$NetBSD: patch-libclamav_fmap.c,v 1.6 2025/08/31 14:49:46 bouyer Exp $

rename gets to my_gets to avoid conflict with fortify/ssp - they use
macros to override libc functions

--- libclamav/fmap.c.orig	2025-06-17 03:41:15.000000000 +0200
+++ libclamav/fmap.c	2025-08-23 16:36:47.062952967 +0200
@@ -428,7 +428,7 @@
     m->unmap           = unmap_handle;
     m->need            = handle_need;
     m->need_offstr     = handle_need_offstr;
-    m->gets            = handle_gets;
+    m->my_gets         = handle_gets;
     m->unneed_off      = handle_unneed_off;
     m->handle_is_fd    = true;
     m->have_md5        = false;
@@ -857,7 +857,7 @@
     m->unmap       = unmap_malloc;
     m->need        = mem_need;
     m->need_offstr = mem_need_offstr;
-    m->gets        = mem_gets;
+    m->my_gets     = mem_gets;
     m->unneed_off  = mem_unneed_off;
 
     if (NULL != name) {
