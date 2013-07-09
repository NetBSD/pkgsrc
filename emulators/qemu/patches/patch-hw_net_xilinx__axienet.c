$NetBSD: patch-hw_net_xilinx__axienet.c,v 1.1 2013/07/09 17:00:58 tsutsui Exp $

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- hw/net/xilinx_axienet.c.orig	2013-06-26 21:47:29.000000000 +0000
+++ hw/net/xilinx_axienet.c
@@ -207,7 +207,7 @@ static uint16_t mdio_read_req(struct MDI
 
     phy = bus->devs[addr];
     if (phy && phy->read) {
-        data = phy->read(phy, reg);
+        data = (*phy->read)(phy, reg);
     } else {
         data = 0xffff;
     }
