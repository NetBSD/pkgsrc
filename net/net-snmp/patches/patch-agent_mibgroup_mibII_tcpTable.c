$NetBSD: patch-agent_mibgroup_mibII_tcpTable.c,v 1.2 2020/06/12 02:22:08 sevan Exp $


--- agent/mibgroup/mibII/tcpTable.c.orig	2020-06-12 02:28:28.274144065 +0100
+++ agent/mibgroup/mibII/tcpTable.c	2020-06-12 02:30:19.848438704 +0100
@@ -1043,7 +1043,11 @@
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
@@ -1067,8 +1071,13 @@
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
