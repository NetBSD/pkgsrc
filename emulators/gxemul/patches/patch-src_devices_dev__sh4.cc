$NetBSD: patch-src_devices_dev__sh4.cc,v 1.4 2019/01/04 13:35:16 ryoon Exp $

Put the actual number of characters waiting in the FIFO instead of 1 or 0

--- src/devices/dev_sh4.cc.orig	2018-12-07 06:29:22.000000000 +0000
+++ src/devices/dev_sh4.cc
@@ -1715,8 +1715,8 @@ DEVICE_ACCESS(sh4)
 
 	case SH4_SCIF_BASE + SCIF_FDR:
 		/*  Nr of bytes in the TX and RX fifos, respectively:  */
-		odata = (console_charavail(d->scif_console_handle)? 1 : 0)
-		    + (d->scif_tx_fifo_cursize << 8);
+		odata = console_charavail(d->scif_console_handle) |
+		    (d->scif_tx_fifo_cursize << 8);
 		break;
 
 	case SH4_SCIF_BASE + SCIF_SPTR:
