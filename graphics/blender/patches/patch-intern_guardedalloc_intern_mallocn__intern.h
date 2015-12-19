$NetBSD: patch-intern_guardedalloc_intern_mallocn__intern.h,v 1.2 2015/12/19 20:52:12 markd Exp $

--- intern/guardedalloc/intern/mallocn_intern.h.orig	2015-10-07 00:09:33.000000000 +0000
+++ intern/guardedalloc/intern/mallocn_intern.h
@@ -63,6 +63,8 @@
 #elif defined(WIN32)
 #  include <malloc.h>
 #  define malloc_usable_size _msize
+#elif defined(__NetBSD__)
+#  define malloc_usable_size(x) 0
 #else
 #  pragma message "We don't know how to use malloc_usable_size on your platform"
 #  undef USE_MALLOC_USABLE_SIZE
