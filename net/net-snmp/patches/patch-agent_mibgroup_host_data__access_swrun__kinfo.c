$NetBSD: patch-agent_mibgroup_host_data__access_swrun__kinfo.c,v 1.3.38.1 2019/07/02 09:40:31 bsiegert Exp $

--- agent/mibgroup/host/data_access/swrun_kinfo.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ agent/mibgroup/host/data_access/swrun_kinfo.c
@@ -5,6 +5,10 @@
  *
  * NB: later FreeBSD and OpenBSD use different kinfo_proc structures
  */
+#ifdef __NetBSD__
+#define _KMEMUSER
+#endif
+
 #include <net-snmp/net-snmp-config.h>
 
 #include <stdio.h>
@@ -286,7 +290,9 @@ netsnmp_arch_swrun_container_load( netsn
 	case LSSUSPENDED:
         case LSSTOP:  entry->hrSWRunStatus = HRSWRUNSTATUS_NOTRUNNABLE;
                       break;
+#ifdef LSDEAD
 	case LSDEAD:
+#endif
         case LSZOMB:  entry->hrSWRunStatus = HRSWRUNSTATUS_INVALID;
 		      break;
         default:   
