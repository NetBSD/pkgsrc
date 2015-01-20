$NetBSD: patch-qemu-xen-traditional_hw_e1000.c,v 1.1 2015/01/20 16:42:13 bouyer Exp $

From sysutils/xentools33/patches/patch-ak.

qemu-0.13.x will include this fix:
http://git.qemu.org/qemu.git/commit/?id=9651ac55e5de0e1534d898316cc851af6ffc4334

--- qemu-xen-traditional/hw/e1000.c.orig	2014-10-06 17:50:24.000000000 +0200
+++ qemu-xen-traditional/hw/e1000.c	2015-01-19 13:16:38.000000000 +0100
@@ -265,16 +265,20 @@
 
     s->eecd_state.old_eecd = val & (E1000_EECD_SK | E1000_EECD_CS |
             E1000_EECD_DI|E1000_EECD_FWE_MASK|E1000_EECD_REQ);
+    if (!(E1000_EECD_CS & val))                        // CS inactive; nothing to do
+       return;
+    if (E1000_EECD_CS & (val ^ oldval)) {      // CS rise edge; reset state
+       s->eecd_state.val_in = 0;
+       s->eecd_state.bitnum_in = 0;
+       s->eecd_state.bitnum_out = 0;
+       s->eecd_state.reading = 0;
+    }
     if (!(E1000_EECD_SK & (val ^ oldval)))	// no clock edge
         return;
     if (!(E1000_EECD_SK & val)) {		// falling edge
         s->eecd_state.bitnum_out++;
         return;
     }
-    if (!(val & E1000_EECD_CS)) {		// rising, no CS (EEPROM reset)
-        memset(&s->eecd_state, 0, sizeof s->eecd_state);
-        return;
-    }
     s->eecd_state.val_in <<= 1;
     if (val & E1000_EECD_DI)
         s->eecd_state.val_in |= 1;
