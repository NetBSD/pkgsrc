$NetBSD: patch-test_ippfind.c,v 1.2 2018/11/10 19:51:12 leot Exp $

--- test/ippfind.c.orig	2018-11-08 13:49:36.000000000 +0000
+++ test/ippfind.c
@@ -1765,11 +1765,6 @@ dnssd_error_string(int error)		/* I - Er
 
     case kDNSServiceErr_PollingMode :
         return ("Service polling mode error.");
-
-#ifndef _WIN32
-    case kDNSServiceErr_Timeout :
-        return ("Service timeout.");
-#endif /* !_WIN32 */
   }
 
 #  elif defined(HAVE_AVAHI)
