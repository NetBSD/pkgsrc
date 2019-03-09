$NetBSD: patch-frmts_grib_degrib_degrib_myutil.c,v 1.1 2019/03/09 01:54:59 gdt Exp $

fix build on SunOS
\todo Explain what's wrong.
\todo File a ticket and get this fixed upstream.

--- frmts/grib/degrib/degrib/myutil.c.orig	2017-11-20 10:45:40.000000000 +0000
+++ frmts/grib/degrib/degrib/myutil.c
@@ -23,7 +23,7 @@
 #ifdef _XOPEN_SOURCE
 #undef _XOPEN_SOURCE
 #endif
-#define _XOPEN_SOURCE 500
+#define _XOPEN_SOURCE 600
 #endif
 
 #include <stdlib.h>
