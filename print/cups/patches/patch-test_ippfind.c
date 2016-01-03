$NetBSD: patch-test_ippfind.c,v 1.1 2016/01/03 19:56:18 bsiegert Exp $

--- test/ippfind.c.orig	2015-05-19 02:36:15.000000000 +0000
+++ test/ippfind.c
@@ -1719,11 +1719,6 @@ dnssd_error_string(int error)		/* I - Er
 
     case kDNSServiceErr_PollingMode :
         return ("Service polling mode error.");
-
-#ifndef WIN32
-    case kDNSServiceErr_Timeout :
-        return ("Service timeout.");
-#endif /* !WIN32 */
   }
 
 #  elif defined(HAVE_AVAHI)
