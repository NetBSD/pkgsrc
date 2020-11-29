$NetBSD: patch-libvncclient_tls__openssl.c,v 1.2 2020/11/29 20:33:53 nia Exp $

Bump _XOPEN_SOURCE to the same as other files to avoid C99 issues.

Fix missing declaration of fd_set.

--- libvncclient/tls_openssl.c.orig	2019-01-06 19:09:30.000000000 +0000
+++ libvncclient/tls_openssl.c
@@ -19,10 +19,11 @@
  */
 
 #ifndef _MSC_VER
-#define _XOPEN_SOURCE 500
+#define _XOPEN_SOURCE 600
 #endif
 
 #include <rfb/rfbclient.h>
+#include <sys/select.h>
 #include <errno.h>
 
 #include <openssl/err.h>
