$NetBSD: patch-src_devices_dev__sh4.cc,v 1.1 2017/07/16 14:10:58 christos Exp $

Put the actual number of characters waiting in the FIFO instead of 1 or 0

--- /usr/src/gxemul/gxemul-0.6.0.1/src/devices/dev_sh4.cc	2014-08-17 04:45:12.000000000 -0400
+++ ./dev_sh4.cc	2017-07-16 09:58:19.288954403 -0400
@@ -1703,8 +1703,8 @@
 
 	case SH4_SCIF_BASE + SCIF_FDR:
 		/*  Nr of bytes in the TX and RX fifos, respectively:  */
-		odata = (console_charavail(d->scif_console_handle)? 1 : 0)
-		    + (d->scif_tx_fifo_cursize << 8);
+		odata = console_charavail(d->scif_console_handle) |
+		    (d->scif_tx_fifo_cursize << 8);
 		break;
 
 	case SH4_SCIF_BASE + SCIF_SPTR:
