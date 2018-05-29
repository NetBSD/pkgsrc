$NetBSD: patch-kinkd-ipsec__doi.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix wrong memset
Fix pointer signness

--- kinkd/ipsec_doi.c.orig	2018-05-28 19:34:49.793231430 -0400
+++ kinkd/ipsec_doi.c	2018-05-28 19:35:27.322259892 -0400
@@ -654,7 +654,7 @@
 			"failed to get buffer.\n");
 		return NULL;
 	}
-	memset(pair, 0, sizeof(pair));
+	memset(pair, 0, sizeof(*pair));
 
 	bp = (caddr_t)(sab + 1);
 	tlen = sa->l - sizeof(*sab);
@@ -2034,7 +2034,7 @@
 
 	/* set prefix */
 	if (len2) {
-		unsigned char *p = new->v + sizeof(struct ipsecdoi_id_b) + len1;
+		unsigned char *p = (unsigned char *)new->v + sizeof(struct ipsecdoi_id_b) + len1;
 		unsigned int bits = prefixlen;
 
 		while (bits >= 8) {
@@ -2141,7 +2141,7 @@
 		plen = 0;
 		max = alen <<3;
 
-		p = buf->v
+		p = (unsigned char *)buf->v
 			+ sizeof(struct ipsecdoi_id_b)
 			+ alen;
 
