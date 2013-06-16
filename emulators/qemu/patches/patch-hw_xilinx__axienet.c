$NetBSD: patch-hw_xilinx__axienet.c,v 1.4 2013/06/16 18:27:25 tsutsui Exp $

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- hw/xilinx_axienet.c.orig	2013-05-24 13:37:57.000000000 +0000
+++ hw/xilinx_axienet.c
@@ -188,7 +188,7 @@ static uint16_t mdio_read_req(struct MDI
 
     phy = bus->devs[addr];
     if (phy && phy->read) {
-        data = phy->read(phy, reg);
+        data = (*phy->read)(phy, reg);
     } else {
         data = 0xffff;
     }
