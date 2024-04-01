$NetBSD: patch-gmp_mpn_generic_compute_powtab.c,v 1.1 2024/04/01 14:33:57 js Exp $

Fix compiling with GCC 4.4.2 on QNX.

--- gmp/mpn/generic/compute_powtab.c.orig	2023-07-29 13:42:16.000000000 +0000
+++ gmp/mpn/generic/compute_powtab.c
@@ -70,6 +70,7 @@ mpn_compute_powtab_mul (powers_t *powtab
   mp_limb_t cy;
   long start_idx;
   int c;
+  long pi;
 
   mp_limb_t big_base = mp_bases[base].big_base;
   int chars_per_limb = mp_bases[base].chars_per_limb;
@@ -139,7 +140,7 @@ mpn_compute_powtab_mul (powers_t *powtab
       start_idx = n_pows - 3;
     }
 
-  for (long pi = start_idx; pi >= 0; pi--)
+  for (pi = start_idx; pi >= 0; pi--)
     {
       t = powtab_mem_ptr;
       powtab_mem_ptr += 2 * n + 2;
@@ -223,7 +224,8 @@ mpn_compute_powtab_div (powers_t *powtab
 
   mp_size_t n = 1;
   mp_size_t shift = 0;
-  for (long pi = n_pows - 1; pi >= 0; pi--)
+  long pi;
+  for (pi = n_pows - 1; pi >= 0; pi--)
     {
       t = powtab_mem_ptr;
       powtab_mem_ptr += 2 * n;
@@ -271,7 +273,7 @@ mpn_compute_powtab_div (powers_t *powtab
 
   /* Strip any remaining low zero limbs.  */
   pt -= n_pows + 1;
-  for (long pi = n_pows; pi >= 0; pi--)
+  for (pi = n_pows; pi >= 0; pi--)
     {
       mp_ptr t = pt[pi].p;
       mp_size_t shift = pt[pi].shift;
@@ -293,7 +295,8 @@ powtab_decide (size_t *exptab, size_t un
 {
   int chars_per_limb = mp_bases[base].chars_per_limb;
   long n_pows = 0;
-  for (size_t pn = (un + 1) >> 1; pn != 1; pn = (pn + 1) >> 1)
+  size_t pn;
+  for (pn = (un + 1) >> 1; pn != 1; pn = (pn + 1) >> 1)
     {
       exptab[n_pows] = pn * chars_per_limb;
       n_pows++;
@@ -301,11 +304,12 @@ powtab_decide (size_t *exptab, size_t un
   exptab[n_pows] = chars_per_limb;
 
 #if HAVE_mpn_compute_powtab_mul && HAVE_mpn_compute_powtab_div
-  size_t pn = un - 1;
+  pn = un - 1;
   size_t xn = (un + 1) >> 1;
   unsigned mcost = 1;
   unsigned dcost = 1;
-  for (long i = n_pows - 2; i >= 0; i--)
+  long i;
+  for (i = n_pows - 2; i >= 0; i--)
     {
       size_t pow = (pn >> (i + 1)) + 1;
 
