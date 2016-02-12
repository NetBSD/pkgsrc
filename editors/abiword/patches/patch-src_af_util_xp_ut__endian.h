$NetBSD: patch-src_af_util_xp_ut__endian.h,v 1.2 2016/02/12 23:42:15 jperkin Exp $

Support DragonFly.

--- src/af/util/xp/ut_endian.h.orig	2013-04-07 13:53:03.000000000 +0000
+++ src/af/util/xp/ut_endian.h
@@ -49,6 +49,13 @@
 	#else
 		#define UT_BIG_ENDIAN
 	#endif
+#elif defined(__DragonFly__)
+	#include <sys/endian.h>
+	#if _BYTE_ORDER == _LITTLE_ENDIAN		
+		#define UT_LITTLE_ENDIAN
+	#else
+		#define UT_BIG_ENDIAN
+	#endif
 #elif defined(__FreeBSD__)
 	#include <machine/endian.h>
 	#if __BYTE_ORDER == __LITTLE_ENDIAN
