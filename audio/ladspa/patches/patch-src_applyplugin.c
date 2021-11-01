$NetBSD: patch-src_applyplugin.c,v 1.2 2021/11/01 20:30:28 wiz Exp $

Endian support for SunOS and macOS.

--- src/applyplugin.c.orig	2021-09-10 08:50:46.000000000 +0000
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
 #include <sndfile.h>
