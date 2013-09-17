$NetBSD: patch-mdart_mdart__adp.cc,v 1.1 2013/09/17 21:13:45 joerg Exp $

--- mdart/mdart_adp.cc.orig	2013-09-17 20:01:09.000000000 +0000
+++ mdart/mdart_adp.cc
@@ -105,7 +105,7 @@ void ADP::sendDarq(nsaddr_t reqId, int r
 #ifdef DEBUG_ADP
 	fprintf(stdout, "%.9f\tADP::sendDarq(%d)\t\t\tin node %d\twith address %s\n", CURRENT_TIME, reqId, mdart_->id_, bitString(mdart_->address_));
 #endif
-	nsaddr_t dstAdd_ = hash(reqId);
+	nsaddr_t dstAdd_ = ::hash(reqId);
 #ifdef DEBUG_ADP
 	fprintf(stdout, "\tsending darq for node %s\n", bitString(dstAdd_));
 #endif
@@ -393,7 +393,7 @@ void ADP::sendDaup() {
 	fprintf(stdout, "%.9f\tMDART::sendDaup()\t\t\t\tin node %d\twith address %s\n", CURRENT_TIME, mdart_->id_, bitString(mdart_->address_));
 //	printDHT();
 #endif
-	nsaddr_t dstAdd_ = hash(mdart_->id_);
+	nsaddr_t dstAdd_ = ::hash(mdart_->id_);
 #ifdef DEBUG_ADP
 	fprintf(stdout, "\tsending daup for node  %s\n", bitString(dstAdd_));
 	mdart_->routingTable_->print();
