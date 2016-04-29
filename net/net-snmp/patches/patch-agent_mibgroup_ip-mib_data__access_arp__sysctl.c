$NetBSD: patch-agent_mibgroup_ip-mib_data__access_arp__sysctl.c,v 1.1 2016/04/29 19:47:21 adam Exp $

Fix for systems with RTF_LLDATA in place of RTF_LLINFO.

--- agent/mibgroup/ip-mib/data_access/arp_sysctl.c.orig	2016-04-29 19:29:57.000000000 +0000
+++ agent/mibgroup/ip-mib/data_access/arp_sysctl.c
@@ -129,7 +129,11 @@ _load_arp_table_from_sysctl(netsnmp_arp_
     mib[2] = 0;
     mib[3] = AF_INET;
     mib[4] = NET_RT_FLAGS;
+#ifdef RTF_LLDATA
+    mib[5] = RTF_LLDATA;
+#else
     mib[5] = RTF_LLINFO;
+#endif
 
     err = 0;
     buf = newbuf = NULL;
@@ -236,7 +240,11 @@ _load_ndp_table_from_sysctl(netsnmp_arp_
     mib[2] = 0;
     mib[3] = AF_INET6;
     mib[4] = NET_RT_FLAGS;
+#ifdef RTF_LLDATA
+    mib[5] = RTF_LLDATA;
+#else
     mib[5] = RTF_LLINFO;
+#endif
 
     err = 0;
     buf = newbuf = NULL;
