$NetBSD: patch-mbedtls_library_net__sockets.c,v 1.2 2024/08/10 07:34:38 wiz Exp $

Fix build on NetBSD

--- mbedtls/library/net_sockets.c.orig	2024-01-16 17:26:58.000000000 +0000
+++ mbedtls/library/net_sockets.c
@@ -24,6 +24,10 @@
     !defined(__HAIKU__) && !defined(__midipix__)
 #error "This module only works on Unix and Windows, see MBEDTLS_NET_C in mbedtls_config.h"
 #endif
+#if defined(__NetBSD__)
+# define _NETBSD_SOURCE
+#endif
+
 
 #include "mbedtls/platform.h"
 
