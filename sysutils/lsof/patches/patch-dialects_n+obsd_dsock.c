$NetBSD: patch-dialects_n+obsd_dsock.c,v 1.1 2023/01/13 04:33:17 mrg Exp $

Handle the inpcb / inpcb6 merge.

--- dialects/n+obsd/dsock.c.orig	2005-08-08 12:53:34.000000000 -0700
+++ dialects/n+obsd/dsock.c	2023-01-12 15:42:17.533910449 -0800
@@ -58,11 +58,18 @@
 process_socket(sa)
 	KA_T sa;			/* socket address in kernel */
 {
+#if     NETBSDV >= 9099104
+# define NETBSD_MERGED_INPCB
+#endif
 	struct domain d;
 	unsigned char *fa = (unsigned char *)NULL;
 	int fam;
 	int fp, lp;
+#ifdef  NETBSD_MERGED_INPCB
+	struct in4pcb inp;
+#else
 	struct inpcb inp;
+#endif
 	unsigned char *la = (unsigned char *)NULL;
 	struct protosw p;
 	struct socket s;
@@ -73,6 +80,9 @@
 	struct sockaddr_un un;
 
 #if	defined(HASIPv6) && defined(NETBSDV) && !defined(HASINRIAIPv6)
+#ifdef  NETBSD_MERGED_INPCB
+# define in6p_ppcb in6p_pcb.inp_ppcb
+#endif
 	struct in6pcb in6p;
 #endif	/* defined(HASIPv6) && defined(NETBSDV) && !defined(HASINRIAIPv6) */
 
@@ -211,6 +221,16 @@
 					       (char *)NULL, 0));
 		if (p.pr_protocol == IPPROTO_TCP)
 		    ta = (KA_T)in6p.in6p_ppcb;
+#ifdef NETBSD_MERGED_INPCB
+	        la = (unsigned char *)&in6p_laddr(&in6p);
+	        lp = (int)ntohs(in6p.in6p_pcb.inp_lport);
+		if (!IN6_IS_ADDR_UNSPECIFIED(&in6p_faddr(&in6p))
+		||  (in6p.in6p_pcb.inp_fport))
+		{
+		    fa = (unsigned char *)&in6p_faddr(&in6p);
+		    fp = (int)ntohs(in6p.in6p_pcb.inp_fport);
+		}
+#else
 	        la = (unsigned char *)&in6p.in6p_laddr;
 	        lp = (int)ntohs(in6p.in6p_lport);
 		if (!IN6_IS_ADDR_UNSPECIFIED(&in6p.in6p_faddr)
@@ -219,13 +239,14 @@
 		    fa = (unsigned char *)&in6p.in6p_faddr;
 		    fp = (int)ntohs(in6p.in6p_fport);
 		}
+#endif
 	    } else
 #endif	/* defined(HASIPv6) && defined(NETBSDV) && !defined(HASINRIAIPv6) */
 
 	    {
 
 	    /*
-	     * Read IPv4 or IPv6 (OpenBSD) protocol control block.
+	     * Read IPv4 or IPv6 (NetBSD) protocol control block.
 	     */
 		if (!s.so_pcb
 		||  kread((KA_T)s.so_pcb, (char *)&inp, sizeof(inp))) {
@@ -242,22 +263,38 @@
 		    enter_nm(Namech);
 		    return;
 		}
+#ifdef  NETBSD_MERGED_INPCB
+#define inp_ppcb in4p_pcb.inp_ppcb
+#define inp_lport in4p_pcb.inp_lport
+#endif
 		enter_dev_ch(print_kptr((KA_T)(inp.inp_ppcb ? inp.inp_ppcb
 							    : s.so_pcb),
 					       (char *)NULL, 0));
 		if (p.pr_protocol == IPPROTO_TCP)
 		    ta = (KA_T)inp.inp_ppcb;
 		lp = (int)ntohs(inp.inp_lport);
+#ifdef  NETBSD_MERGED_INPCB
+#undef inp_ppcb
+#undef inp_lport
+#endif
 		if (fam == AF_INET) {
 
 		/*
 		 * Save IPv4 address information.
 		 */
+#ifdef NETBSD_MERGED_INPCB
+		    la = (unsigned char *)&in4p_laddr(&inp);
+		    if (in4p_faddr(&inp).s_addr != INADDR_ANY || inp.in4p_pcb.inp_fport) {
+			fa = (unsigned char *)&in4p_faddr(&inp);
+			fp = (int)ntohs(inp.in4p_pcb.inp_fport);
+		    }
+#else
 		    la = (unsigned char *)&inp.inp_laddr;
 		    if (inp.inp_faddr.s_addr != INADDR_ANY || inp.inp_fport) {
 			fa = (unsigned char *)&inp.inp_faddr;
 			fp = (int)ntohs(inp.inp_fport);
 		    }
+#endif
 		}
 
 #if	defined(HASIPv6) && (defined(OPENBSDV) || defined(HASINRIAIPv6))
