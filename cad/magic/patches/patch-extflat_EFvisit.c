$NetBSD: patch-extflat_EFvisit.c,v 1.2 2013/03/07 22:05:12 joerg Exp $

--- extflat/EFvisit.c.orig	2013-03-02 22:43:10.000000000 +0000
+++ extflat/EFvisit.c
@@ -576,7 +576,7 @@ efVisitSingleResist(hc, name1, name2, re
 	return 0;
 
     if ((he = EFHNLook(hc->hc_hierName, name2, "resist(2)")) == NULL)
-	return;
+	return 0;
     n2 = ((EFNodeName *) HashGetValue(he))->efnn_node;
     if (n2->efnode_flags & EF_KILLED)
 	return 0;
