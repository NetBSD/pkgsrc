$NetBSD: patch-external_mysql-connector-cpp_config.h,v 1.1 2018/07/20 09:36:19 bouyer Exp $

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
