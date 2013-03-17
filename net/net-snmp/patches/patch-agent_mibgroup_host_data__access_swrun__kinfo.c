$NetBSD: patch-agent_mibgroup_host_data__access_swrun__kinfo.c,v 1.2 2013/03/17 00:15:29 gdt Exp $

--- agent/mibgroup/host/data_access/swrun_kinfo.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/host/data_access/swrun_kinfo.c
@@ -5,6 +5,10 @@
  *
  * NB: later FreeBSD uses a different kinfo_proc structure
  */
+#ifdef __NetBSD__
+#define _KMEMUSER
+#endif
+
 #include <net-snmp/net-snmp-config.h>
 
 #include <stdio.h>
