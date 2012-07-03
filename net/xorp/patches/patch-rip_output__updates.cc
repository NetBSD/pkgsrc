$NetBSD: patch-rip_output__updates.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- rip/output_updates.cc.orig	2012-07-03 16:24:18.000000000 +0000
+++ rip/output_updates.cc
@@ -78,7 +78,7 @@ OutputUpdates<A>::output_packet()
 						origin, r->tag(),
 						r->policytags());
 
-	bool accepted = do_filtering(copy);
+	bool accepted = this->do_filtering(copy);
 	if (!accepted) {
 	    delete copy;
 	    continue;
