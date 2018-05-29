$NetBSD: patch-iked_ikev1_ipsec__doi.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix memset argument
Fix unused

--- iked/ikev1/ipsec_doi.c.orig	2008-07-07 05:36:08.000000000 -0400
+++ iked/ikev1/ipsec_doi.c	2018-05-28 21:19:12.197533568 -0400
@@ -220,7 +220,9 @@
 	rc_vchar_t *newsa;
 	struct isakmpsa *sa, tsa;
 	struct prop_pair *s, *p;
+#if 0
 	int prophlen;
+#endif
 	int i;
 
 	if (iph1->approval) {
@@ -232,8 +234,10 @@
 		if (pair[i] == NULL)
 			continue;
 		for (s = pair[i]; s; s = s->next) {
+#if 0
 			prophlen = sizeof(struct isakmp_pl_p)
 					+ s->prop->spi_size;
+#endif
 			/* compare proposal and select one */
 			for (p = s; p; p = p->tnext) {
 				sa = get_ph1approvalx(p, iph1->proposal,
@@ -254,8 +258,10 @@
 			if (pair[i] == NULL)
 				continue;
 			for (s = pair[i]; s; s = s->next) {
+#if 0
 				prophlen = sizeof(struct isakmp_pl_p)
 						+ s->prop->spi_size;
+#endif
 				for (p = s; p; p = p->tnext) {
 					print_ph1mismatched(p,
 							    iph1->proposal);
@@ -1238,7 +1244,7 @@
 			"failed to get buffer.\n");
 		return NULL;
 	}
-	memset(pair, 0, sizeof(pair));
+	memset(pair, 0, sizeof(*pair));
 
 	bp = (caddr_t)(sab + 1);
 	tlen = sa->l - sizeof(*sab);
