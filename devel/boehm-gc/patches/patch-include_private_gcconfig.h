$NetBSD: patch-include_private_gcconfig.h,v 1.1 2016/09/21 17:59:11 maya Exp $

Fix 'unknown type name GC_INNER' compilation error (FreeBSD)
from https://github.com/ivmai/bdwgc/commit/6f4e123e34c2e20343a84b6fadd17bde0e7b354c

--- include/private/gcconfig.h.orig	2016-08-02 19:36:14.000000000 +0000
+++ include/private/gcconfig.h
@@ -2745,11 +2745,6 @@
 # define SUNOS5SIGS
 #endif
 
-#ifdef DATASTART_USES_BSDGETDATASTART
-  GC_INNER ptr_t GC_FreeBSDGetDataStart(size_t, ptr_t);
-# define DATASTART_IS_FUNC
-#endif
-
 #if !defined(GC_EXPLICIT_SIGNALS_UNBLOCK) && defined(SUNOS5SIGS) \
     && !defined(GC_NO_PTHREAD_SIGMASK)
 # define GC_EXPLICIT_SIGNALS_UNBLOCK
