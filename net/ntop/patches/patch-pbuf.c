$NetBSD: patch-pbuf.c,v 1.1 2011/02/11 11:12:15 adam Exp $

Do not discard packets with bad checksum.
Bad checksum may occur when local interface has hardware-assisted checksumming.

--- pbuf.c.orig	2011-02-11 10:00:09.000000000 +0000
+++ pbuf.c
@@ -1175,7 +1175,6 @@ static void processIpPkt(const u_char *b
        && (in_cksum((const u_short *)bp, hlen, 0) != 0)
        ) {
       incrementTrafficCounter(&myGlobals.device[actualDeviceId].rcvdPktStats.badChecksum, 1);
-      return;
     }
 
   /*
