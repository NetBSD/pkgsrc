$NetBSD: patch-src_portable__endian.h,v 1.1 2025/10/04 17:15:36 kikadf Exp $

* Fix build, Net-, Free- and DragonFly BSD provide be16toh, le16toh, 
  etc, so there's no need for that definitions
  https://github.com/admesh/admesh/commit/7c6ffaf9bd87aa86212ce9b131ae5282729a9702

--- src/portable_endian.h.orig	2025-10-04 15:37:51.064690701 +0000
+++ src/portable_endian.h
@@ -46,23 +46,10 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
-
-#	include <sys/endian.h>
-
-#	define be16toh(x) betoh16(x)
-#	define le16toh(x) letoh16(x)
-
-#	define be32toh(x) betoh32(x)
-#	define le32toh(x) letoh32(x)
-
-#	define be64toh(x) betoh64(x)
-#	define le64toh(x) letoh64(x)
-
 #elif defined(__WINDOWS__)
 
 /* #	include <winsock2.h> */
