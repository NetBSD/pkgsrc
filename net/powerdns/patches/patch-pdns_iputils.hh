$NetBSD: patch-pdns_iputils.hh,v 1.2 2017/03/29 11:46:03 fhajny Exp $

- Do not use IP_PKTINFO on NetBSD, the structure is not as expected.
- Backport fix for SunOS segfault problem, see:
  https://github.com/PowerDNS/pdns/pull/4877

--- pdns/iputils.hh.orig	2017-01-17 08:43:49.000000000 +0000
+++ pdns/iputils.hh
@@ -40,6 +40,10 @@
 
 #include "namespaces.hh"
 
+#if defined(__NetBSD__) && defined(IP_PKTINFO)
+#undef IP_PKTINFO
+#endif
+
 #ifdef __APPLE__
 #include <libkern/OSByteOrder.h>
 
@@ -59,23 +63,22 @@
 #define le64toh(x) OSSwapLittleToHostInt64(x)
 #endif
 
-// for illumos
-#ifdef BE_64
+#ifdef __sun
 
 #define htobe16(x) BE_16(x)
 #define htole16(x) LE_16(x)
-#define be16toh(x) BE_IN16(x)
-#define le16toh(x) LE_IN16(x)
+#define be16toh(x) BE_IN16(&(x))
+#define le16toh(x) LE_IN16(&(x))
 
 #define htobe32(x) BE_32(x)
 #define htole32(x) LE_32(x)
-#define be32toh(x) BE_IN32(x)
-#define le32toh(x) LE_IN32(x)
+#define be32toh(x) BE_IN32(&(x))
+#define le32toh(x) LE_IN32(&(x))
 
 #define htobe64(x) BE_64(x)
 #define htole64(x) LE_64(x)
-#define be64toh(x) BE_IN64(x)
-#define le64toh(x) LE_IN64(x)
+#define be64toh(x) BE_IN64(&(x))
+#define le64toh(x) LE_IN64(&(x))
 
 #endif
 
