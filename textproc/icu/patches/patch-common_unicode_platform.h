$NetBSD: patch-common_unicode_platform.h,v 1.1 2012/04/26 18:12:37 martin Exp $

--- common/unicode/platform.h.orig	2012-04-26 19:49:36.000000000 +0200
+++ common/unicode/platform.h	2012-04-26 19:53:33.000000000 +0200
@@ -131,7 +131,8 @@
 #   include <android/api-level.h>
 #elif defined(linux) || defined(__linux__) || defined(__linux)
 #   define U_PLATFORM U_PF_LINUX
-#elif defined(BSD) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(BSD) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
+	defined(__NetBSD__) || defined(__DragonFly__)
 #   define U_PLATFORM U_PF_BSD
 #elif defined(sun) || defined(__sun)
     /* Check defined(__SVR4) || defined(__svr4__) to distinguish Solaris from SunOS? */
@@ -346,6 +347,13 @@
 #   define U_IS_BIG_ENDIAN 1
 #elif defined(__LITTLE_ENDIAN__) || defined(_LITTLE_ENDIAN)
 #   define U_IS_BIG_ENDIAN 0
+#elif U_PLATFORM == U_PF_BSD
+#include <sys/endian.h>
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#   define U_IS_BIG_ENDIAN 0
+#else
+#   define U_IS_BIG_ENDIAN 1
+#endif
 #elif U_PLATFORM == U_PF_OS390 || U_PLATFORM == U_PF_OS400
     /* These platforms do not appear to predefine any endianness macros. */
 #   define U_IS_BIG_ENDIAN 1
