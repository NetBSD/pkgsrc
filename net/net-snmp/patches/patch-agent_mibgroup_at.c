$NetBSD: patch-agent_mibgroup_at.c,v 1.1 2016/04/29 19:47:21 adam Exp $

Fix for systems with RTF_LLDATA in place of RTF_LLINFO.

--- agent/mibgroup/mibII/at.c.orig	2016-04-29 19:32:13.000000000 +0000
+++ agent/mibgroup/mibII/at.c
@@ -101,7 +101,7 @@
 #include <net-snmp/data_access/interface.h>
 
 #if defined(HAVE_SYS_SYSCTL_H) && !defined(NETSNMP_CAN_USE_SYSCTL)
-# if defined(RTF_LLINFO) 
+# if defined(RTF_LLINFO) || defined(RTF_LLDATA)
 #  define NETSNMP_CAN_USE_SYSCTL 1
 # endif
 #endif
@@ -691,7 +691,9 @@ ARP_Scan_Init(void)
     mib[2] = 0;
     mib[3] = AF_INET;
     mib[4] = NET_RT_FLAGS;
-#if defined RTF_LLINFO
+#if defined RTF_LLDATA
+    mib[5] = RTF_LLDATA;
+#elif defined RTF_LLINFO
     mib[5] = RTF_LLINFO;
 #else
     mib[5] = 0;
