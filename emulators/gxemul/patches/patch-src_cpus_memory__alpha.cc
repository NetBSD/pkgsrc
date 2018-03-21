$NetBSD: patch-src_cpus_memory__alpha.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/memory_alpha.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/memory_alpha.cc
@@ -90,7 +90,7 @@ if (vaddr == 0xfffffffd80000000ULL) {
 		return 2;
 	}
 
-	// debug("base = 0x%016"PRIx64"\n", base);
+	// debug("base = 0x%016" PRIx64 "\n", base);
 if (vaddr == 0xfffffffd80000000ULL) fatal("AYONA3\n");
 
 	uint64_t addr, pte1, pte2, pte3;
@@ -116,7 +116,7 @@ if (vaddr == 0xfffffffd80000000ULL) fata
 	pte1 = *(uint64_t *)(pt_entry_ptr);
 	pte1 = LE64_TO_HOST(pte1);
 
-	// debug("pte1 = 0x%016"PRIx64"\n", pte1);
+	// debug("pte1 = 0x%016" PRIx64 "\n", pte1);
 	if (!(pte1 & ALPHA_PTE_VALID)) {
 		// TODO:
 		// IF level1_pte<KRE> EQ 0 THEN
@@ -137,7 +137,7 @@ if (vaddr == 0xfffffffd80000000ULL) fata
 	pte2 = *(uint64_t *)(pt_entry_ptr);
 	pte2 = LE64_TO_HOST(pte2);
 
-	// debug("pte2 = 0x%016"PRIx64"\n", pte2);
+	// debug("pte2 = 0x%016" PRIx64 "\n", pte2);
 	if (!(pte2 & ALPHA_PTE_VALID)) {
 		// TODO:
 		// IF level2_pte<KRE> EQ 0 THEN
@@ -158,7 +158,7 @@ if (vaddr == 0xfffffffd80000000ULL) fata
 	pte3 = *(uint64_t *)(pt_entry_ptr);
 	pte3 = LE64_TO_HOST(pte3);
 
-	// debug("pte3 = 0x%016"PRIx64"\n", pte3);
+	// debug("pte3 = 0x%016" PRIx64 "\n", pte3);
 
 	if (!(pte3 & ALPHA_PTE_VALID)) {
 		fatal("TODO: pte3 not valid.\n");
@@ -172,9 +172,8 @@ if (vaddr == 0xfffffffd80000000ULL) fata
 
 not_found:
 	/*  No match.  */
-	fatal("[ alpha_translate_v2p: 0x%016"PRIx64" wasn't found ]\n", vaddr);
+	fatal("[ alpha_translate_v2p: 0x%016" PRIx64 " wasn't found ]\n", vaddr);
 abort();
 	exit(1);
 	return 0;
 }
-
