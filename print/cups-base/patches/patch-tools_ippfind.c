$NetBSD: patch-tools_ippfind.c,v 1.1 2020/10/27 09:29:11 jperkin Exp $

Remove another instance of kDNSServiceErr_Timeout, unavailable in
mDNSResponder-258.14.

--- tools/ippfind.c.orig	2020-04-27 18:04:29.000000000 +0000
+++ tools/ippfind.c
@@ -1733,7 +1733,7 @@ dnssd_error_string(int error)		/* I - Er
     case kDNSServiceErr_PollingMode :
         return ("Service polling mode error.");
 
-#ifndef _WIN32
+#if 0
     case kDNSServiceErr_Timeout :
         return ("Service timeout.");
 #endif /* !_WIN32 */
