$NetBSD: patch-packet.c,v 1.1 2016/02/26 21:06:38 tez Exp $

Fix for CVE-2016-1907
from https://anongit.mindrot.org/openssh.git/commit/?id=2fecfd486bdba9f51b3a789277bb0733ca36e1c0


--- packet.c.orig	2016-02-26 18:42:38.037291000 +0000
+++ packet.c
@@ -1581,6 +1581,7 @@ ssh_packet_read_poll2(struct ssh *ssh, u
 			logit("Bad packet length %u.", state->packlen);
 			if ((r = sshpkt_disconnect(ssh, "Packet corrupt")) != 0)
 				return r;
+			return SSH_ERR_CONN_CORRUPT;
 		}
 		sshbuf_reset(state->incoming_packet);
 	} else if (state->packlen == 0) {
