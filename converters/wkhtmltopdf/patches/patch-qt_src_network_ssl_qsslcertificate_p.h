--- qt/src/network/ssl/qsslcertificate_p.h.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslcertificate_p.h	2020-04-23 17:34:53.413950571 +0200
@@ -42,8 +42,10 @@
 
 #ifndef QSSLCERTIFICATE_P_H
 #define QSSLCERTIFICATE_P_H
 
+#define OPENSSL_API_COMPAT 0x10000000L
+
 #include "qsslcertificate.h"
 
 //
 //  W A R N I N G
