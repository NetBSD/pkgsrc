$NetBSD: patch-src_file_file__elf.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/file/file_elf.cc.orig	2014-08-17 08:45:10.000000000 +0000
+++ src/file/file_elf.cc
@@ -326,9 +326,9 @@ static void file_load_elf(struct machine
 	    encoding == ELFDATA2LSB? "LSB (LE)" : "MSB (BE)", s);
 
 	if (elf64)
-		debug("%016"PRIx64"\n", (uint64_t) eentry);
+		debug("%016" PRIx64 "\n", (uint64_t) eentry);
 	else
-		debug("%08"PRIx32"\n", (uint32_t) eentry);
+		debug("%08" PRIx32 "\n", (uint32_t) eentry);
 
 	/*
 	 *  SH64: 32-bit instruction encoding?
@@ -400,34 +400,34 @@ static void file_load_elf(struct machine
 			if (p_type == PT_LOAD)
 				debug("load");
 			else
-				debug("0x%08"PRIx32, (uint32_t) p_type);
+				debug("0x%08" PRIx32, (uint32_t) p_type);
 
-			debug(") @ 0x%"PRIx64", vaddr 0x", (uint64_t) p_offset);
+			debug(") @ 0x%" PRIx64 ", vaddr 0x", (uint64_t) p_offset);
 
 			if (elf64)
-				debug("%016"PRIx64, (uint64_t) p_vaddr);
+				debug("%016" PRIx64, (uint64_t) p_vaddr);
 			else
-				debug("%08"PRIx32, (uint32_t) p_vaddr);
+				debug("%08" PRIx32, (uint32_t) p_vaddr);
 
-			debug(" len=0x%"PRIx64"\n", (uint64_t) p_memsz);
+			debug(" len=0x%" PRIx64 "\n", (uint64_t) p_memsz);
 
 			if (p_vaddr != p_paddr) {
 				if (elf64)
-					debug("NOTE: vaddr (0x%"PRIx64") and "
-					    "paddr (0x%"PRIx64") differ; using "
+					debug("NOTE: vaddr (0x%" PRIx64 ") and "
+					    "paddr (0x%" PRIx64 ") differ; using "
 					    "vaddr\n", (uint64_t) p_vaddr,
 					    (uint64_t) p_paddr);
 				else
-					debug("NOTE: vaddr (0x%08"PRIx32") and "
-					    "paddr (0x%08"PRIx32") differ; usin"
+					debug("NOTE: vaddr (0x%08" PRIx32 ") and "
+					    "paddr (0x%08" PRIx32 ") differ; usin"
 					    "g vaddr\n", (uint32_t) p_vaddr,
 					    (uint32_t)p_paddr);
 			}
 
 			if (p_memsz < p_filesz) {
 				fprintf(stderr, "%s: memsz < filesz. TODO: how"
-				    " to handle this? memsz=%016"PRIx64
-				    " filesz=%016"PRIx64"\n", filename,
+				    " to handle this? memsz=%016" PRIx64
+				    " filesz=%016" PRIx64 "\n", filename,
 				    (uint64_t) p_memsz, (uint64_t) p_filesz);
 				exit(1);
 			}
@@ -493,7 +493,7 @@ static void file_load_elf(struct machine
 		off_t sh_offset;
 		int n_entries;	/*  for reading the symbol / string tables  */
 
-		/*  debug("section header %i at %016"PRIx64"\n", i,
+		/*  debug("section header %i at %016" PRIx64 "\n", i,
 		    (uint64_t) eshoff+i*eshentsize);  */
 
 		fseek(f, eshoff + i * eshentsize, SEEK_SET);
@@ -576,7 +576,7 @@ static void file_load_elf(struct machine
 				exit(1);
 			}
 
-			debug("%i symbol entries at 0x%"PRIx64"\n",
+			debug("%i symbol entries at 0x%" PRIx64 "\n",
 			    (int) n_entries, (uint64_t) sh_offset);
 
 			n_symbols = n_entries;
@@ -604,7 +604,7 @@ static void file_load_elf(struct machine
 				exit(1);
 			}
 
-			debug("%i bytes of symbol strings at 0x%"PRIx64"\n",
+			debug("%i bytes of symbol strings at 0x%" PRIx64 "\n",
 			    (int) sh_size, (uint64_t) sh_offset);
 
 			symbol_strings[sh_size] = '\0';
@@ -654,9 +654,9 @@ static void file_load_elf(struct machine
 			if (strcmp(symbol_strings + st_name, "_gp") == 0) {
 				debug("found _gp address: 0x");
 				if (elf64)
-					debug("%016"PRIx64"\n", (uint64_t)addr);
+					debug("%016" PRIx64 "\n", (uint64_t)addr);
 				else
-					debug("%08"PRIx32"\n", (uint32_t)addr);
+					debug("%08" PRIx32 "\n", (uint32_t)addr);
 				*gpp = addr;
 			}
 		}
@@ -709,7 +709,7 @@ static void file_load_elf(struct machine
 		    ((uint64_t)b[5] << 16) + ((uint64_t)b[6] << 8) +
 		    (uint64_t)b[7];
 
-		debug("entrypoint 0x%016"PRIx64", toc_base 0x%016"PRIx64"\n",
+		debug("entrypoint 0x%016" PRIx64 ", toc_base 0x%016" PRIx64 "\n",
 		    (uint64_t) *entrypointp, (uint64_t) toc_base);
 		if (tocp != NULL)
 			*tocp = toc_base;
@@ -717,4 +717,3 @@ static void file_load_elf(struct machine
 
 	n_executables_loaded ++;
 }
-
