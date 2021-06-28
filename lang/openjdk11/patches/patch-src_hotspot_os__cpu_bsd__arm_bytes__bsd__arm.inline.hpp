$NetBSD: patch-src_hotspot_os__cpu_bsd__arm_bytes__bsd__arm.inline.hpp,v 1.1 2021/06/28 22:53:05 tnn Exp $

NetBSD/evbarm fixes

--- src/hotspot/os_cpu/bsd_arm/bytes_bsd_arm.inline.hpp.orig	2021-04-24 02:47:22.000000000 +0000
+++ src/hotspot/os_cpu/bsd_arm/bytes_bsd_arm.inline.hpp
@@ -25,9 +25,15 @@
 #ifndef OS_CPU_BSD_ARM_VM_BYTES_BSD_ARM_INLINE_HPP
 #define OS_CPU_BSD_ARM_VM_BYTES_BSD_ARM_INLINE_HPP
 
+#if defined(__NetBSD__)
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+#else
 #define bswap_16(x) __bswap16(x)
 #define bswap_32(x) __bswap32(x)
 #define bswap_64(x) __bswap64(x)
+#endif
 
 // Efficient swapping of data bytes from Java byte
 // ordering to native byte ordering and vice versa.
