$NetBSD: patch-include_endian_compat.h,v 1.2 2015/10/25 09:05:23 bouyer Exp $

--- include/endian_compat.h.orig	2015-10-01 16:09:19.000000000 +0200
+++ include/endian_compat.h	2015-10-01 16:20:48.000000000 +0200
@@ -29,6 +29,8 @@
 #define le32toh(x) CFSwapInt32LittleToHost(x)
 #define htole16(x) CFSwapInt16HostToLittle(x)
 #define le16toh(x) CFSwapInt16LittleToHost(x)
+#elif defined(__NetBSD__)
+#include <sys/endian.h>
 #else
 #include <endian.h>
 #endif
