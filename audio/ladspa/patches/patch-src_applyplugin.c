$NetBSD: patch-src_applyplugin.c,v 1.1 2019/10/05 17:39:38 nia Exp $

Endian support for SunOS and macOS.

--- src/applyplugin.c.orig	2019-01-06 12:27:52.000000000 +0000
+++ src/applyplugin.c
@@ -6,7 +6,19 @@
 /*****************************************************************************/
 
 #include <dlfcn.h>
-#include <endian.h>
+#ifdef __linux__
+# include <endian.h>
+#elif defined(__sun)
+# include <sys/byteorder.h>
+# ifdef _LITTLE_ENDIAN
+#  define LITTLE_ENDIAN 1234
+#  define BYTE_ORDER LITTLE_ENDIAN
+# endif
+#elif defined(__APPLE__)
+# include <machine/endian.h>
+#else
+# include <sys/endian.h>
+#endif
 #include <errno.h>
 #include <math.h>
 #include <stdlib.h>
