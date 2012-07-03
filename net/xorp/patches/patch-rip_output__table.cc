$NetBSD: patch-rip_output__table.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rip/output_table.cc.orig	2012-07-03 16:23:55.000000000 +0000
+++ rip/output_table.cc
@@ -68,7 +68,7 @@ OutputTable<A>::output_packet()
 					        origin, r->tag(),
 						r->policytags());
 	
-	bool accepted = do_filtering(copy);
+	bool accepted = this->do_filtering(copy);
 	if (!accepted) {
 	    delete copy;
 	    continue;
