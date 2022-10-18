$NetBSD: patch-agent_mibgroup_mibII_icmp.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/mibII/icmp.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/mibII/icmp.c
@@ -621,6 +621,13 @@ bail:
 #define USES_TRADITIONAL_ICMPSTAT
 #endif
 
+#ifdef ICMP_NSTATS
+struct icmpstat {
+	uint64_t st[ICMP_NSTATS];
+};
+#define ICMP_STAT_STRUCTURE	struct icmpstat
+#endif
+
 #if !defined(ICMP_STAT_STRUCTURE)
 #define ICMP_STAT_STRUCTURE	struct icmpstat
 #define USES_TRADITIONAL_ICMPSTAT
