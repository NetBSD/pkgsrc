$NetBSD: patch-scheduler_dirsvc.c,v 1.3 2014/06/07 11:54:54 wiz Exp $

--- scheduler/dirsvc.c.orig     2014-03-05 21:11:32.000000000 +0000
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
