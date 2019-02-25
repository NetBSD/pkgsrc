$NetBSD: patch-libvncclient_tls__openssl.c,v 1.1 2019/02/25 09:48:26 jperkin Exp $

Bump _XOPEN_SOURCE to the same as other files to avoid C99 issues.

--- libvncclient/tls_openssl.c.orig	2019-01-06 19:09:30.000000000 +0000
+++ libvncclient/tls_openssl.c
@@ -19,7 +19,7 @@
  */
 
 #ifndef _MSC_VER
-#define _XOPEN_SOURCE 500
+#define _XOPEN_SOURCE 600
 #endif
 
 #include <rfb/rfbclient.h>
