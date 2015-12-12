$NetBSD: patch-frmts_grib_degrib18_degrib_myutil.c,v 1.1 2015/12/12 15:27:50 wiedi Exp $

fix build on SunOS
--- frmts/grib/degrib18/degrib/myutil.c.orig	2015-09-16 10:21:15.000000000 +0000
+++ frmts/grib/degrib18/degrib/myutil.c
@@ -12,7 +12,7 @@
  */
 
 /* For S_IFDIR */
-#define _XOPEN_SOURCE 500
+#define _XOPEN_SOURCE 600
 #include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
