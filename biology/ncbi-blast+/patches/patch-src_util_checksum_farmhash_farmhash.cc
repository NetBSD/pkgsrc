$NetBSD: patch-src_util_checksum_farmhash_farmhash.cc,v 1.1 2023/05/28 22:48:27 bacon Exp $

Ensure bswap_32() and bswap_64() gets defined on NetBSD.

--- src/util/checksum/farmhash/farmhash.cc.orig	2018-09-26 12:38:06.000000000 +0000
+++ src/util/checksum/farmhash/farmhash.cc
@@ -158,12 +158,12 @@
 
 #include <sys/types.h>
 #include <machine/bswap.h>
-#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
+#if defined(bswap_32) && defined(bswap_64)
 #undef bswap_32
 #undef bswap_64
+#endif
 #define bswap_32(x) bswap32(x)
 #define bswap_64(x) bswap64(x)
-#endif
 
 #elif defined(__HAIKU__)
 
