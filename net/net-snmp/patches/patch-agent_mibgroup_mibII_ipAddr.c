$NetBSD: patch-agent_mibgroup_mibII_ipAddr.c,v 1.2 2013/03/17 00:15:29 gdt Exp $

--- agent/mibgroup/mibII/ipAddr.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/mibII/ipAddr.c
@@ -221,6 +221,10 @@ var_ipAddrEntry(struct variable *vp,
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
