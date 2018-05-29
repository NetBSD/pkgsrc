$NetBSD: patch-iked_ikev1_ikev1.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Remove unused

--- iked/ikev1/ikev1.c.orig	2008-07-07 05:36:08.000000000 -0400
+++ iked/ikev1/ikev1.c	2018-05-28 19:50:20.088751812 -0400
@@ -1457,8 +1457,6 @@
 #define	IKEV1_DEFAULT_RETRY_CHECKPH1 30
 
 	if (!iph1) {
-		struct sched *sc;
-
 		if (isakmp_ph1begin_i(rm_info, iph2->dst, iph2->src) < 0) {
 			plog(PLOG_INTERR, PLOGLOC, 0,
 			     "failed to initiate phase 1 negotiation for %s\n",
@@ -1467,7 +1465,7 @@
 			goto fail;
 		}
 		iph2->retry_checkph1 = IKEV1_DEFAULT_RETRY_CHECKPH1;
-		sc = sched_new(1, isakmp_chkph1there_stub, iph2);
+		sched_new(1, isakmp_chkph1there_stub, iph2);
 		plog(PLOG_INFO, PLOGLOC, 0,
 		     "IPsec-SA request for %s queued "
 		     "since no phase1 found\n",
