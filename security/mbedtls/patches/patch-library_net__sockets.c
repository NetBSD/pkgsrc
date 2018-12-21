$NetBSD: patch-library_net__sockets.c,v 1.2 2018/12/21 09:43:00 wiz Exp $

Comment out _POSIX_C_SOURCE, this makes sockaddr_storage unavailable on NetBSD.
https://github.com/ARMmbed/mbedtls/issues/2310

--- library/net_sockets.c.orig	2018-12-02 13:20:52.000000000 +0000
+++ library/net_sockets.c
@@ -22,7 +22,7 @@
 /* Enable definition of getaddrinfo() even when compiling with -std=c99. Must
  * be set before config.h, which pulls in glibc's features.h indirectly.
  * Harmless on other platforms. */
-#define _POSIX_C_SOURCE 200112L
+//#define _POSIX_C_SOURCE 200112L
 
 #if !defined(MBEDTLS_CONFIG_FILE)
 #include "mbedtls/config.h"
