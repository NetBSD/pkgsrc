$NetBSD: patch-library_net__sockets.c,v 1.3 2020/06/11 11:43:50 nia Exp $

Make sure sockaddr_storage and socklen_t are available on NetBSD.

https://github.com/ARMmbed/mbedtls/pull/3422

--- library/net_sockets.c.orig	2020-04-09 13:12:23.000000000 +0000
+++ library/net_sockets.c
@@ -23,6 +23,7 @@
  * be set before config.h, which pulls in glibc's features.h indirectly.
  * Harmless on other platforms. */
 #define _POSIX_C_SOURCE 200112L
+#define _XOPEN_SOURCE 600 /* sockaddr_storage */
 
 #if !defined(MBEDTLS_CONFIG_FILE)
 #include "mbedtls/config.h"
@@ -319,7 +320,8 @@ int mbedtls_net_accept( mbedtls_net_cont
     struct sockaddr_storage client_addr;
 
 #if defined(__socklen_t_defined) || defined(_SOCKLEN_T) ||  \
-    defined(_SOCKLEN_T_DECLARED) || defined(__DEFINED_socklen_t)
+    defined(_SOCKLEN_T_DECLARED) || defined(__DEFINED_socklen_t) || \
+    defined(socklen_t)
     socklen_t n = (socklen_t) sizeof( client_addr );
     socklen_t type_len = (socklen_t) sizeof( type );
 #else
