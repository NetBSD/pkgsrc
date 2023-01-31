$NetBSD: patch-src_include_gnunet_common.h,v 1.1 2023/01/31 18:53:46 nikita Exp $

Patch adopted from Debian.
Defining BYTE_SWAP_* on big endian systems to fix FTBFS.
Authored by Gianfranco Costamagna <locutusofborg@debian.org>.

--- src/include/gnunet_common.h.orig
+++ src/include/gnunet_common.h
@@ -178,6 +178,15 @@ enum GNUNET_GenericReturnValue
 #define GNUNET_le64toh(x) (x)
 #endif
 #if __BYTE_ORDER == __BIG_ENDIAN
+#ifdef HAVE_BYTESWAP_H
+#define BYTE_SWAP_16(x) bswap_16 (x)
+#define BYTE_SWAP_32(x) bswap_32 (x)
+#define BYTE_SWAP_64(x) bswap_64 (x)
+#else
+#define BYTE_SWAP_16(x) __bswap_16 (x)
+#define BYTE_SWAP_32(x) __bswap_32 (x)
+#define BYTE_SWAP_64(x) __bswap_64 (x)
+#endif
 #define GNUNET_htobe16(x) (x)
 #define GNUNET_htole16(x) BYTE_SWAP_16 (x)
 #define GNUNET_be16toh(x) (x)
