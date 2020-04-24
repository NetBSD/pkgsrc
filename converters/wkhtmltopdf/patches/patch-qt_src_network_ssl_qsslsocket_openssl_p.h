--- qt/src/network/ssl/qsslsocket_openssl_p.h.orig	2016-08-23 08:13:31.000000000 +0200
+++ qt/src/network/ssl/qsslsocket_openssl_p.h	2020-04-23 17:34:53.558228832 +0200
@@ -53,8 +53,10 @@
 //
 // We mean it.
 //
 
+#define OPENSSL_API_COMPAT 0x10000000L
+
 #include "qsslsocket_p.h"
 
 #ifdef Q_OS_WIN
 #include <qt_windows.h>
