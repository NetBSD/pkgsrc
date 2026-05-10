$NetBSD: patch-target_m68k_helper.c,v 1.1 2026/05/10 04:12:37 thorpej Exp $

Ensure that m68k TLB fills for read accesses do not include write
permission if the MODIFIED bit is not set in the PTE.  Without this,
a page that is referenced before being modified may end up not being
marked as MODIFIED, which can lead to all sorts of problems if the
operating system decides it needs to start swapping due to memory
pressure.

--- target/m68k/helper.c.orig	2026-05-09 22:41:53.289781118 +0000
+++ target/m68k/helper.c	2026-05-10 00:02:06.795840537 +0000
@@ -755,7 +755,7 @@ static int get_physical_address(CPUM68KS
     }
 
     /* Page Table Root Pointer */
-    *prot = PAGE_READ | PAGE_WRITE;
+    *prot = PAGE_READ;
     if (access_type & ACCESS_CODE) {
         *prot |= PAGE_EXEC;
     }
@@ -786,7 +786,6 @@ static int get_physical_address(CPUM68KS
         if (access_type & ACCESS_PTEST) {
             env->mmu.mmusr |= M68K_MMU_WP_040;
         }
-        *prot &= ~PAGE_WRITE;
         if (access_type & ACCESS_STORE) {
             return -1;
         }
@@ -813,7 +812,6 @@ static int get_physical_address(CPUM68KS
         if (access_type & ACCESS_PTEST) {
             env->mmu.mmusr |= M68K_MMU_WP_040;
         }
-        *prot &= ~PAGE_WRITE;
         if (access_type & ACCESS_STORE) {
             return -1;
         }
@@ -884,16 +882,18 @@ static int get_physical_address(CPUM68KS
         env->mmu.mmusr |= M68K_MMU_R_040;
     }
 
-    if (next & M68K_DESC_WRITEPROT) {
-        *prot &= ~PAGE_WRITE;
-        if (access_type & ACCESS_STORE) {
+    if (next & M68K_DESC_SUPERONLY) {
+        if ((access_type & ACCESS_SUPER) == 0) {
             return -1;
         }
     }
-    if (next & M68K_DESC_SUPERONLY) {
-        if ((access_type & ACCESS_SUPER) == 0) {
+
+    if (next & M68K_DESC_WRITEPROT) {
+        if (access_type & ACCESS_STORE) {
             return -1;
         }
+    } else if (next & M68K_DESC_MODIFIED) {
+        *prot |= PAGE_WRITE;
     }
 
     return 0;
