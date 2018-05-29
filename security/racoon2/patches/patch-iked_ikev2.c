$NetBSD: patch-iked_ikev2.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Remove unused

--- iked/ikev2.c.orig	2010-02-01 05:30:51.000000000 -0500
+++ iked/ikev2.c	2018-05-28 19:59:33.332024762 -0400
@@ -1945,8 +1945,6 @@
 	struct ikev2_payload_header *p;
 	int type;
 	struct ikev2_payload_header *id_i = 0;
-	struct ikev2_payload_header *cert = 0;
-	struct ikev2_payload_header *certreq = 0;
 	struct ikev2_payload_header *id_r = 0;
 	struct ikev2payl_auth *auth = 0;
 	struct ikev2_payload_header *sa_i2 = 0;
@@ -2010,10 +2008,8 @@
 			 * accept up to four X.509 certificates in support of authentication,
 			 */
 #endif
-			cert = p;
 			break;
 		case IKEV2_PAYLOAD_CERTREQ:
-			certreq = p;
 			break;
 		case IKEV2_PAYLOAD_ID_R:
 			if (id_r)
@@ -2639,7 +2635,6 @@
 	int type;
 	struct ikev2_payload_header *p;
 	struct ikev2_payload_header *id_r = 0;
-	struct ikev2_payload_header *cert = 0;
 	struct ikev2payl_auth *auth = 0;
 	struct ikev2_payload_header *sa_r2 = 0;
 	struct ikev2_payload_header *ts_i = 0;
@@ -2669,7 +2664,6 @@
 			 * accept up to four X.509 certificates in support of authentication,
 			 */
 #endif
-			cert = p;
 			break;
 		case IKEV2_PAYLOAD_AUTH:
 			if (auth)
@@ -2791,7 +2785,6 @@
 	int type;
 	struct ikev2_payload_header *p;
 	struct ikev2_payload_header *cfg = 0;
-	struct ikev2_payload_header *id_r = 0;
 	struct ikev2_payload_header *sa_r2 = 0;
 	struct ikev2_payload_header *ts_i = 0;
 	struct ikev2_payload_header *ts_r = 0;
@@ -2834,7 +2827,6 @@
 		case IKEV2_PAYLOAD_ENCRYPTED:
 			break;
 		case IKEV2_PAYLOAD_ID_R:
-			id_r = p;
 			break;
 		case IKEV2_PAYLOAD_SA:
 			sa_r2 = p;
@@ -4541,7 +4533,9 @@
 	int i;
 	uint32_t spi;
 	struct ikev2_child_sa *child_sa;
+#if 0
 	struct rcf_policy *policy;
+#endif
 
 	d = (struct ikev2payl_delete *)p;
 	protocol_id = d->dh.protocol_id;
@@ -4641,7 +4635,9 @@
 				break;
 			}
 
+#if 0
 			policy = child_sa->selector->pl;
+#endif
 
 			/* (draft-17)
 			 * If by chance both ends of a set
