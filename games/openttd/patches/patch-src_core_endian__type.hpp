$NetBSD: patch-src_core_endian__type.hpp,v 1.1 2019/09/23 09:49:52 nia Exp $

NetBSD does not have endian definitions in param.h

--- src/core/endian_type.hpp.orig	2019-09-16 19:15:04.000000000 +0000
+++ src/core/endian_type.hpp
@@ -35,6 +35,13 @@
 #	else
 #		define TTD_ENDIAN TTD_BIG_ENDIAN
 #	endif
+#elif defined(__NetBSD__)
+#	include <sys/endian.h>
+#	if BYTE_ORDER == LITTLE_ENDIAN
+#		define TTD_ENDIAN TTD_LITTLE_ENDIAN
+#	else
+#		define TTD_ENDIAN TTD_BIG_ENDIAN
+#	endif
 #elif !defined(TESTING)
 #	include <sys/param.h>
 #	if __BYTE_ORDER == __LITTLE_ENDIAN
