$NetBSD: patch-scheduler_dirsvc.c,v 1.2 2020/05/26 08:36:56 triaxx Exp $

o net/mDNSResponder-258.14 does not define kDNSServiceErr_Timeout, just threat
 it like kDNSServiceErr_Unknown.

--- scheduler/dirsvc.c.orig	2015-01-30 16:15:53.000000000 +0000
+++ scheduler/dirsvc.c
@@ -865,9 +865,6 @@ dnssdErrorString(int error)		/* I - Erro
 
     case kDNSServiceErr_PollingMode :
         return ("Service polling mode error.");
-
-    case kDNSServiceErr_Timeout :
-        return ("Service timeout.");
   }
 
 #  else /* HAVE_AVAHI */
