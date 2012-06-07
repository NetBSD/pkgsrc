$NetBSD: patch-hw_xilinx__axienet.c,v 1.2 2012/06/07 21:23:46 ryoon Exp $

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>

--- hw/xilinx_axienet.c.orig	2012-06-01 09:13:13.000000000 +0000
+++ hw/xilinx_axienet.c
@@ -189,7 +189,7 @@ static uint16_t mdio_read_req(struct MDI
 
     phy = bus->devs[addr];
     if (phy && phy->read) {
-        data = phy->read(phy, reg);
+        data = (*phy->read)(phy, reg);
     } else {
         data = 0xffff;
     }
