$NetBSD: patch-libgearman-1.0_gearman.h,v 1.1 2013/10/10 00:04:52 joerg Exp $

--- libgearman-1.0/gearman.h.orig	2013-10-09 23:41:20.000000000 +0000
+++ libgearman-1.0/gearman.h
@@ -50,8 +50,12 @@
 #endif
 
 #ifdef __cplusplus
-#  include <tr1/cinttypes>
 #  include <cstddef>
+#  if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#  include <cinttypes>
+#  else
+#  include <tr1/cinttypes>
+#  endif
 #  include <cstdlib>
 #  include <ctime>
 #else
