$NetBSD: patch-.._.._ipxe_src_drivers_net_tulip.c,v 1.1 2013/05/27 22:26:27 prlw1 Exp $

Build fix.

--- ../../ipxe/src/drivers/net/tulip.c.orig	2010-02-02 16:12:44.000000000 +0000
+++ ../../ipxe/src/drivers/net/tulip.c
@@ -1171,7 +1171,7 @@ static int tulip_poll(struct nic *nic, i
     if (rx_ring[tp->cur_rx].status & 0x00008000) {
 	/* return the descriptor and buffer to receive ring */
         rx_ring[tp->cur_rx].status = 0x80000000;
-	tp->cur_rx = (++tp->cur_rx) % RX_RING_SIZE;
+	tp->cur_rx = (tp->cur_rx + 1) % RX_RING_SIZE;
         return 0;
     }
 
@@ -1180,7 +1180,7 @@ static int tulip_poll(struct nic *nic, i
 
     /* return the descriptor and buffer to receive ring */
     rx_ring[tp->cur_rx].status = 0x80000000;
-    tp->cur_rx = (++tp->cur_rx) % RX_RING_SIZE;
+    tp->cur_rx = (tp->cur_rx + 1) % RX_RING_SIZE;
 
     return 1;
 }
