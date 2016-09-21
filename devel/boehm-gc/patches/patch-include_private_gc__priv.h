$NetBSD: patch-include_private_gc__priv.h,v 1.1 2016/09/21 17:59:11 maya Exp $

Fix 'unknown type name GC_INNER' compilation error (FreeBSD)
from https://github.com/ivmai/bdwgc/commit/6f4e123e34c2e20343a84b6fadd17bde0e7b354c

--- include/private/gc_priv.h.orig	2016-08-02 19:36:14.000000000 +0000
+++ include/private/gc_priv.h
@@ -2500,6 +2500,8 @@ GC_INNER ptr_t GC_store_debug_info(ptr_t
 # if !defined(PCR)
 #   define NEED_FIND_LIMIT
 # endif
+  GC_INNER ptr_t GC_FreeBSDGetDataStart(size_t, ptr_t);
+# define DATASTART_IS_FUNC
 #endif /* DATASTART_USES_BSDGETDATASTART */
 
 #if (defined(NETBSD) || defined(OPENBSD)) && defined(__ELF__) \
