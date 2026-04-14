$NetBSD: patch-src_libsystemd_sd-bus_bus-protocol.h,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* NetBSD support

--- src/libsystemd/sd-bus/bus-protocol.h.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/bus-protocol.h
@@ -46,7 +46,9 @@ enum {
         _BUS_INVALID_ENDIAN = 0,
         BUS_LITTLE_ENDIAN   = 'l',
         BUS_BIG_ENDIAN      = 'B',
-#if (defined(__FreeBSD__) && _BYTE_ORDER == _BIG_ENDIAN) || (defined(__linux__) && __BYTE_ORDER == __BIG_ENDIAN)
+#if (defined(__FreeBSD__) && _BYTE_ORDER == _BIG_ENDIAN) || \
+    (defined(__linux__) && __BYTE_ORDER == __BIG_ENDIAN) || \
+    (defined(__NetBSD__) && _BYTE_ORDER == _BIG_ENDIAN)
         BUS_NATIVE_ENDIAN   = BUS_BIG_ENDIAN,
         BUS_REVERSE_ENDIAN  = BUS_LITTLE_ENDIAN
 #else
