$NetBSD: patch-irr_src_os.cpp,v 1.1 2024/08/12 15:16:03 ktnb Exp $

Add NetBSD's endian functions

--- irr/src/os.cpp.orig	2024-08-12 14:23:31.809803900 +0000
+++ irr/src/os.cpp
@@ -31,6 +31,11 @@
 #define bswap_16(X) letoh16(X)
 #define bswap_32(X) letoh32(X)
 #define bswap_64(X) letoh64(X)
+#elif defined(__NetBSD__)
+#include <endian.h>
+#define bswap_16(X) htole16(X)
+#define bswap_32(X) htole32(X)
+#define bswap_64(X) htole64(X)
 #elif !defined(_IRR_SOLARIS_PLATFORM_) && !defined(__PPC__) && !defined(_IRR_WINDOWS_API_)
 #include <byteswap.h>
 #else
