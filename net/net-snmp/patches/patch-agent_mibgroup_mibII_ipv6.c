$NetBSD: patch-agent_mibgroup_mibII_ipv6.c,v 1.3 2023/01/13 23:14:31 gutteridge Exp $

Account for pcb struct changes as of NetBSD 9.99.104.

--- agent/mibgroup/mibII/ipv6.c.orig	2022-07-13 21:14:14.000000000 +0000
+++ agent/mibgroup/mibII/ipv6.c
@@ -176,7 +176,7 @@
 
 netsnmp_feature_require(linux_read_ip6_stat);
 
-#if defined(netbsd1) && !defined(openbsd4)
+#if defined(netbsd1) && !defined(openbsd4) && __NetBSD_Version__ < 999010400
 #define inp_lport in6p_lport
 #define inp_fport in6p_fport
 #define inp_ppcb in6p_ppcb
@@ -1627,8 +1627,13 @@ var_udp6(register struct variable * vp,
         }
 #endif
 #if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+# if __NetBSD_Version__ < 999010400
         if (in6pcb.in6p_af != AF_INET6)
             goto skip;
+# else
+        if (in6pcb.in6p_pcb.inp_af != AF_INET6)
+            goto skip;
+# endif
 #elif defined(INP_ISIPV6)
 	if (!INP_ISIPV6(&in6pcb))
 	    goto skip;
@@ -1650,6 +1655,15 @@ var_udp6(register struct variable * vp,
                 ntohs(*(uint16_t *) &in6pcb.inp_laddr6.s6_addr[2]);
         else
             newname[j++] = 0;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+        for (i = 0; i < sizeof(struct in6_addr); i++)
+            newname[j++] = in6pcb.in6p_ip6.ip6_src.s6_addr[i];
+        newname[j++] = ntohs(in6pcb.in6p_pcb.inp_lport);
+        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_ip6.ip6_src))
+            newname[j++] =
+                ntohs(*(uint16_t *) &in6pcb.in6p_ip6.ip6_src.s6_addr[2]);
+        else
+            newname[j++] = 0;
 #else
         for (i = 0; i < sizeof(struct in6_addr); i++)
             newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
@@ -1693,6 +1707,9 @@ var_udp6(register struct variable * vp,
 #elif defined(openbsd4)
         p = (caddr_t)in6pcb.inp_queue.cqe_next;
 	if (p == first) break;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+        p = (caddr_t)in6pcb.in6p_pcb.inp_queue.tqe_next;
+        if (p == first) break;
 #elif defined(__NetBSD__) && __NetBSD_Version__ >= 700000001
         p = (caddr_t)in6pcb.in6p_queue.tqe_next;
 	if (p == first) break;
@@ -1733,6 +1750,12 @@ var_udp6(register struct variable * vp,
                 ntohs(*(uint16_t *) & in6pcb.inp_laddr6.s6_addr[2]);
         else
             long_return = 0;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_ip6.ip6_src))
+            long_return =
+                ntohs(*(uint16_t *) & in6pcb.in6p_ip6.ip6_src.s6_addr[2]);
+        else
+            long_return = 0;
 #else
         if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_laddr))
             long_return =
@@ -2204,8 +2227,13 @@ var_tcp6(register struct variable * vp,
         }
 #endif
 #if defined(__NetBSD__) && __NetBSD_Version__ >= 106250000	/*1.6Y*/
+# if __NetBSD_Version__ < 999010400
         if (in6pcb.in6p_af != AF_INET6)
+             goto skip;
+# else
+        if (in6pcb.in6p_pcb.inp_af != AF_INET6)
             goto skip;
+# endif
 #elif defined(INP_ISIPV6)
 	if (!INP_ISIPV6(&in6pcb))
 	    goto skip;
@@ -2229,6 +2257,18 @@ var_tcp6(register struct variable * vp,
                 ntohs(*(uint16_t *) &in6pcb.inp_laddr6.s6_addr[2]);
         else
             newname[j++] = 0;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+        for (i = 0; i < sizeof(struct in6_addr); i++)
+            newname[j++] = in6pcb.in6p_ip6.ip6_src.s6_addr[i];
+        newname[j++] = ntohs(in6pcb.in6p_pcb.inp_lport);
+        for (i = 0; i < sizeof(struct in6_addr); i++)
+            newname[j++] = in6pcb.in6p_ip6.ip6_dst.s6_addr[i];
+        newname[j++] = ntohs(in6pcb.in6p_pcb.inp_fport);
+        if (IN6_IS_ADDR_LINKLOCAL(&in6pcb.in6p_ip6.ip6_src))
+            newname[j++] =
+                ntohs(*(uint16_t *) &in6pcb.in6p_ip6.ip6_src.s6_addr[2]);
+        else
+            newname[j++] = 0;
 #else
         for (i = 0; i < sizeof(struct in6_addr); i++)
             newname[j++] = in6pcb.in6p_laddr.s6_addr[i];
@@ -2249,7 +2289,11 @@ var_tcp6(register struct variable * vp,
         DEBUGMSG(("mibII/ipv6", " %d\n", exact));
 
 #if 1                           /* this is very odd but sometimes happen, and cause infinite loop */
+ #if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+        if (ntohs(in6pcb.in6p_pcb.inp_lport) == 0)
+ #else
         if (ntohs(in6pcb.inp_lport) == 0)
+ #endif
             goto skip;
 #endif
         result = snmp_oid_compare(name, *length, newname, j);
@@ -2279,6 +2323,9 @@ var_tcp6(register struct variable * vp,
 #elif defined(openbsd4)
         p = (caddr_t)in6pcb.inp_queue.cqe_next;
 	if (p == first) break;
+#elif defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+        p = (caddr_t)in6pcb.in6p_pcb.inp_queue.tqe_next;
+        if (p == first) break;
 #elif defined(__NetBSD__) && __NetBSD_Version__ >= 700000001
         p = (caddr_t)in6pcb.in6p_queue.tqe_next;
 	if (p == first) break;
@@ -2302,11 +2349,17 @@ var_tcp6(register struct variable * vp,
     *length = savnameLen;
     memcpy((char *) name, (char *) savname, *length * sizeof(oid));
     memcpy(&in6pcb, &savpcb, sizeof(savpcb));
+#if defined(__NetBSD__) && __NetBSD_Version__ >= 999010400
+    if (!NETSNMP_KLOOKUP(in6pcb.in6p_pcb.inp_ppcb, (char *) &tcpcb, sizeof(tcpcb))) {
+        DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcpcb at %p\n",
+                    in6pcb.in6p_pcb.inp_ppcb));
+#else
     if (!NETSNMP_KLOOKUP(in6pcb.inp_ppcb, (char *) &tcpcb, sizeof(tcpcb))) {
-	DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcpcb at %p\n",
-		    in6pcb.inp_ppcb));
-	found = 0;
-	return NULL;
+        DEBUGMSGTL(("mibII/ipv6", "klookup fail for tcb6.tcpcb at %p\n",
+                    in6pcb.inp_ppcb));
+#endif
+        found = 0;
+        return NULL;
     }
     *write_method = 0;
     *var_len = sizeof(long);    /* default to 'long' results */
