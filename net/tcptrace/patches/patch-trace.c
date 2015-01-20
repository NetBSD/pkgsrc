$NetBSD: patch-trace.c,v 1.1 2015/01/20 08:29:22 enami Exp $

--- trace.c.orig	2015-01-20 08:06:47.000000000 +0000
+++ trace.c
@@ -2416,12 +2416,12 @@ dotrace(
 	 * bytes in this pkt.
 	 */
 	if (otherdir->ack == 0){
-		owin = end - start ;
+		owin = (seqnum)end - (seqnum)start;
 	}
 	else {
 		/* ack  always acks 'received + 1' bytes, so subtract 1 
 		 * for owin */
-		owin = end - (otherdir->ack - 1);
+		owin = (seqnum)end - (otherdir->ack - 1);
 	}
 	
 	if (owin > thisdir->owin_max)
