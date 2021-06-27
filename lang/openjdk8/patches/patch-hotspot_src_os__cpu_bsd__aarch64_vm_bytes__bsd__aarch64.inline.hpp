$NetBSD: patch-hotspot_src_os__cpu_bsd__aarch64_vm_bytes__bsd__aarch64.inline.hpp,v 1.1 2021/06/27 18:30:26 tnn Exp $

NetBSD/evbarm-aarch64 support

--- hotspot/src/os_cpu/bsd_aarch64/vm/bytes_bsd_aarch64.inline.hpp.orig	2021-05-14 21:52:06.000000000 +0000
+++ hotspot/src/os_cpu/bsd_aarch64/vm/bytes_bsd_aarch64.inline.hpp
@@ -33,6 +33,10 @@
 #  define bswap_16(x) swap16(x)
 #  define bswap_32(x) swap32(x)
 #  define bswap_64(x) swap64(x)
+#elif defined(__NetBSD__)
+#  define bswap_16(x) bswap16(x)
+#  define bswap_32(x) bswap32(x)
+#  define bswap_64(x) bswap64(x)
 #endif
 
 // Efficient swapping of data bytes from Java byte
