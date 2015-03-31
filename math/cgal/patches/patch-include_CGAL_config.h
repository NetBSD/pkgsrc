$NetBSD: patch-include_CGAL_config.h,v 1.1 2015/03/31 15:48:32 joerg Exp $

--- include/CGAL/config.h.orig	2015-03-27 19:26:56.000000000 +0000
+++ include/CGAL/config.h
@@ -109,6 +109,15 @@
 #  else
 #    error Unknown endianness
 #  endif
+#elif defined(__NetBSD__)
+#  include <sys/endian.h>
+#  if _BYTE_ORDER == _LITTLE_ENDIAN
+#    define CGAL_LITTLE_ENDIAN
+#  elif _BYTE_ORDER == _BIG_ENDIAN
+#    define CGAL_BIG_ENDIAN
+#  else
+#  error Unknown endianness
+#  endif
 #elif defined(__sparc) || defined(__sparc__) \
    || defined(_POWER) || defined(__powerpc__) \
    || defined(__ppc__) || defined(__hppa) \
