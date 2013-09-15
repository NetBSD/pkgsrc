$NetBSD: patch-libmemcached-1.0_memcached.h,v 1.1 2013/09/15 12:28:22 joerg Exp $

--- libmemcached-1.0/memcached.h.orig	2013-09-14 17:06:48.000000000 +0000
+++ libmemcached-1.0/memcached.h
@@ -43,9 +43,13 @@
 #endif
 
 #ifdef __cplusplus
-#  include <tr1/cinttypes>
 #  include <cstddef>
 #  include <cstdlib>
+#  if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#    include <cinttypes>
+#  else
+#    include <tr1/cinttypes>
+#  endif
 #else
 #  include <inttypes.h>
 #  include <stddef.h>
