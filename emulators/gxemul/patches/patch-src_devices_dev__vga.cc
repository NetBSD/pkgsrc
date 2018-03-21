$NetBSD: patch-src_devices_dev__vga.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_vga.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_vga.cc
@@ -516,8 +516,8 @@ DEVICE_TICK(vga)
 		int base = ((d->crtc_reg[VGA_CRTC_START_ADDR_HIGH] << 8)
 		    + d->crtc_reg[VGA_CRTC_START_ADDR_LOW]) * 2;
 		int new_u_y1, new_u_y2;
-		debug("[ dev_vga_tick: dyntrans access, %"PRIx64" .. %"
-		    PRIx64" ]\n", (uint64_t) low, (uint64_t) high);
+		debug("[ dev_vga_tick: dyntrans access, %" PRIx64 " .. %"
+		    PRIx64 " ]\n", (uint64_t) low, (uint64_t) high);
 		low -= base;
 		high -= base;
 		d->update_x1 = 0;
@@ -1266,4 +1266,3 @@ void dev_vga_init(struct machine *machin
 
 	vga_update_cursor(machine, d);
 }
-
