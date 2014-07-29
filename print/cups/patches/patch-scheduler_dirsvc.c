$NetBSD: patch-scheduler_dirsvc.c,v 1.5 2014/07/29 11:38:40 wiz Exp $

o net/mDNSResponder-258.14 does not define kDNSServiceErr_Timeout, just threat
 it like kDNSServiceErr_Unknown.

--- scheduler/dirsvc.c.orig	2014-06-09 18:33:24.000000000 +0000
+++ scheduler/dirsvc.c
@@ -831,9 +833,6 @@ dnssdErrorString(int error)		/* I - Erro
 
     case kDNSServiceErr_PollingMode :
         return ("Service polling mode error.");
-
-    case kDNSServiceErr_Timeout :
-        return ("Service timeout.");
   }
 
 #  else /* HAVE_AVAHI */
