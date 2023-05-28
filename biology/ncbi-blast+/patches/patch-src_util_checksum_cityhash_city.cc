$NetBSD: patch-src_util_checksum_cityhash_city.cc,v 1.1 2023/05/28 22:48:27 bacon Exp $

Ensure bswap_32() and bswap_64() is defined on NetBSD.

--- src/util/checksum/cityhash/city.cc.orig	2018-09-28 20:34:39.000000000 +0000
+++ src/util/checksum/cityhash/city.cc
@@ -82,10 +82,8 @@ static uint32 UNALIGNED_LOAD32(const cha
 
 #include <sys/types.h>
 #include <machine/bswap.h>
-#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
 #define bswap_32(x) bswap32(x)
 #define bswap_64(x) bswap64(x)
-#endif
 
 #else
 
