$NetBSD: patch-src_devices_dev__sh4.cc,v 1.3 2018/03/21 17:39:42 kamil Exp $

Put the actual number of characters waiting in the FIFO instead of 1 or 0

Fix C++11 literals.

--- src/devices/dev_sh4.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_sh4.cc
@@ -844,7 +844,7 @@ DEVICE_ACCESS(sh4_pcic)
 		/*  Hardcoded to what OpenBSD/landisk uses:  */
 		if (writeflag == MEM_WRITE && idata != 0xac000000) {
 			fatal("sh4_pcic: SH4_PCICONF5 unknown value"
-			    " 0x%"PRIx32"\n", (uint32_t) idata);
+			    " 0x%" PRIx32 "\n", (uint32_t) idata);
 			exit(1);
 		}
 		break;
@@ -853,7 +853,7 @@ DEVICE_ACCESS(sh4_pcic)
 		/*  Hardcoded to what OpenBSD/landisk uses:  */
 		if (writeflag == MEM_WRITE && idata != 0x8c000000) {
 			fatal("sh4_pcic: SH4_PCICONF6 unknown value"
-			    " 0x%"PRIx32"\n", (uint32_t) idata);
+			    " 0x%" PRIx32 "\n", (uint32_t) idata);
 			exit(1);
 		}
 		break;
@@ -862,7 +862,7 @@ DEVICE_ACCESS(sh4_pcic)
 		/*  Hardcoded to what OpenBSD/landisk uses:  */
 		if (writeflag == MEM_WRITE && idata != ((64 - 1) << 20)) {
 			fatal("sh4_pcic: SH4_PCILSR0 unknown value"
-			    " 0x%"PRIx32"\n", (uint32_t) idata);
+			    " 0x%" PRIx32 "\n", (uint32_t) idata);
 			exit(1);
 		}
 		break;
@@ -871,7 +871,7 @@ DEVICE_ACCESS(sh4_pcic)
 		/*  Hardcoded to what OpenBSD/landisk uses:  */
 		if (writeflag == MEM_WRITE && idata != 0xac000000) {
 			fatal("sh4_pcic: SH4_PCILAR0 unknown value"
-			    " 0x%"PRIx32"\n", (uint32_t) idata);
+			    " 0x%" PRIx32 "\n", (uint32_t) idata);
 			exit(1);
 		}
 		break;
@@ -880,7 +880,7 @@ DEVICE_ACCESS(sh4_pcic)
 		/*  Hardcoded to what OpenBSD/landisk uses:  */
 		if (writeflag == MEM_WRITE && idata != ((64 - 1) << 20)) {
 			fatal("sh4_pcic: SH4_PCILSR1 unknown value"
-			    " 0x%"PRIx32"\n", (uint32_t) idata);
+			    " 0x%" PRIx32 "\n", (uint32_t) idata);
 			exit(1);
 		}
 		break;
@@ -889,15 +889,15 @@ DEVICE_ACCESS(sh4_pcic)
 		/*  Hardcoded to what OpenBSD/landisk uses:  */
 		if (writeflag == MEM_WRITE && idata != 0xac000000) {
 			fatal("sh4_pcic: SH4_PCILAR1 unknown value"
-			    " 0x%"PRIx32"\n", (uint32_t) idata);
+			    " 0x%" PRIx32 "\n", (uint32_t) idata);
 			exit(1);
 		}
 		break;
 
 	case SH4_PCIMBR:
 		if (writeflag == MEM_WRITE && idata != SH4_PCIC_MEM) {
-			fatal("sh4_pcic: PCIMBR set to 0x%"PRIx32", not"
-			    " 0x%"PRIx32"? TODO\n", (uint32_t) idata,
+			fatal("sh4_pcic: PCIMBR set to 0x%" PRIx32 ", not"
+			    " 0x%" PRIx32 "? TODO\n", (uint32_t) idata,
 			    (uint32_t) SH4_PCIC_MEM);
 			exit(1);
 		}
@@ -905,8 +905,8 @@ DEVICE_ACCESS(sh4_pcic)
 
 	case SH4_PCIIOBR:
 		if (writeflag == MEM_WRITE && idata != SH4_PCIC_IO) {
-			fatal("sh4_pcic: PCIIOBR set to 0x%"PRIx32", not"
-			    " 0x%"PRIx32"? TODO\n", (uint32_t) idata,
+			fatal("sh4_pcic: PCIIOBR set to 0x%" PRIx32 ", not"
+			    " 0x%" PRIx32 "? TODO\n", (uint32_t) idata,
 			    (uint32_t) SH4_PCIC_IO);
 			exit(1);
 		}
@@ -982,7 +982,7 @@ DEVICE_ACCESS(sh4)
 			d->sdmr3 = v;
 		else
 			d->sdmr2 = v;
-		debug("[ sh4: sdmr%i set to 0x%04"PRIx16" ]\n",
+		debug("[ sh4: sdmr%i set to 0x%04" PRIx16 " ]\n",
 		    relative_addr & 0x00040000? 3 : 2, v);
 		return 1;
 	}
@@ -1235,7 +1235,7 @@ DEVICE_ACCESS(sh4)
 			if (idata & (TCR_ICPF | TCR_ICPE1 | TCR_ICPE0 |
 			    TCR_CKEG1 | TCR_CKEG0 | TCR_TPSC2)) {
 				fatal("Unimplemented SH4 timer control"
-				    " bits: 0x%08"PRIx32". Aborting.\n",
+				    " bits: 0x%08" PRIx32 ". Aborting.\n",
 				    (int) idata);
 				exit(1);
 			}
@@ -1299,7 +1299,7 @@ DEVICE_ACCESS(sh4)
 			if (idata & ~0x00ffffff) {
 				fatal("[ SH4 DMA: Attempt to set top 8 "
 				    "bits of the count register? 0x%08"
-				    PRIx32" ]\n", (uint32_t) idata);
+				    PRIx32 " ]\n", (uint32_t) idata);
 				exit(1);
 			}
 
@@ -1703,8 +1703,8 @@ DEVICE_ACCESS(sh4)
 
 	case SH4_SCIF_BASE + SCIF_FDR:
 		/*  Nr of bytes in the TX and RX fifos, respectively:  */
-		odata = (console_charavail(d->scif_console_handle)? 1 : 0)
-		    + (d->scif_tx_fifo_cursize << 8);
+		odata = console_charavail(d->scif_console_handle) |
+		    (d->scif_tx_fifo_cursize << 8);
 		break;
 
 	case SH4_SCIF_BASE + SCIF_SPTR:
@@ -2000,4 +2000,3 @@ DEVINIT(sh4)
 
 	return 1;
 }
-
