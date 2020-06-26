$NetBSD: patch-scan_scan__iso8601.c,v 1.1 2020/06/26 19:21:52 schmonz Exp $

Fix Illumos build.

--- scan/scan_iso8601.c.orig	2016-04-27 14:07:50.000000000 +0000
+++ scan/scan_iso8601.c
@@ -44,7 +44,7 @@ size_t scan_iso8601(const char* in,struc
     }
   }
 
-#ifdef __MINGW32__
+#if defined(__MINGW32__) || (defined (__sun__) && defined(__svr4__))
   x.tm_wday=x.tm_yday=x.tm_isdst=0;
 #else
   x.tm_wday=x.tm_yday=x.tm_isdst=x.tm_gmtoff=0;
