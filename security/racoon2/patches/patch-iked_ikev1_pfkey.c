$NetBSD: patch-iked_ikev1_pfkey.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix unused

--- iked/ikev1/pfkey.c.orig	2008-04-01 06:39:13.000000000 -0400
+++ iked/ikev1/pfkey.c	2018-05-28 19:55:26.598592949 -0400
@@ -562,7 +562,9 @@
 	unsigned int satype, mode;
 	struct saprop *pp;
 	struct saproto *pr;
+#ifdef notyet
 	uint32_t minspi, maxspi;
+#endif
 #if 0
 	int proxy = 0;
 #endif
@@ -613,13 +615,15 @@
 		}
 		/* this works around a bug in Linux kernel where it
 		 * allocates 4 byte spi's for IPCOMP */
-		else if (satype == SADB_X_SATYPE_IPCOMP) {
+#ifdef notyet
+		if (satype == SADB_X_SATYPE_IPCOMP) {
 			minspi = 0x100;
 			maxspi = 0xffff;
 		} else {
 			minspi = 0;
 			maxspi = 0;
 		}
+#endif
 		mode = ipsecdoi2rc_mode(pr->encmode);
 		if (mode == 0) {
 			plog(PLOG_INTERR, PLOGLOC, NULL,
@@ -635,8 +639,10 @@
 		param.pref_dst = 0;
 		param.satype = satype;
 		param.samode = mode;
-		/* param.minspi = minspi; */
-		/* param.maxspi = maxspi; */
+#ifdef notyet
+		param.minspi = minspi;
+		param.maxspi = maxspi;
+#endif
 		param.reqid = pr->reqid_in;
 		param.seq = iph2->seq;
 		if (iph2->sadb_request.method->getspi(&param)) {
@@ -747,7 +753,9 @@
         unsigned int e_keylen, a_keylen, flags;
         int satype, mode;
         struct rcpfk_msg param;
+#if 0
         unsigned int wsize = 4;        /* XXX static size of window */
+#endif
 
         /* sanity check */
         if (iph2->approval == NULL) {
@@ -773,10 +781,13 @@
                         plog(PLOG_PROTOERR, PLOGLOC, 0,
                              "invalid proto_id %d\n", pr->proto_id);
                         return -1;
-                } else if (satype == RCT_SATYPE_IPCOMP) {
+                }
+#if 0
+		if (satype == RCT_SATYPE_IPCOMP) {
                         /* IPCOMP has no replay window */
                         wsize = 0;
                 }
+#endif
                 mode = ipsecdoi2rc_mode(pr->encmode);
                 if (mode == 0) {
                         plog(PLOG_PROTOERR, PLOGLOC, 0,
