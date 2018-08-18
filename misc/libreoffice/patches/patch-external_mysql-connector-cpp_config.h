$NetBSD: patch-external_mysql-connector-cpp_config.h,v 1.1.2.2 2018/08/18 10:21:45 bsiegert Exp $

--- external/mysql-connector-cpp/config.h.orig	2018-07-19 19:35:30.087775890 +0200
+++ external/mysql-connector-cpp/config.h	2018-07-19 19:37:26.808008694 +0200
@@ -13,6 +13,10 @@
 #endif
 #endif
 
+#if defined(__NetBSD__)
+    #define HAVE_INTTYPES_H
+#endif
+
 #ifdef HAVE_STDINT_H
 #include <stdint.h>
 #endif
