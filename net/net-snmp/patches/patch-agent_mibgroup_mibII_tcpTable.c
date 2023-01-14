$NetBSD: patch-agent_mibgroup_mibII_tcpTable.c,v 1.3 2023/01/14 21:11:35 mrg Exp $

handle list changes in 6.99.28

handle merged inpcb code since 9.99.104:
  http://mail-index.netbsd.org/source-changes/2022/10/28/msg141800.html


--- agent/mibgroup/mibII/tcpTable.c.orig	2022-07-13 14:14:14.000000000 -0700
+++ agent/mibgroup/mibII/tcpTable.c	2023-01-14 00:30:16.395356283 -0800
@@ -123,20 +123,34 @@ struct netsnmp_inpcb_s {
 #if __FreeBSD_version >= 1200026
     struct xinpcb   pcb;
 #else
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+    struct in4pcb    pcb;
+#else
     struct inpcb    pcb;
 #endif
+#endif
     int             state;
     netsnmp_inpcb  *inp_next;
 };
 #undef INP_NEXT_SYMBOL
-#define INP_NEXT_SYMBOL		inp_next
 #define	TCPTABLE_ENTRY_TYPE	netsnmp_inpcb 
 #define	TCPTABLE_STATE		state 
+#define	TCPTABLE_IS_LINKED_LIST
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+#define INP_NEXT_SYMBOL		inp_next
+#define	TCPTABLE_LOCALADDRESS	pcb.in4p_ip.ip_src.s_addr 
+#define	TCPTABLE_LOCALPORT	pcb.in4p_pcb.inp_lport
+#define	TCPTABLE_REMOTEADDRESS	pcb.in4p_ip.ip_dst.s_addr 
+#define	TCPTABLE_REMOTEPORT	pcb.in4p_pcb.inp_fport
+#define	TCPTABLE_TCPCB          pcb.in4p_pcb.inp_ppcb
+#else
+#define INP_NEXT_SYMBOL		inp_next
 #define	TCPTABLE_LOCALADDRESS	pcb.inp_laddr.s_addr 
 #define	TCPTABLE_LOCALPORT	pcb.inp_lport
 #define	TCPTABLE_REMOTEADDRESS	pcb.inp_faddr.s_addr 
 #define	TCPTABLE_REMOTEPORT	pcb.inp_fport
-#define	TCPTABLE_IS_LINKED_LIST
+#define	TCPTABLE_TCPCB          pcb.inp_ppcb
+#endif
 
 #endif                          /* hpux11 */
 
@@ -1057,18 +1071,22 @@ tcpTable_load(netsnmp_cache *cache, void
     /*
      *  Set up a linked list
      */
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    entry  = TAILQ_FIRST(&table.inpt_queue);
+#else
     entry  = table.INP_FIRST_SYMBOL;
+#endif
     while (entry) {
    
         nnew = SNMP_MALLOC_TYPEDEF(netsnmp_inpcb);
         if (!nnew)
             break;
-        if (!NETSNMP_KLOOKUP(entry, (char *)&(nnew->pcb), sizeof(struct inpcb))) {
+        if (!NETSNMP_KLOOKUP(entry, (char *)&(nnew->pcb), sizeof(nnew->pcb))) {
             DEBUGMSGTL(("mibII/tcpTable:TcpTable_load", "klookup failed\n"));
             break;
         }
 
-        if (!NETSNMP_KLOOKUP(nnew->pcb.inp_ppcb, (char *)&tcpcb, sizeof(struct tcpcb))) {
+        if (!NETSNMP_KLOOKUP(nnew->TCPTABLE_TCPCB, (char *)&tcpcb, sizeof(struct tcpcb))) {
             DEBUGMSGTL(("mibII/tcpTable:TcpTable_load", "klookup failed\n"));
             break;
         }
@@ -1081,8 +1099,13 @@ tcpTable_load(netsnmp_cache *cache, void
 	nnew->inp_next = tcp_head;
 	tcp_head   = nnew;
 
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        if (entry == TAILQ_FIRST(&table.inpt_queue))
+            break;
+#else
         if (entry == table.INP_FIRST_SYMBOL)
             break;
+#endif
     }
 
     if (tcp_head) {
