$NetBSD$

--- mpi/aarch64/mpih-sub1.S.orig	2019-11-18 20:25:49.000000000 +0000
+++ mpi/aarch64/mpih-sub1.S
@@ -34,9 +34,9 @@
 
 .text
 
-.globl _gcry_mpih_sub_n
-ELF(.type  _gcry_mpih_sub_n,%function)
-_gcry_mpih_sub_n:
+.globl C_SYMBOL_NAME(_gcry_mpih_sub_n)
+ELF(.type  C_SYMBOL_NAME(_gcry_mpih_sub_n),%function)
+C_SYMBOL_NAME(_gcry_mpih_sub_n):
 	CFI_STARTPROC()
 	and	w5, w3, #3;
 	subs	xzr, xzr, xzr; /* prepare carry flag for sub */
@@ -71,4 +71,4 @@ _gcry_mpih_sub_n:
 	cset	x0, cc;
 	ret;
 	CFI_ENDPROC()
-ELF(.size _gcry_mpih_sub_n,.-_gcry_mpih_sub_n;)
+ELF(.size C_SYMBOL_NAME(_gcry_mpih_sub_n),.-C_SYMBOL_NAME(_gcry_mpih_sub_n);)
