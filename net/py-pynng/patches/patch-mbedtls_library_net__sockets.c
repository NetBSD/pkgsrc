$NetBSD: patch-mbedtls_library_net__sockets.c,v 1.1 2021/05/13 19:35:54 khorben Exp $

Fix build on NetBSD

--- mbedtls/library/net_sockets.c.orig	2020-08-27 02:34:52.000000000 +0000
+++ mbedtls/library/net_sockets.c
@@ -24,6 +24,10 @@
  * Harmless on other platforms. */
 #define _POSIX_C_SOURCE 200112L
 
+#if defined(__NetBSD__)
+# define _NETBSD_SOURCE
+#endif
+
 #if !defined(MBEDTLS_CONFIG_FILE)
 #include "mbedtls/config.h"
 #else
