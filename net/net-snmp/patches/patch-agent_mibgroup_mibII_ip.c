$NetBSD: patch-agent_mibgroup_mibII_ip.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/mibII/ip.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/mibII/ip.c
@@ -255,6 +255,18 @@ long            ipTTL, oldipTTL;
 #define	USES_TRADITIONAL_IPSTAT
 #endif
 
+#ifdef IP_NSTATS
+typedef struct ipstat {
+	uint64_t st[IP_NSTATS];
+};
+#define IP_STAT_STRUCTURE	struct ipstat
+#endif
+
+#ifdef dragonfly
+#define IP_STAT_STRUCTURE	struct ip_stats
+#define	USES_TRADITIONAL_IPSTAT
+#endif
+
 #if !defined(IP_STAT_STRUCTURE)
 #define IP_STAT_STRUCTURE	struct ipstat
 #define	USES_TRADITIONAL_IPSTAT
