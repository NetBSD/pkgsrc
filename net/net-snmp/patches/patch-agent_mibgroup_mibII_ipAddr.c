$NetBSD: patch-agent_mibgroup_mibII_ipAddr.c,v 1.1 2013/03/12 17:14:49 kim Exp $

--- agent/mibgroup/mibII/ipAddr.c.orig	2010-01-23 17:07:35.000000000 +0200
+++ agent/mibgroup/mibII/ipAddr.c	2013-03-12 17:48:01.000000000 +0200
@@ -218,6 +218,10 @@
         if (Interface_Scan_Next(&interface, NULL, &ifnet, &in_ifaddr) == 0)
             break;
 #ifdef HAVE_STRUCT_IFNET_IF_ADDRLIST
+#if defined(netbsd1) || defined(openbsd2)
+#define if_addrlist if_addrlist.tqh_first
+#endif
+
         if (ifnet.if_addrlist == 0)
             continue;           /* No address found for interface */
 #endif
