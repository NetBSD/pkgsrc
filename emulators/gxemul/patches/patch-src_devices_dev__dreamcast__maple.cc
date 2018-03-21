$NetBSD: patch-src_devices_dev__dreamcast__maple.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_dreamcast_maple.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_dreamcast_maple.cc
@@ -387,14 +387,14 @@ void maple_do_dma_xfer(struct cpu *cpu, 
 	}
 
 	/*  debug("[ dreamcast_maple: DMA transfer, dmaaddr = "
-	    "0x%08"PRIx32" ]\n", addr);  */
+	    "0x%08" PRIx32 " ]\n", addr);  */
 
 	/*
 	 *  DMA transfers must be 32-byte aligned, according to Marcus
 	 *   Comstedt's Maple demo program.
 	 */
 	if (addr & 0x1f) {
-		fatal("[ dreamcast_maple: dmaaddr 0x%08"PRIx32" is NOT"
+		fatal("[ dreamcast_maple: dmaaddr 0x%08" PRIx32 " is NOT"
 		    " 32-byte aligned; aborting ]\n", addr);
 		return;
 	}
@@ -432,7 +432,7 @@ void maple_do_dma_xfer(struct cpu *cpu, 
 
 		if (receive_addr & 0xe000001f)
 			fatal("[ dreamcast_maple: WARNING! receive address 0x"
-			    "%08"PRIx32" isn't valid! ]\n", receive_addr);
+			    "%08" PRIx32 " isn't valid! ]\n", receive_addr);
 
 		/*  Read the command word for this message:  */
 		cpu->memory_rw(cpu, cpu->mem, addr, (unsigned char *) (void *) &buf, 4, MEM_READ,
@@ -515,7 +515,7 @@ void maple_do_dma_xfer(struct cpu *cpu, 
 				    d, cpu, port, receive_addr);
 			} else {
 				fatal("[ dreamcast_maple: WARNING: GETCOND: "
-				    "UNIMPLEMENTED 0x%08"PRIx32" ]\n", cond);
+				    "UNIMPLEMENTED 0x%08" PRIx32 " ]\n", cond);
 				exit(1);
 			}
 			break;
@@ -665,4 +665,3 @@ DEVINIT(dreamcast_maple)
 
 	return 1;
 }
-
