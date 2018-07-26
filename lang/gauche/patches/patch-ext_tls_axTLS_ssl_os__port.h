$NetBSD: patch-ext_tls_axTLS_ssl_os__port.h,v 1.1 2018/07/26 16:55:29 jperkin Exp $

Provide endian support on SunOS.

--- ext/tls/axTLS/ssl/os_port.h.orig	2017-04-14 08:07:25.000000000 +0000
+++ ext/tls/axTLS/ssl/os_port.h
@@ -162,6 +162,9 @@ EXP_FUNC int STDCALL getdomainname(char
 #define be64toh(x) OSSwapBigToHostInt64(x)
 #elif  defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/endian.h>
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define be64toh(x) BE_64(x)
 #else
 #include <asm/byteorder.h>
 #endif
