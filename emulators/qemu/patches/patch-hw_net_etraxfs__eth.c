$NetBSD: patch-hw_net_etraxfs__eth.c,v 1.1 2013/07/09 17:00:58 tsutsui Exp $

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- hw/net/etraxfs_eth.c.orig	2013-06-26 21:47:29.000000000 +0000
+++ hw/net/etraxfs_eth.c
@@ -185,7 +185,7 @@ static void mdio_read_req(struct qemu_md
 
     phy = bus->devs[bus->addr];
     if (phy && phy->read) {
-        bus->data = phy->read(phy, bus->req);
+        bus->data = (*phy->read)(phy, bus->req);
     } else {
         bus->data = 0xffff;
     }
@@ -359,7 +359,7 @@ static void eth_validate_duplex(struct f
     int new_mm = 0;
 
     phy = eth->mdio_bus.devs[eth->phyaddr];
-    phy_duplex = !!(phy->read(phy, 18) & (1 << 11));
+    phy_duplex = !!((*phy->read)(phy, 18) & (1 << 11));
     mac_duplex = !!(eth->regs[RW_REC_CTRL] & 128);
 
     if (mac_duplex != phy_duplex) {
