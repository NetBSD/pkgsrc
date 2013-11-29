$NetBSD: patch-agent_mibgroup_mibII_udpTable.c,v 1.1 2013/11/29 12:59:51 joerg Exp $

--- agent/mibgroup/mibII/udpTable.c.orig	2013-11-26 22:25:02.000000000 +0000
+++ agent/mibgroup/mibII/udpTable.c
@@ -395,7 +395,11 @@ udpTable_next_entry( void **loop_context
      * and update the loop context ready for the next one.
      */
     *data_context = (void*)entry;
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    *loop_context = (void*)TAILQ_NEXT(entry, inp_queue);
+#else
     *loop_context = (void*)entry->INP_NEXT_SYMBOL;
+#endif
     return index;
 }
 
@@ -405,7 +409,11 @@ udpTable_free(netsnmp_cache *cache, void
     UDPTABLE_ENTRY_TYPE	 *p;
     while (udp_head) {
         p = udp_head;
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        udp_head = TAILQ_NEXT(udp_head, inp_queue);
+#else
         udp_head = udp_head->INP_NEXT_SYMBOL;
+#endif
         free(p);
     }
 
@@ -705,7 +713,11 @@ udpTable_load(netsnmp_cache *cache, void
     /*
      *  Set up a linked list
      */
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    entry  = TAILQ_FIRST(&table.inpt_queue);
+#else
     entry  = table.inpt_queue.cqh_first;
+#endif
     while (entry) {
    
         nnew = SNMP_MALLOC_TYPEDEF(struct inpcb);
@@ -717,12 +729,22 @@ udpTable_load(netsnmp_cache *cache, void
             break;
         }
 
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        entry    = TAILQ_NEXT(nnew, inp_queue);	/* Next kernel entry */
+	TAILQ_NEXT(nnew, inp_queue) = udp_head;
+#else
         entry    = nnew->inp_queue.cqe_next;	/* Next kernel entry */
 	nnew->inp_queue.cqe_next = udp_head;
+#endif
 	udp_head = nnew;
 
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        if (entry == TAILQ_FIRST(&table.inpt_queue))
+            break;
+#else
         if (entry == table.inpt_queue.cqh_first)
             break;
+#endif
     }
 
     if (udp_head) {
