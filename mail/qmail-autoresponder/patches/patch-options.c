$NetBSD: patch-options.c,v 1.2 2018/12/17 16:15:29 schmonz Exp $

Remove unneeded include. Handle _XOPEN_SOURCE on SunOS.

--- options.c.orig	2018-04-13 16:17:51.000000000 +0000
+++ options.c
@@ -1,5 +1,12 @@
+#if defined(__sun) && !defined(_XOPEN_SOURCE)
+#  if (__STDC_VERSION__-0 < 199901L)
+#define _XOPEN_SOURCE 500
+#  else
+#define _XOPEN_SOURCE 600
+#  endif
+#else
 #define _XOPEN_SOURCE
-#include <mysql/mysql.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
