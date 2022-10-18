$NetBSD: patch-agent_mibgroup_mibII_tcp.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/mibII/tcp.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/mibII/tcp.c
@@ -197,6 +197,16 @@ init_tcp(void)
 #define USES_TRADITIONAL_TCPSTAT
 #endif
 
+#ifdef TCP_NSTATS
+typedef uint32_t tcp_stats[TCP_NSTATS];
+#define TCP_STAT_STRUCTURE	tcp_stats
+#endif
+
+#ifdef dragonfly
+#define TCP_STAT_STRUCTURE	struct tcp_stats
+#define USES_TRADITIONAL_TCPSTAT
+#endif
+
 #if !defined(TCP_STAT_STRUCTURE)
 #define TCP_STAT_STRUCTURE	struct tcpstat
 #define USES_TRADITIONAL_TCPSTAT
@@ -324,6 +334,75 @@ tcp_handler(netsnmp_mib_handler         
 #endif			/* linux */
         netsnmp_set_request_error(reqinfo, request, SNMP_NOSUCHOBJECT);
         continue;
+#elif defined(TCP_NSTAT)
+    case TCPRTOALGORITHM:      /* Assume Van Jacobsen's algorithm */
+        ret_value = 4;
+        type = ASN_INTEGER;
+        break;
+    case TCPRTOMIN:
+#ifdef TCPTV_NEEDS_HZ
+        ret_value = TCPTV_MIN;
+#else
+        ret_value = TCPTV_MIN / PR_SLOWHZ * 1000;
+#endif
+        type = ASN_INTEGER;
+        break;
+    case TCPRTOMAX:
+#ifdef TCPTV_NEEDS_HZ
+        ret_value = TCPTV_REXMTMAX;
+#else
+        ret_value = TCPTV_REXMTMAX / PR_SLOWHZ * 1000;
+#endif
+        type = ASN_INTEGER;
+        break;
+    case TCPMAXCONN:
+        ret_value = -1;		/* Dynamic maximum */
+        type = ASN_INTEGER;
+        break;
+    case TCPACTIVEOPENS:
+        ret_value = tcpstat[TCP_STAT_CONNATTEMPT];
+        break;
+    case TCPPASSIVEOPENS:
+        ret_value = tcpstat[TCP_STAT_ACCEPTS];
+        break;
+        /*
+         * NB:  tcps_drops is actually the sum of the two MIB
+         *      counters tcpAttemptFails and tcpEstabResets.
+         */
+    case TCPATTEMPTFAILS:
+        ret_value = tcpstat[TCP_STAT_CONNDROPS];
+        break;
+    case TCPESTABRESETS:
+        ret_value = tcpstat[TCP_STAT_DROPS];
+        break;
+    case TCPCURRESTAB:
+#ifdef USING_MIBII_TCPTABLE_MODULE
+        ret_value = TCP_Count_Connections();
+#else
+        ret_value = 0;
+#endif
+        type = ASN_GAUGE;
+        break;
+    case TCPINSEGS:
+        ret_value = tcpstat[TCP_STAT_RCVTOTAL];
+        break;
+    case TCPOUTSEGS:
+        /*
+         * RFC 1213 defines this as the number of segments sent
+         * "excluding those containing only retransmitted octets"
+         */
+        ret_value = tcpstat[TCP_STAT_SNDTOTAL] - tcpstat[TCP_STAT_SNDREXMITPACK];
+        break;
+    case TCPRETRANSSEGS:
+        ret_value = tcpstat[TCP_STAT_SNDREXMITPACK];
+        break;
+    case TCPINERRS:
+        ret_value = tcpstat[TCP_STAT_RCVBADSUM] + tcpstat[TCP_STAT_RCVBADOFF]
+            + tcpstat[TCP_STAT_RCVMEMDROP] + tcpstat[TCP_STAT_RCVSHORT];
+        break;
+    case TCPOUTRSTS:
+        ret_value = tcpstat[TCP_STAT_SNDCTRL] - tcpstat[TCP_STAT_CLOSED];
+        break;
 #elif defined(USES_TRADITIONAL_TCPSTAT) && !defined(_USE_FIRST_PROTOCOL)
 #ifdef HAVE_SYS_TCPIPSTATS_H
     /*
