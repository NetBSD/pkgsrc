$NetBSD: patch-scheduler_dirsvc.c,v 1.6 2015/12/02 21:14:16 leot Exp $

o net/mDNSResponder-258.14 does not define kDNSServiceErr_Timeout, just threat
 it like kDNSServiceErr_Unknown.

--- scheduler/dirsvc.c.orig	2015-01-30 16:15:53.000000000 +0000
+++ scheduler/dirsvc.c
@@ -831,9 +831,6 @@ dnssdErrorString(int error)		/* I - Erro
 
     case kDNSServiceErr_PollingMode :
         return ("Service polling mode error.");
-
-    case kDNSServiceErr_Timeout :
-        return ("Service timeout.");
   }
 
 #  else /* HAVE_AVAHI */
