$NetBSD: patch-target_m68k_helper.c,v 1.2 2026/06/13 17:29:01 thorpej Exp $

Ensure that m68k TLB fills for read accesses do not include write
permission if the MODIFIED bit is not set in the PTE.  Without this,
a page that is referenced before being modified may end up not being
marked as MODIFIED, which can lead to all sorts of problems if the
operating system decides it needs to start swapping due to memory
pressure.

--- target/m68k/helper.c.orig	2026-05-27 16:39:40.000000000 +0000
+++ target/m68k/helper.c	2026-06-13 16:51:29.222776471 +0000
@@ -736,6 +736,8 @@ static int get_physical_address(CPUM68KS
     uint32_t next;
     target_ulong page_mask;
     bool debug = access_type & ACCESS_DEBUG;
+    bool writeprot = false;
+    uint32_t ptest_sr;
     int page_bits;
     int i;
     MemTxResult txres;
@@ -755,7 +757,7 @@ static int get_physical_address(CPUM68KS
     }
 
     /* Page Table Root Pointer */
-    *prot = PAGE_READ | PAGE_WRITE;
+    *prot = PAGE_READ;
     if (access_type & ACCESS_CODE) {
         *prot |= PAGE_EXEC;
     }
@@ -786,7 +788,7 @@ static int get_physical_address(CPUM68KS
         if (access_type & ACCESS_PTEST) {
             env->mmu.mmusr |= M68K_MMU_WP_040;
         }
-        *prot &= ~PAGE_WRITE;
+	writeprot = true;
         if (access_type & ACCESS_STORE) {
             return -1;
         }
@@ -813,7 +815,7 @@ static int get_physical_address(CPUM68KS
         if (access_type & ACCESS_PTEST) {
             env->mmu.mmusr |= M68K_MMU_WP_040;
         }
-        *prot &= ~PAGE_WRITE;
+	writeprot = true;
         if (access_type & ACCESS_STORE) {
             return -1;
         }
@@ -841,10 +843,12 @@ static int get_physical_address(CPUM68KS
             goto txfail;
         }
     }
+    ptest_sr = next & M68K_MMU_SR_MASK_040;
     if (access_type & ACCESS_STORE) {
         if (next & M68K_DESC_WRITEPROT) {
             if (!(next & M68K_DESC_USED) && !debug) {
-                address_space_stl(cs->as, entry, next | M68K_DESC_USED,
+		next |= M68K_DESC_USED;
+		address_space_stl(cs->as, entry, next,
                                   MEMTXATTRS_UNSPECIFIED, &txres);
                 if (txres != MEMTX_OK) {
                     goto txfail;
@@ -852,8 +856,8 @@ static int get_physical_address(CPUM68KS
             }
         } else if ((next & (M68K_DESC_MODIFIED | M68K_DESC_USED)) !=
                            (M68K_DESC_MODIFIED | M68K_DESC_USED) && !debug) {
-            address_space_stl(cs->as, entry,
-                              next | (M68K_DESC_MODIFIED | M68K_DESC_USED),
+	    next |= M68K_DESC_MODIFIED | M68K_DESC_USED;
+	    address_space_stl(cs->as, entry, next,
                               MEMTXATTRS_UNSPECIFIED, &txres);
             if (txres != MEMTX_OK) {
                 goto txfail;
@@ -861,7 +865,8 @@ static int get_physical_address(CPUM68KS
         }
     } else {
         if (!(next & M68K_DESC_USED) && !debug) {
-            address_space_stl(cs->as, entry, next | M68K_DESC_USED,
+	    next |= M68K_DESC_USED;
+            address_space_stl(cs->as, entry, next,
                               MEMTXATTRS_UNSPECIFIED, &txres);
             if (txres != MEMTX_OK) {
                 goto txfail;
@@ -879,23 +884,28 @@ static int get_physical_address(CPUM68KS
     *physical = (next & page_mask) + (address & (*page_size - 1));
 
     if (access_type & ACCESS_PTEST) {
-        env->mmu.mmusr |= next & M68K_MMU_SR_MASK_040;
+	env->mmu.mmusr |= ptest_sr;
         env->mmu.mmusr |= *physical & 0xfffff000;
         env->mmu.mmusr |= M68K_MMU_R_040;
     }
 
     if (next & M68K_DESC_WRITEPROT) {
-        *prot &= ~PAGE_WRITE;
+	writeprot = true;
         if (access_type & ACCESS_STORE) {
             return -1;
         }
     }
+
     if (next & M68K_DESC_SUPERONLY) {
         if ((access_type & ACCESS_SUPER) == 0) {
             return -1;
         }
     }
 
+    if (!writeprot && (next & M68K_DESC_MODIFIED)) {
+        *prot |= PAGE_WRITE;
+    }
+
     return 0;
 
 txfail:
