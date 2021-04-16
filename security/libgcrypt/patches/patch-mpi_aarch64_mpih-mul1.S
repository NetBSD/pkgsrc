$NetBSD$

--- mpi/aarch64/mpih-mul1.S.orig	2019-11-18 20:25:49.000000000 +0000
+++ mpi/aarch64/mpih-mul1.S
@@ -34,9 +34,9 @@
 
 .text
 
-.globl _gcry_mpih_mul_1
-ELF(.type  _gcry_mpih_mul_1,%function)
-_gcry_mpih_mul_1:
+.globl C_SYMBOL_NAME(_gcry_mpih_mul_1)
+ELF(.type  C_SYMBOL_NAME(_gcry_mpih_mul_1),%function)
+C_SYMBOL_NAME(_gcry_mpih_mul_1):
 	CFI_STARTPROC()
 	and	w5, w2, #3;
 	mov	x4, xzr;
@@ -96,4 +96,4 @@ _gcry_mpih_mul_1:
 	mov	x0, x4;
 	ret;
 	CFI_ENDPROC()
-ELF(.size _gcry_mpih_mul_1,.-_gcry_mpih_mul_1;)
+ELF(.size C_SYMBOL_NAME(_gcry_mpih_mul_1),.-C_SYMBOL_NAME(_gcry_mpih_mul_1);)
