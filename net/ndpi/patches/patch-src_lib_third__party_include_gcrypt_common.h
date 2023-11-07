$NetBSD: patch-src_lib_third__party_include_gcrypt_common.h,v 1.1 2023/11/07 22:31:11 he Exp $

Don't conditionalize definition of bswap_64().
This leaves it undefined on macppc, and you get link errors.

--- src/lib/third_party/include/gcrypt/common.h.orig	2023-02-01 17:29:59.000000000 +0000
+++ src/lib/third_party/include/gcrypt/common.h
@@ -53,9 +53,7 @@
 
   #include <sys/types.h>
   #include <machine/bswap.h>
-  #if defined(__BSWAP_RENAME) && !defined(__bswap_32)
   #define bswap_64(x) bswap64(x)
-  #endif
 #elif defined(__MINGW32__) || defined(__MINGW64__)
   #define bswap_64(x) __builtin_bswap64(x)
 #else
