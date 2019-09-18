$NetBSD: patch-intern_guardedalloc_intern_mallocn__intern.h,v 1.3 2019/09/18 23:40:17 nia Exp $

Support NetBSD.

--- intern/guardedalloc/intern/mallocn_intern.h.orig	2019-07-24 07:41:39.000000000 +0000
+++ intern/guardedalloc/intern/mallocn_intern.h
@@ -55,6 +55,8 @@
 #elif defined(__HAIKU__)
 #  include <malloc.h>
 size_t malloc_usable_size(void *ptr);
+#elif defined(__NetBSD__)
+#  define malloc_usable_size(p) (0)
 #else
 #  pragma message "We don't know how to use malloc_usable_size on your platform"
 #  undef USE_MALLOC_USABLE_SIZE
