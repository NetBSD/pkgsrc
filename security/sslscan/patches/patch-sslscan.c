$NetBSD: patch-sslscan.c,v 1.1.1.1 2013/11/19 12:46:07 tron Exp $

Fix build.

--- sslscan.c.orig	2009-09-01 13:35:59.000000000 +0100
+++ sslscan.c	2013-11-19 12:44:42.000000000 +0000
@@ -41,6 +41,7 @@
 #include <openssl/pkcs12.h>
 #include <openssl/x509.h>
 #include <openssl/x509v3.h>
+#include <netinet/in.h>
 
 // Defines...
 #define false 0
