$Id: patch-src_report.c,v 1.1 2016/01/22 21:56:37 dmcmahill Exp $

--- src/report.c.orig	2014-03-10 23:09:51.000000000 -0400
+++ src/report.c	2016-01-22 10:05:47.000000000 -0500
@@ -32,4 +32,7 @@
 #endif
 
+#ifdef HAVE_LOCALE_H
+#include <locale.h>  /* setlocale() and LC_ALL */
+#endif
 #include <math.h>
 
