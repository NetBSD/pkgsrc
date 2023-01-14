$NetBSD: patch-agent_mibgroup_mibII_udpTable.c,v 1.4 2023/01/14 21:11:35 mrg Exp $

handle list changes in 6.99.28

handle merged inpcb code since 9.99.104:
  http://mail-index.netbsd.org/source-changes/2022/10/28/msg141800.html


--- agent/mibgroup/mibII/udpTable.c.orig	2022-07-13 14:14:14.000000000 -0700
+++ agent/mibgroup/mibII/udpTable.c	2023-01-14 00:46:14.117378148 -0800
@@ -109,10 +109,16 @@ struct netsnmp_inpcb_s {
 #define	UDPTABLE_LOCALADDRESS	pcb.inp_laddr.s_addr 
 #define	UDPTABLE_LOCALPORT	pcb.inp_lport
 #else
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+#define	UDPTABLE_ENTRY_TYPE	struct in4pcb 
+#define	UDPTABLE_LOCALADDRESS	in4p_ip.ip_src.s_addr
+#define	UDPTABLE_LOCALPORT	in4p_pcb.inp_lport
+#else
 #define	UDPTABLE_ENTRY_TYPE	struct inpcb 
 #define	UDPTABLE_LOCALADDRESS	inp_laddr.s_addr 
 #define	UDPTABLE_LOCALPORT	inp_lport
 #endif
+#endif
 #define	UDPTABLE_IS_LINKED_LIST
 
 #endif                          /* hpux11 */
@@ -430,7 +436,13 @@ udpTable_next_entry( void **loop_context
      * and update the loop context ready for the next one.
      */
     *data_context = (void*)entry;
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+    *loop_context = (void*)TAILQ_NEXT(entry, in4p_pcb.inp_queue);
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    *loop_context = (void*)TAILQ_NEXT(entry, inp_queue);
+#else
     *loop_context = (void*)entry->INP_NEXT_SYMBOL;
+#endif
     return index;
 }
 
@@ -440,7 +452,13 @@ udpTable_free(netsnmp_cache *cache, void
     UDPTABLE_ENTRY_TYPE	 *p;
     while (udp_head) {
         p = udp_head;
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+        udp_head = TAILQ_NEXT(udp_head, in4p_pcb.inp_queue);
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        udp_head = TAILQ_NEXT(udp_head, inp_queue);
+#else
         udp_head = udp_head->INP_NEXT_SYMBOL;
+#endif
         free(p);
     }
 
@@ -752,7 +770,11 @@ udpTable_load(netsnmp_cache *cache, void
     /*
      *  Set up a linked list
      */
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    entry  = TAILQ_FIRST(&table.inpt_queue);
+#else
     entry  = table.INP_FIRST_SYMBOL;
+#endif
     while (entry) {
    
         nnew = SNMP_MALLOC_TYPEDEF(struct inpcb);
@@ -809,12 +831,22 @@ udpTable_load(netsnmp_cache *cache, void
             break;
         }
 
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        entry    = TAILQ_NEXT(nnew, inp_queue);        /* Next kernel entry */
+       TAILQ_NEXT(nnew, inp_queue) = udp_head;
+#else
         entry    = nnew->INP_NEXT_SYMBOL;		/* Next kernel entry */
 	nnew->INP_NEXT_SYMBOL = udp_head;
+#endif
 	udp_head = nnew;
 
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        if (entry == TAILQ_FIRST(&table.inpt_queue))
+            break;
+#else
         if (entry == udp_inpcb.INP_NEXT_SYMBOL)
             break;
+#endif
     }
 
     if (udp_head) {
