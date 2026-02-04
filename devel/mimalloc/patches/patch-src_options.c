$NetBSD: patch-src_options.c,v 1.1 2026/02/04 16:12:43 adam Exp $

https://github.com/microsoft/mimalloc/issues/1219

--- src/options.c.orig	2026-02-04 16:09:06.364196291 +0000
+++ src/options.c
@@ -136,11 +136,7 @@ static mi_option_desc_t mi_options[_mi_option_last] =
   { 0, MI_OPTION_UNINIT, MI_OPTION(deprecated_page_reset) },      // reset page memory on free
   { 0, MI_OPTION_UNINIT, MI_OPTION(deprecated_abandoned_page_purge) }, 
   { 0, MI_OPTION_UNINIT, MI_OPTION(deprecated_segment_reset) },   // reset segment memory on free (needs eager commit)
-#if defined(__NetBSD__)
-  { 0, MI_OPTION_UNINIT, MI_OPTION(eager_commit_delay) },         // the first N segments per thread are not eagerly committed
-#else
   { 1, MI_OPTION_UNINIT, MI_OPTION(deprecated_eager_commit_delay) },  
-#endif
   { 1000,MI_OPTION_UNINIT, MI_OPTION_LEGACY(purge_delay,reset_delay) },  // purge delay in milli-seconds
   { 0,   MI_OPTION_UNINIT, MI_OPTION(use_numa_nodes) },           // 0 = use available numa nodes, otherwise use at most N nodes.
   { 0,   MI_OPTION_UNINIT, MI_OPTION_LEGACY(disallow_os_alloc,limit_os_alloc) },           // 1 = do not use OS memory for allocation (but only reserved arenas)
