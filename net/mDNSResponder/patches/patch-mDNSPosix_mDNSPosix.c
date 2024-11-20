$NetBSD: patch-mDNSPosix_mDNSPosix.c,v 1.1 2024/11/20 17:56:21 hauke Exp $

 - OpenBSD fix from
https://web.archive.org/web/20140115063128/http://lists.apple.com/archives/bonjour-dev/2007/Jan/msg00003.html

 - NetBSD HINFO record from hw.model and kern.osrelease

--- mDNSPosix/mDNSPosix.c.orig	2024-11-20 15:54:56.086626755 +0000
+++ mDNSPosix/mDNSPosix.c
@@ -453,7 +453,7 @@ mDNSlocal void SocketDataReady(mDNS *con
         // so all we can do is just assume it's a multicast
 
         #if HAVE_BROKEN_RECVDSTADDR || (!defined(IP_PKTINFO) && !defined(IP_RECVDSTADDR))
-        if ((destAddr.NotAnInteger == 0) && (flags & MSG_MCAST))
+        if ((destAddr.ip.v4.NotAnInteger == 0) && (flags & MSG_MCAST))
         {
             destAddr.type = senderAddr.type;
             if      (senderAddr.type == mDNSAddrType_IPv4) destAddr.ip.v4 = AllDNSLinkGroup_v4.ip.v4;
@@ -1849,6 +1855,37 @@ mDNSlocal mDNSBool mDNSPlatformInit_CanR
     return(err == 0);
 }
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+
+void
+initmachinedescr(mDNS *const m)
+{
+    char hwbuf[256], swbuf[256];
+    size_t hwlen, swlen;
+    const int hwmib[] = { CTL_HW, HW_MODEL };
+    const int swmib[] = { CTL_KERN, KERN_OSRELEASE };
+    const char netbsd[] = "NetBSD ";
+
+    hwlen = sizeof(hwbuf);
+    swlen = sizeof(swbuf);
+    if (sysctl(hwmib, 2, hwbuf, &hwlen, 0, 0) ||
+        sysctl(swmib, 2, swbuf, &swlen, 0, 0))
+            return;
+    
+    if (hwlen + swlen + sizeof(netbsd) >=254)
+            return;
+
+    m->HIHardware.c[0] = hwlen - 1;
+    m->HISoftware.c[0] = swlen + sizeof(netbsd) - 2;
+    memcpy(&m->HIHardware.c[1], hwbuf, hwlen - 1);
+    memcpy(&m->HISoftware.c[1], netbsd, sizeof(netbsd) - 1);
+    memcpy(&m->HISoftware.c[1 + sizeof(netbsd) - 1], swbuf, swlen - 1);
+}
+#endif
+
+
 // mDNS core calls this routine to initialise the platform-specific data.
 mDNSexport mStatus mDNSPlatformInit(mDNS *const m)
 {
@@ -1870,6 +1907,10 @@ mDNSexport mStatus mDNSPlatformInit(mDNS
     GetUserSpecifiedRFC1034ComputerName(&m->hostlabel);
     if (m->hostlabel.c[0] == 0) MakeDomainLabelFromLiteralString(&m->hostlabel, "Computer");
 
+#ifdef __NetBSD__
+    initmachinedescr(m);
+#endif
+
     mDNS_SetFQDN(m);
 
     sa.sa_family = AF_INET;
