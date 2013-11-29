$NetBSD: patch-agent_mibgroup_mibII_tcpTable.c,v 1.1 2013/11/29 12:59:51 joerg Exp $

--- agent/mibgroup/mibII/tcpTable.c.orig	2013-11-26 22:24:01.000000000 +0000
+++ agent/mibgroup/mibII/tcpTable.c
@@ -946,7 +946,11 @@ tcpTable_load(netsnmp_cache *cache, void
     /*
      *  Set up a linked list
      */
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    entry  = TAILQ_FIRST(&table.inpt_queue);
+#else
     entry  = table.inpt_queue.cqh_first;
+#endif
     while (entry) {
    
         nnew = SNMP_MALLOC_TYPEDEF(netsnmp_inpcb);
@@ -970,8 +974,13 @@ tcpTable_load(netsnmp_cache *cache, void
 	nnew->inp_next = tcp_head;
 	tcp_head   = nnew;
 
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        if (entry == TAILQ_FIRST(&table.inpt_queue))
+            break;
+#else
         if (entry == table.inpt_queue.cqh_first)
             break;
+#endif
     }
 
     if (tcp_head) {
