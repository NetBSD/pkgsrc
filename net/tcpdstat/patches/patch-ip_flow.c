$NetBSD: patch-ip_flow.c,v 1.1 2012/03/07 18:27:30 hans Exp $

--- ip_flow.c.orig	2000-06-30 13:16:26.000000000 +0200
+++ ip_flow.c	2012-03-07 19:03:35.308708989 +0100
@@ -66,14 +66,14 @@ struct flow_entry {
 
 	struct flow f_flow;
 	int	f_packets;
-	quad_t	f_bytes;
+	int64_t	f_bytes;
 };
 
 #define FLOW_HASHSIZE	256
 
 static LIST_HEAD(flow_head, flow_entry) flow_hash[FLOW_HASHSIZE];
 int	total_packets;
-quad_t	total_bytes;
+int64_t	total_bytes;
 
 static __inline int ip_hash4 __P((struct in_addr *, struct in_addr *));
 #ifdef INET6
@@ -229,7 +229,7 @@ void ipflow_show(void)
 			 */
 			for (j = 0; j < NTOP; j++) {
 				if (big_flows[j] == NULL ||
-				    (quad_t)flow->f_bytes > big_flows[j]->f_bytes) {
+				    (int64_t)flow->f_bytes > big_flows[j]->f_bytes) {
 					/* insert the entry */
 					for (k = NTOP-1; k > j; k--)
 						big_flows[k] = big_flows[k-1];
@@ -312,7 +312,7 @@ struct addr_entry {
 #endif
 	} a_un;
 	int	addr_packets;
-	quad_t	addr_bytes;
+	int64_t	addr_bytes;
 };
 
 #define addr_ip		a_un.ua_ip
@@ -324,18 +324,18 @@ struct addr_entry {
 
 static LIST_HEAD(addr_head, addr_entry) addr_hash[FLOW_HASHSIZE];
 static int total_addr = 0;
-static quad_t v4_total_bytes = 0;
+static int64_t v4_total_bytes = 0;
 #ifdef INET6
 static LIST_HEAD(addr_head6, addr_entry) addr_hash6[FLOW_HASHSIZE];
 static int total_addr6 = 0;
-static quad_t v6_total_bytes = 0;
+static int64_t v6_total_bytes = 0;
 #endif
 
 static int addr_count(af, ip_addr, packets, bytes)
 	int	af;
 	struct in_addr *ip_addr;
 	int	packets;
-	quad_t	bytes;
+	int64_t	bytes;
 {
 	struct addr_entry *addr;
 	int hash;
