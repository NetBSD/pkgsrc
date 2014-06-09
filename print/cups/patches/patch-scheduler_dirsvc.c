$NetBSD: patch-scheduler_dirsvc.c,v 1.4 2014/06/09 09:27:10 wiz Exp $

o Fix building without dnssd option.
o net/mDNSResponder-258.14 does not define kDNSServiceErr_Timeout, just threat
 it like kDNSServiceErr_Unknown.

--- scheduler/dirsvc.c.orig	2014-03-05 21:11:32.000000000 +0000
+++ scheduler/dirsvc.c
@@ -237,11 +237,13 @@ cupsdStartBrowsing(void)
   if (BrowseLocalProtocols & BROWSE_SMB)
     update_smb(1);
 
+#if defined(HAVE_DNSSD) || defined(HAVE_AVAHI)
  /*
   * Register the individual printers
   */
 
   dnssdRegisterAllPrinters(0);
+#endif
 }
 
 
@@ -255,6 +257,7 @@ cupsdStopBrowsing(void)
   if (!Browsing || !BrowseLocalProtocols)
     return;
 
+#if defined(HAVE_DNSSD) || defined(HAVE_AVAHI)
  /*
   * De-register the individual printers
   */
@@ -265,7 +268,6 @@ cupsdStopBrowsing(void)
   * Shut down browsing sockets...
   */
 
-#if defined(HAVE_DNSSD) || defined(HAVE_AVAHI)
   if ((BrowseLocalProtocols & BROWSE_DNSSD) && DNSSDMaster)
     dnssdStop();
 #endif /* HAVE_DNSSD || HAVE_AVAHI */
@@ -829,9 +831,6 @@ dnssdErrorString(int error)		/* I - Erro
 
     case kDNSServiceErr_PollingMode :
         return ("Service polling mode error.");
-
-    case kDNSServiceErr_Timeout :
-        return ("Service timeout.");
   }
 
 #  else /* HAVE_AVAHI */
