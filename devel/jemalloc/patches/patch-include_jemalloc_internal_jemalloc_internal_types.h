$NetBSD: patch-include_jemalloc_internal_jemalloc_internal_types.h,v 1.1 2019/02/17 08:40:09 mrg Exp $

add 32 bit sparc support.

--- include/jemalloc/internal/jemalloc_internal_types.h.orig	2019-02-16 23:56:29.457544064 -0800
+++ include/jemalloc/internal/jemalloc_internal_types.h	2019-02-16 23:56:03.367260510 -0800
@@ -64,7 +64,8 @@
 #  ifdef __alpha__
 #    define LG_QUANTUM		4
 #  endif
-#  if (defined(__sparc64__) || defined(__sparcv9) || defined(__sparc_v9__))
+#  if (defined(__sparc64__) || defined(__sparcv9) || defined(__sparc_v9__) || \
+	defined(__sparc__))
 #    define LG_QUANTUM		4
 #  endif
 #  if (defined(__amd64__) || defined(__x86_64__) || defined(_M_X64))
