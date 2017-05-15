$NetBSD: patch-src_devices_dev__footbridge.cc,v 1.1 2017/05/15 01:45:49 christos Exp $
- fix hang interrupt issue. Always assert the irq's even if we have alread
  asserted the global irq for the device. prevents hangs with cats.
- add cosmetic (no/op) code for the SDRAM setup that cats does.

--- src/devices/dev_footbridge.cc.orig	2014-08-17 04:45:12.000000000 -0400
+++ src/devices/dev_footbridge.cc	2017-05-14 21:30:25.392564100 -0400
@@ -154,7 +154,7 @@
 	struct footbridge_data *d = (struct footbridge_data *) interrupt->extra;
 	d->irq_status |= interrupt->line;
 
-	if ((d->irq_status & d->irq_enable) && !d->irq_asserted) {
+	if ((d->irq_status & d->irq_enable) /* && !d->irq_asserted */) {
 		d->irq_asserted = 1;
 		INTERRUPT_ASSERT(d->irq);
 	}
@@ -455,6 +455,42 @@
 		INTERRUPT_DEASSERT(d->timer_irq[timer_nr]);
 		break;
 
+	case SDRAM_BA_MASK:
+		if (writeflag == MEM_READ) {
+			fatal("[ footbridge read to sdram_ba_mask ]\n");
+			exit(1);
+		} else {
+			switch (idata) {
+			case SDRAM_MASK_256KB:
+			case SDRAM_MASK_512KB:
+			case SDRAM_MASK_1MB:
+			case SDRAM_MASK_2MB:
+			case SDRAM_MASK_4MB:
+			case SDRAM_MASK_8MB:
+			case SDRAM_MASK_16MB:
+			case SDRAM_MASK_32MB:
+			case SDRAM_MASK_64MB:
+			case SDRAM_MASK_128MB:
+			case SDRAM_MASK_256MB:
+				break;
+			default:
+				fatal("[ footbridge write to sdram_ba_mask "
+				    "%#llx ]\n", (long long)idata);
+				break;
+			}
+		}
+		break;
+	case SDRAM_BA_OFFSET:
+		if (writeflag == MEM_READ) {
+			fatal("[ footbridge read to sdram_ba_offset ]\n");
+			exit(1);
+		} else {
+			if (idata != 0)
+				fatal("[ footbridge write to sdram_ba_offset "
+				    "%#llx ]\n", (long long)idata);
+		}
+		break;
+
 	default:if (writeflag == MEM_READ) {
 			fatal("[ footbridge: read from 0x%x ]\n",
 			    (int)relative_addr);
