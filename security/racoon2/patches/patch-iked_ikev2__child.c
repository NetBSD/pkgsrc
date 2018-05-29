$NetBSD: patch-iked_ikev2__child.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Comment out unused

--- iked/ikev2_child.c.orig	2008-09-10 04:30:58.000000000 -0400
+++ iked/ikev2_child.c	2018-05-28 20:02:17.518182437 -0400
@@ -1373,7 +1373,9 @@
 	struct prop_pair *matching_proposal = 0;
 	struct prop_pair *matching_my_proposal = 0;
 	struct prop_pair **new_my_proposal_list = 0;
+#ifdef notyet
 	rc_vchar_t *g_ir;
+#endif
 	int err = 0;
 
 	/* update IPsec SA with received parameter */
@@ -1451,8 +1453,8 @@
 		       use_transport_mode ? "transport" : "tunnel"));
 	}
 
-	g_ir = 0;
 #ifdef notyet
+	g_ir = 0;
 	/* if (ke_i && ke_r) g_ir = g^i^r */
 #endif
 
