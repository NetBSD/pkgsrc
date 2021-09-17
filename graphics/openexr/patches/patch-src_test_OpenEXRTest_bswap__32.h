$NetBSD: patch-src_test_OpenEXRTest_bswap__32.h,v 1.1 2021/09/17 05:35:01 martin Exp $

Simply use <sys/bswap.h> for all NetBSD architectures.

Upstream: https://github.com/AcademySoftwareFoundation/openexr/pull/1147

--- src/test/OpenEXRTest/bswap_32.h.orig	2021-07-31 21:57:32.000000000 +0200
+++ src/test/OpenEXRTest/bswap_32.h	2021-09-17 07:00:54.974296748 +0200
@@ -20,10 +20,8 @@
 #define bswap_32(x) swap32(x)
 #elif defined(__NetBSD__)
 #include <sys/types.h>
-#include <machine/bswap.h>
-#if defined(__BSWAP_RENAME) && !defined(__bswap_32)
+#include <sys/bswap.h>
 #define bswap_32(x) bswap32(x)
-#endif
 #else
 #include <byteswap.h>
 #endif
