$NetBSD$

--- mpi/aarch64/mpih-mul2.S.orig	2019-11-18 20:25:49.000000000 +0000
+++ mpi/aarch64/mpih-mul2.S
@@ -34,9 +34,9 @@
 
 .text
 
-.globl _gcry_mpih_addmul_1
-ELF(.type  _gcry_mpih_addmul_1,%function)
-_gcry_mpih_addmul_1:
+.globl C_SYMBOL_NAME(_gcry_mpih_addmul_1)
+ELF(.type  C_SYMBOL_NAME(_gcry_mpih_addmul_1),%function)
+C_SYMBOL_NAME(_gcry_mpih_addmul_1):
 	CFI_STARTPROC()
 	and	w5, w2, #3;
 	mov	x6, xzr;
@@ -108,4 +108,4 @@ _gcry_mpih_addmul_1:
 	mov	x0, x6;
 	ret;
 	CFI_ENDPROC()
-ELF(.size _gcry_mpih_addmul_1,.-_gcry_mpih_addmul_1;)
+ELF(.size C_SYMBOL_NAME(_gcry_mpih_addmul_1),.-C_SYMBOL_NAME(_gcry_mpih_addmul_1);)
