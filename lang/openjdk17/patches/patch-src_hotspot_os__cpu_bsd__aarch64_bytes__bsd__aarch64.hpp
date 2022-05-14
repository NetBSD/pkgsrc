$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_bytes__bsd__aarch64.hpp,v 1.1 2022/05/14 15:23:02 tnn Exp $

NetBSD/evbarm support

--- src/hotspot/os_cpu/bsd_aarch64/bytes_bsd_aarch64.hpp.orig	2022-04-23 02:25:56.000000000 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/bytes_bsd_aarch64.hpp
@@ -34,6 +34,10 @@
   #define bswap_16(x) swap16(x)
   #define bswap_32(x) swap32(x)
   #define bswap_64(x) swap64(x)
+#elif defined(__NetBSD__)
+  #define bswap_16(x) bswap16(x)
+  #define bswap_32(x) bswap32(x)
+  #define bswap_64(x) bswap64(x)
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
 #  define bswap_16(x) OSSwapInt16(x)
