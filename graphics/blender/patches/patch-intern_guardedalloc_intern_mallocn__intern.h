$NetBSD: patch-intern_guardedalloc_intern_mallocn__intern.h,v 1.1 2014/04/07 12:21:25 ryoon Exp $

--- intern/guardedalloc/intern/mallocn_intern.h.orig	2014-03-19 22:05:25.000000000 +0000
+++ intern/guardedalloc/intern/mallocn_intern.h
@@ -62,6 +62,8 @@
 #elif defined(WIN32)
 #  include <malloc.h>
 #  define malloc_usable_size _msize
+#elif defined(__NetBSD__)
+#  define malloc_usable_size(x) 0
 #else
 #  error "We don't know how to use malloc_usable_size on your platform"
 #endif
