$NetBSD: patch-iputils.hh,v 1.3 2017/03/31 19:41:13 fhajny Exp $

- IP_PKTINFO structure different on NetBSD than expected.
- Backport fix for SunOS segfault problem, see:
  https://github.com/PowerDNS/pdns/pull/4877

--- iputils.hh.orig	2017-01-13 08:55:55.000000000 +0000
+++ iputils.hh
@@ -38,6 +38,10 @@
 #include <boost/tuple/tuple.hpp>
 #include <boost/tuple/tuple_comparison.hpp>
 
+#if defined(IP_PKTINFO) && defined(__NetBSD__)
+#undef IP_PKTINFO
+#endif
+
 #include "namespaces.hh"
 
 #ifdef __APPLE__
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
 
