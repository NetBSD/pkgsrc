$NetBSD: patch-include_net-snmp_system_netbsd.h,v 1.1 2013/04/04 19:59:07 christos Exp $

--- include/net-snmp/system/netbsd.h.orig	2012-10-09 18:28:58.000000000 -0400
+++ include/net-snmp/system/netbsd.h	2013-04-04 15:07:09.000000000 -0400
@@ -33,6 +33,11 @@
 #define UTMP_FILE _PATH_UTMP
 
 #define UDP_ADDRESSES_IN_HOST_ORDER 1
+#if __NetBSD_Version__ >= 600000000 && !defined(netbsdelf6)
+#define netbsdelf6
+#elif  __NetBSD_Version__ >= 500000000 && !defined(netbsdelf5)
+#define netbsdelf5
+#endif
 
 #ifdef netbsdelf6
 #define netbsd6
@@ -68,6 +73,13 @@
 
 #if __NetBSD_Version__ >= 499005800
 #define NETBSD_STATS_VIA_SYSCTL
+
+/* Why these undefs? */
+#undef IPSTAT_SYMBOL
+#undef ICMPSTAT_SYMBOL
+#undef TCPSTAT_SYMBOL
+#undef UDPSTAT_SYMBOL
+
 #endif /* __NetBSD_Version__ >= 499005800 */
 
 /* define the extra mib modules that are supported */
