$NetBSD: patch-iked_ike__conf.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Comment out impossible case (switch is enum)

--- iked/ike_conf.c.orig	2009-07-28 01:32:40.000000000 -0400
+++ iked/ike_conf.c	2018-05-28 19:48:04.934126933 -0400
@@ -4025,12 +4025,14 @@
 		SA_CONF(comp_alg, sa, comp_alg, 0);
 
 		switch (sa_protocol) {
+#if 0
 		case 0:
 			++*err;
 			plog(PLOG_INTERR, PLOGLOC, 0,
 			     "sa %s does not have sa_protocol field\n",
 			     sa_index);
 			break;
+#endif
 		case RCT_SATYPE_ESP:
 			if (!enc_alg) {
 				++*err;
@@ -4226,12 +4228,14 @@
 		if (!action)
 			POLICY_DEFAULT(action, action, 0);
 		switch (action) {
+#if 0
 		case 0:
 			++error;
 			plog(PLOG_INTERR, PLOGLOC, 0,
 			     "policy %s lacks action field\n",
 			     rc_vmem2str(policy->pl_index));
 			continue;
+#endif
 		case RCT_ACT_AUTO_IPSEC:
 			break;
 		default:
