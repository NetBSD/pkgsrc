$NetBSD: patch-lib_geo.h,v 1.1 2014/02/16 15:39:51 wiedi Exp $

need MIN/MAX on SunOS
--- lib/geo.h.orig	2013-12-20 09:27:33.336349381 +0000
+++ lib/geo.h
@@ -24,7 +24,7 @@
 #include "ii.h"
 #include "db.h"
 
-#ifdef WIN32
+#if defined(WIN32) || defined(__sun)
 # define _USE_MATH_DEFINES
 # ifndef MAX
 #  define MAX(a, b) ((a) > (b) ? (a) : (b))
@@ -33,7 +33,7 @@
 # ifndef MIN
 #  define MIN(a, b) ((a) < (b) ? (a) : (b))
 # endif
-#endif /* WIN32 */
+#endif /* WIN32 or __sun */
 #include <math.h>
 
 #ifdef __cplusplus
