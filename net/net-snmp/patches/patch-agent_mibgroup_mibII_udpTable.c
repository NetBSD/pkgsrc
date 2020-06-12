$NetBSD: patch-agent_mibgroup_mibII_udpTable.c,v 1.2 2020/06/12 02:22:08 sevan Exp $


--- agent/mibgroup/mibII/udpTable.c.orig	2020-06-12 01:53:58.092446674 +0100
+++ agent/mibgroup/mibII/udpTable.c	2020-06-12 02:01:40.556941658 +0100
@@ -426,7 +426,11 @@
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
 
@@ -436,7 +440,11 @@
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
 
@@ -744,7 +752,11 @@
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
@@ -801,12 +813,22 @@
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
