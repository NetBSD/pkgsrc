$NetBSD: patch-hw_xilinx__axienet.c,v 1.3 2012/09/11 17:13:45 asau Exp $

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>

--- hw/xilinx_axienet.c.orig	2012-09-05 14:03:06.000000000 +0000
+++ hw/xilinx_axienet.c
@@ -189,7 +189,7 @@ static uint16_t mdio_read_req(struct MDI
 
     phy = bus->devs[addr];
     if (phy && phy->read) {
-        data = phy->read(phy, reg);
+        data = (*phy->read)(phy, reg);
     } else {
         data = 0xffff;
     }
