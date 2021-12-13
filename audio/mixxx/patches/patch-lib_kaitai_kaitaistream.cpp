$NetBSD: patch-lib_kaitai_kaitaistream.cpp,v 1.1 2021/12/13 17:24:38 nia Exp $

Portability...

--- lib/kaitai/kaitaistream.cpp.orig	2021-09-29 13:23:02.000000000 +0000
+++ lib/kaitai/kaitaistream.cpp
@@ -17,9 +17,17 @@
 #define bswap_16(x) _byteswap_ushort(x)
 #define bswap_32(x) _byteswap_ulong(x)
 #define bswap_64(x) _byteswap_uint64(x)
-#else // !__APPLE__ or !_MSC_VER
+#elif defined(__linux__)
 #include <endian.h>
 #include <byteswap.h>
+#else // !__APPLE__ or !_MSC_VER
+#include <endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
+#define __BYTE_ORDER    BYTE_ORDER
+#define __BIG_ENDIAN    BIG_ENDIAN
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
 #endif
 
 #include <iostream>
