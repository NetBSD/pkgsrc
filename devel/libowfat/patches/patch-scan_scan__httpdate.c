$NetBSD: patch-scan_scan__httpdate.c,v 1.1 2022/11/03 00:00:08 schmonz Exp $

Fix macOS build with the 13.0 SDK, which has its own definition of
__deprecated__.

--- scan/scan_httpdate.c.orig	2016-04-27 14:07:50
+++ scan/scan_httpdate.c
@@ -4,6 +4,9 @@
 #include "byte.h"
 #include "case.h"
 #include <time.h>
+#ifdef __APPLE__
+#undef __deprecated__
+#endif
 #include <stdlib.h>
 
 #ifdef sgi
