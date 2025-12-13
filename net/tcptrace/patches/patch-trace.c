$NetBSD: patch-trace.c,v 1.2 2025/12/13 16:42:03 vins Exp $

--- trace.c.orig	2004-11-04 22:43:51.000000000 +0000
+++ trace.c
@@ -2061,14 +2061,14 @@ dotrace(
 	 /* Use relative sequence numbers after the first segment in either direction */
 	 snprintf(buf2, sizeof(buf2), "%lu:%lu(%lu) ", (start - a2b_first_seqnum),
 		  (end - a2b_first_seqnum), (end-start));
-	 strncat(buf1, buf2, strlen(buf2));
+	 strncat(buf1, buf2, sizeof(buf1) - strlen(buf1) - 1);
 	 if(a2b_first_seqnum == 0 && !SYN_SET(ptcp)) // Don't use relative sequence numbers until handshake is complete.
 	   a2b_first_seqnum = thisdir->min_seq;
       }else if(dir == B2A) {
 	 /* Use relative sequence numbers after the first segment in either direction */
 	 snprintf(buf2, sizeof(buf2), "%lu:%lu(%lu) ", (start - b2a_first_seqnum),
 		  (end - b2a_first_seqnum), (end-start));
-	 strncat(buf1, buf2, strlen(buf2));
+	 strncat(buf1, buf2, sizeof(buf1) - strlen(buf1) - 1);
 	 if(b2a_first_seqnum == 0 && !SYN_SET(ptcp))
 	   b2a_first_seqnum = thisdir->min_seq;
       }
@@ -2080,26 +2080,26 @@ dotrace(
 	   snprintf(buf2, sizeof(buf2), "ack %lu ", (th_ack - b2a_first_seqnum));
 	 else if(dir == B2A)
 	   snprintf(buf2, sizeof(buf2), "ack %lu ", (th_ack - a2b_first_seqnum));
-	 strncat(buf1, buf2, strlen(buf2));
+	 strncat(buf1, buf2, sizeof(buf1) - strlen(buf1) - 1);
       }
       
       /* Advertised Window */
 	 memset(&buf2, 0, sizeof(buf2));
 	 snprintf(buf2, sizeof(buf2), "win %lu ", eff_win);
-	 strncat(buf1, buf2, strlen(buf2));
+	 strncat(buf1, buf2, sizeof(buf1) - strlen(buf1) - 1);
       
       /* Retransmits */
       if(retrans) {
 	 memset(&buf2, 0, sizeof(buf2));
 	 snprintf(buf2, sizeof(buf2), "R ");
-	 strncat(buf1, buf2, strlen(buf2));
+	 strncat(buf1, buf2, sizeof(buf1) - strlen(buf1) - 1);
       }
       
       /* Hardware Duplicates */ 
       if(hw_dup) {
 	 memset(&buf2, 0, sizeof(buf2));
 	 snprintf(buf2, sizeof(buf2), "HD ");
-	 strncat(buf1, buf2, strlen(buf2));
+	 strncat(buf1, buf2, sizeof(buf1) - strlen(buf1) - 1);
       }
       
       /* Draw the segment ------>/<------- */
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
