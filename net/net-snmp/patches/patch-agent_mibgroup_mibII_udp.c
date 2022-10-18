$NetBSD: patch-agent_mibgroup_mibII_udp.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/mibII/udp.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/mibII/udp.c
@@ -151,6 +151,12 @@ init_udp(void)
 #define USES_TRADITIONAL_UDPSTAT
 #endif
 
+#ifdef UDP_NSTATS
+typedef struct udpstat {
+	uint64_t st[UDP_NSTATS];
+};
+#define UDP_STAT_STRUCTURE	struct udpstat
+#endif
 
 #if !defined(UDP_STAT_STRUCTURE)
 #define UDP_STAT_STRUCTURE	struct udpstat
