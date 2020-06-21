$NetBSD: patch-ntpd_ntp__proto.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/ntp_proto.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpd/ntp_proto.c
@@ -717,7 +717,7 @@ receive(
 	 * items from the packet once we can be sure they are indeed
 	 * there.
 	 */
-	if (rbufp->recv_length < LEN_PKT_NOMAC) {
+	if ((size_t)rbufp->recv_length < LEN_PKT_NOMAC) {
 		sys_badlength++;
 		return;				/* bogus length */
 	}
@@ -4680,7 +4680,7 @@ fast_xmit(
 	 * packet is not authenticated.
 	 */
 	sendlen = LEN_PKT_NOMAC;
-	if (rbufp->recv_length == sendlen) {
+	if ((size_t)rbufp->recv_length == sendlen) {
 		sendpkt(&rbufp->recv_srcadr, rbufp->dstadr, 0, &xpkt,
 		    sendlen);
 		DPRINTF(1, ("fast_xmit: at %ld %s->%s mode %d len %lu\n",
