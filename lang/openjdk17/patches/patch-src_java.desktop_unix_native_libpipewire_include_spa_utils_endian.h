$NetBSD: patch-src_java.desktop_unix_native_libpipewire_include_spa_utils_endian.h,v 1.1 2025/08/12 14:50:46 ryoon Exp $

--- src/java.desktop/unix/native/libpipewire/include/spa/utils/endian.h.orig	2025-07-29 16:00:36.439499169 +0000
+++ src/java.desktop/unix/native/libpipewire/include/spa/utils/endian.h
@@ -10,6 +10,12 @@
 #define bswap_16 bswap16
 #define bswap_32 bswap32
 #define bswap_64 bswap64
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
 #elif defined(_MSC_VER) && defined(_WIN32)
 #include <stdlib.h>
 #define __LITTLE_ENDIAN 1234
