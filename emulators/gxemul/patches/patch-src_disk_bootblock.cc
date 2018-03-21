$NetBSD: patch-src_disk_bootblock.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/disk/bootblock.cc.orig	2014-08-17 08:45:14.000000000 +0000
+++ src/disk/bootblock.cc
@@ -177,7 +177,7 @@ int load_bootblock(struct machine *m, st
 		/*  Convert loadaddr to uncached:  */
 		if ((bootblock_loadaddr & 0xf0000000ULL) != 0x80000000 &&
 		    (bootblock_loadaddr & 0xf0000000ULL) != 0xa0000000) {
-			fatal("\nWARNING! Weird load address 0x%08"PRIx32
+			fatal("\nWARNING! Weird load address 0x%08" PRIx32
 			    " for SCSI id %i.\n\n",
 			    (uint32_t)bootblock_loadaddr, boot_disk_id);
 			if (bootblock_loadaddr == 0) {
@@ -198,7 +198,7 @@ int load_bootblock(struct machine *m, st
 		bootblock_pc |= 0xffffffffa0000000ULL;
 		cpu->pc = bootblock_pc;
 
-		debug("DEC boot: loadaddr=0x%08"PRIx32", pc=0x%08"PRIx32,
+		debug("DEC boot: loadaddr=0x%08" PRIx32 ", pc=0x%08" PRIx32,
 		    (uint32_t) bootblock_loadaddr, (uint32_t) bootblock_pc);
 
 		readofs = 0x18;
@@ -311,5 +311,3 @@ ret_ok:
 	free(bootblock_buf);
 	return retval;
 }
-
-
