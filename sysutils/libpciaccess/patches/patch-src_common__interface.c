$NetBSD: patch-src_common__interface.c,v 1.1 2013/12/21 11:05:23 jperkin Exp $

Add Darwin support.

--- src/common_interface.c.orig	2013-07-20 22:54:34.000000000 +0000
+++ src/common_interface.c
@@ -67,6 +67,22 @@
 # define HTOLE_32(x)   (x)
 #endif /* Solaris */
 
+#elif defined(__APPLE__)
+
+#include <architecture/byte_order.h>
+
+#if __BYTE_ORDER == __BIG_ENDIAN
+# define LETOH_16(x)	OSSwapInt16(x)
+# define HTOLE_16(x)	OSSwapInt16(x)
+# define LETOH_32(x)	OSSwapInt32(x)
+# define HTOLE_32(x)	OSSwapInt32(x)
+#else
+# define LETOH_16(x)	(x)
+# define HTOLE_16(x)	(x)
+# define LETOH_32(x)	(x)
+# define HTOLE_32(x)	(x)
+#endif /* darwin */
+
 #else
 
 #include <sys/endian.h>
