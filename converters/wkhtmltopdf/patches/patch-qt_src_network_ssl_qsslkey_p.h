--- qt/src/network/ssl/qsslkey_p.h.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslkey_p.h	2020-04-23 17:34:53.485308089 +0200
@@ -42,8 +42,10 @@
 
 #ifndef QSSLKEY_P_H
 #define QSSLKEY_P_H
 
+#define OPENSSL_API_COMPAT 0x10000000L
+
 #include "qsslkey.h"
 
 //
 //  W A R N I N G
