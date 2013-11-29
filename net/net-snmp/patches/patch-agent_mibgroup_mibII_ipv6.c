$NetBSD: patch-agent_mibgroup_mibII_ipv6.c,v 1.1 2013/11/29 12:59:51 joerg Exp $

--- agent/mibgroup/mibII/ipv6.c.orig	2013-11-26 22:18:51.000000000 +0000
+++ agent/mibgroup/mibII/ipv6.c
@@ -1336,7 +1336,11 @@ var_udp6(register struct variable * vp,
     DEBUGMSGOID(("mibII/ipv6", name, *length));
     DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000 || defined(openbsd4)	/*1.6Y*/
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    if (!auto_nlist("udbtable", (char *) &udbtable, sizeof(udbtable)))
+        return NULL;
+    first = p = (caddr_t)TAILQ_FIRST(&udbtable.inpt_queue);
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 106250000 || defined(openbsd4)	/*1.6Y*/
     if (!auto_nlist("udbtable", (char *) &udbtable, sizeof(udbtable)))
         return NULL;
     first = p = (caddr_t)udbtable.inpt_queue.cqh_first;
@@ -1473,6 +1477,9 @@ var_udp6(register struct variable * vp,
 #if defined(openbsd4)
         p = (caddr_t)in6pcb.inp_queue.cqe_next;
 	if (p == first) break;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        p = (caddr_t)TAILQ_NEXT(&in6pcb, in6p_queue);
+	if (p == first) break;
 #elif defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
         p = (caddr_t)in6pcb.in6p_queue.cqe_next;
 	if (p == first) break;
@@ -1780,7 +1787,11 @@ var_tcp6(register struct variable * vp,
     DEBUGMSGOID(("mibII/ipv6", name, *length));
     DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
-#if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000 || defined(openbsd4)	/*1.6Y*/
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+    if (!auto_nlist("tcbtable", (char *) &tcbtable, sizeof(tcbtable)))
+        return NULL;
+    first = p = (caddr_t)TAILQ_FIRST(&tcbtable.inpt_queue);
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 106250000 || defined(openbsd4)	/*1.6Y*/
     if (!auto_nlist("tcbtable", (char *) &tcbtable, sizeof(tcbtable)))
         return NULL;
     first = p = (caddr_t)tcbtable.inpt_queue.cqh_first;
@@ -1928,6 +1939,9 @@ var_tcp6(register struct variable * vp,
 #if defined(openbsd4)
         p = (caddr_t)in6pcb.inp_queue.cqe_next;
 	if (p == first) break;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 699002800
+        p = (caddr_t)TAILQ_NEXT(&in6pcb, in6p_queue);
+	if (p == first) break;
 #elif defined(__NetBSD__) && __NetBSD_Version__ >= 106250000 || defined(openbsd4)	/*1.6Y*/
         p = (caddr_t)in6pcb.in6p_queue.cqe_next;
 	if (p == first) break;
