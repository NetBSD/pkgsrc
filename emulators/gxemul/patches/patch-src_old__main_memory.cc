$NetBSD: patch-src_old__main_memory.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/old_main/memory.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/old_main/memory.cc
@@ -378,13 +378,13 @@ void memory_device_register(struct memor
 
 	if (verbose >= 2) {
 		/*  (40 bits of physical address is displayed)  */
-		debug("device at 0x%010"PRIx64": %s", (uint64_t) baseaddr,
+		debug("device at 0x%010" PRIx64 ": %s", (uint64_t) baseaddr,
 		    device_name);
 
 		if (flags & (DM_DYNTRANS_OK | DM_DYNTRANS_WRITE_OK)
 		    && (baseaddr & mem->dev_dyntrans_alignment) != 0) {
 			fatal("\nWARNING: Device dyntrans access, but unaligned"
-			    " baseaddr 0x%"PRIx64".\n", (uint64_t) baseaddr);
+			    " baseaddr 0x%" PRIx64 ".\n", (uint64_t) baseaddr);
 		}
 
 		if (flags & (DM_DYNTRANS_OK | DM_DYNTRANS_WRITE_OK)) {
@@ -627,11 +627,11 @@ void memory_warn_about_unimplemented_add
 		debug("} ");
 	}
 
-	fatal("paddr=0x%"PRIx64" >= physical_max; pc=", paddr);
+	fatal("paddr=0x%" PRIx64 " >= physical_max; pc=", paddr);
 	if (cpu->is_32bit)
-		fatal("0x%08"PRIx32, (uint32_t) old_pc);
+		fatal("0x%08" PRIx32, (uint32_t) old_pc);
 	else
-		fatal("0x%016"PRIx64, (uint64_t) old_pc);
+		fatal("0x%016" PRIx64, (uint64_t) old_pc);
 	symbol = get_symbol_name(&cpu->machine->symbol_context,
 	    old_pc, &offset);
 	fatal(" <%s> ]\n", symbol? symbol : " no symbol ");
@@ -998,4 +998,3 @@ void store_16bit_word_in_host(struct cpu
 		int tmp = data[0]; data[0] = data[1]; data[1] = tmp;
 	}
 }
-
