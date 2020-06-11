$NetBSD: patch-programs_ssl_ssl__mail__client.c,v 1.1 2020/06/11 11:43:50 nia Exp $

Make sure gethostname is available on NetBSD.

https://github.com/ARMmbed/mbedtls/pull/3422

--- programs/ssl/ssl_mail_client.c.orig	2020-04-09 13:12:23.000000000 +0000
+++ programs/ssl/ssl_mail_client.c
@@ -23,6 +23,7 @@
  * be set before config.h, which pulls in glibc's features.h indirectly.
  * Harmless on other platforms. */
 #define _POSIX_C_SOURCE 200112L
+#define _XOPEN_SOURCE 600
 
 #if !defined(MBEDTLS_CONFIG_FILE)
 #include "mbedtls/config.h"
