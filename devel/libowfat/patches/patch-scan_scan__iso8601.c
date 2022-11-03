$NetBSD: patch-scan_scan__iso8601.c,v 1.2 2022/11/03 00:00:08 schmonz Exp $

Fix Illumos build. Then fix macOS build with the 13.0 SDK, which has its
own definition of __deprecated__.

--- scan/scan_iso8601.c.orig	2016-04-27 14:07:50
+++ scan/scan_iso8601.c
@@ -4,6 +4,9 @@
 #include "byte.h"
 #include "case.h"
 #include <time.h>
+#ifdef __APPLE__
+#undef __deprecated__
+#endif
 #include <stdlib.h>
 
 #ifdef sgi
@@ -44,7 +47,7 @@ size_t scan_iso8601(const char* in,struct timespec* t)
     }
   }
 
-#ifdef __MINGW32__
+#if defined(__MINGW32__) || (defined (__sun__) && defined(__svr4__))
   x.tm_wday=x.tm_yday=x.tm_isdst=0;
 #else
   x.tm_wday=x.tm_yday=x.tm_isdst=x.tm_gmtoff=0;
