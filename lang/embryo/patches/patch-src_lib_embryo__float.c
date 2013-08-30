$NetBSD: patch-src_lib_embryo__float.c,v 1.1 2013/08/30 11:12:04 obache Exp $

* band-aid patch for missing fxp2f(3) on NetBSD<6

--- src/lib/embryo_float.c.orig	2013-04-04 19:42:04.000000000 +0000
+++ src/lib/embryo_float.c
@@ -52,6 +52,13 @@
 #define MAXFLOAT 3.40282347e+38f
 #endif
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#  if __NetBSD_Version < 600000000
+#define exp2f(x) expf((x) * M_LN2)
+#  endif
+#endif
+
 /* internally useful calls */
 
 static float
