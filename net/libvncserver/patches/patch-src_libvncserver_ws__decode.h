$NetBSD: patch-src_libvncserver_ws__decode.h,v 1.1 2025/05/04 09:47:19 nia Exp $

Byteswap compat for SunOS.

--- src/libvncserver/ws_decode.h.orig	2025-05-04 07:52:41.063877770 +0000
+++ src/libvncserver/ws_decode.h
@@ -13,6 +13,15 @@
 #define WS_HTON64(n) OSSwapHostToBigInt64(n)
 #define WS_HTON16(n) OSSwapHostToBigInt16(n)
 
+#elif defined(__sun)
+
+#include <sys/byteorder.h>
+#define WS_NTOH64(n) BE_64(n)
+#define WS_NTOH32(n) BE_32(n)
+#define WS_NTOH16(n) BE_16(n)
+#define WS_HTON64(n) BE_64(n)
+#define WS_HTON16(n) BE_16(n)
+
 #else
 
 #ifdef LIBVNCSERVER_HAVE_ENDIAN_H
