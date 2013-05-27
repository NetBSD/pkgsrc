$NetBSD: patch-.._.._ipxe_src_drivers_net_ns83820.c,v 1.1 2013/05/27 22:26:27 prlw1 Exp $

Build fix.

--- ../../ipxe/src/drivers/net/ns83820.c.orig	2010-02-02 16:12:44.000000000 +0000
+++ ../../ipxe/src/drivers/net/ns83820.c
@@ -687,7 +687,7 @@ static int ns83820_poll(struct nic *nic,
 	//			rx_ring[entry].link = 0;
 	rx_ring[entry].cmdsts = cpu_to_le32(CMDSTS_OWN);
 
-	ns->cur_rx = ++ns->cur_rx % NR_RX_DESC;
+	ns->cur_rx = (ns->cur_rx + 1) % NR_RX_DESC;
 
 	if (ns->cur_rx == 0)	/* We have wrapped the ring */
 	  kick_rx();
