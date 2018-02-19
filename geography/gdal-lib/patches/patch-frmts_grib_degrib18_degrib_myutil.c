$NetBSD: patch-frmts_grib_degrib18_degrib_myutil.c,v 1.2 2018/02/19 12:05:17 ryoon Exp $

fix build on SunOS
--- frmts/grib/degrib18/degrib/myutil.c.orig	2017-11-20 10:45:40.000000000 +0000
+++ frmts/grib/degrib18/degrib/myutil.c
@@ -23,7 +23,7 @@
 #ifdef _XOPEN_SOURCE
 #undef _XOPEN_SOURCE
 #endif
-#define _XOPEN_SOURCE 500
+#define _XOPEN_SOURCE 600
 #endif
 
 #include <stdlib.h>
