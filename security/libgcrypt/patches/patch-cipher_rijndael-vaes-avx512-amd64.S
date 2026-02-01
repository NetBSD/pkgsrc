$NetBSD: patch-cipher_rijndael-vaes-avx512-amd64.S,v 1.1 2026/02/01 08:51:16 wiz Exp $

https://dev.gnupg.org/file/view/35198420/

--- cipher/rijndael-vaes-avx512-amd64.S.orig	2026-01-20 13:36:28.000000000 +0000
+++ cipher/rijndael-vaes-avx512-amd64.S
@@ -277,7 +277,7 @@ _gcry_vaes_avx512_cbc_dec_amd64:
 .Lcbc_dec_skip_avx512:
 	/* Handle trailing blocks with AVX2 implementation. */
 	cmpq $0, %r8;
-	ja _gcry_vaes_avx2_cbc_dec_amd64;
+	ja _gcry_vaes_avx2_cbc_dec_amd64 AT_PLT;
 
 	ret_spec_stop
 	CFI_ENDPROC();
@@ -491,7 +491,7 @@ _gcry_vaes_avx512_cfb_dec_amd64:
 .Lcfb_dec_skip_avx512:
 	/* Handle trailing blocks with AVX2 implementation. */
 	cmpq $0, %r8;
-	ja _gcry_vaes_avx2_cfb_dec_amd64;
+	ja _gcry_vaes_avx2_cfb_dec_amd64 AT_PLT;
 
 	ret_spec_stop
 	CFI_ENDPROC();
@@ -813,7 +813,7 @@ _gcry_vaes_avx512_ctr_enc_amd64:
 .Lctr_enc_skip_avx512:
 	/* Handle trailing blocks with AVX2 implementation. */
 	cmpq $0, %r8;
-	ja _gcry_vaes_avx2_ctr_enc_amd64;
+	ja _gcry_vaes_avx2_ctr_enc_amd64 AT_PLT;
 
 	ret_spec_stop
 	CFI_ENDPROC();
@@ -1037,7 +1037,7 @@ _gcry_vaes_avx512_ctr32le_enc_amd64:
 .Lctr32le_enc_skip_avx512:
 	/* Handle trailing blocks with AVX2 implementation. */
 	cmpq $0, %r8;
-	ja _gcry_vaes_avx2_ctr32le_enc_amd64;
+	ja _gcry_vaes_avx2_ctr32le_enc_amd64 AT_PLT;
 
 	ret_spec_stop
 	CFI_ENDPROC();
@@ -1721,7 +1721,7 @@ _gcry_vaes_avx512_ocb_aligned_crypt_amd64:
 .Locb_skip_avx512:
 	/* Handle trailing blocks with AVX2 implementation. */
 	cmpq $0, %r8;
-	ja _gcry_vaes_avx2_ocb_crypt_amd64;
+	ja _gcry_vaes_avx2_ocb_crypt_amd64 AT_PLT;
 
 	xorl %eax, %eax;
 	ret_spec_stop
@@ -2084,7 +2084,7 @@ _gcry_vaes_avx512_xts_crypt_amd64:
 .Lxts_crypt_skip_avx512:
 	/* Handle trailing blocks with AVX2 implementation. */
 	cmpq $0, %r8;
-	ja _gcry_vaes_avx2_xts_crypt_amd64;
+	ja _gcry_vaes_avx2_xts_crypt_amd64 AT_PLT;
 
 	ret_spec_stop
 	CFI_ENDPROC();
@@ -2347,7 +2347,7 @@ _gcry_vaes_avx512_ecb_crypt_amd64:
 .Lecb_crypt_skip_avx512:
 	/* Handle trailing blocks with AVX2 implementation. */
 	cmpq $0, %r8;
-	ja _gcry_vaes_avx2_ecb_crypt_amd64;
+	ja _gcry_vaes_avx2_ecb_crypt_amd64 AT_PLT;
 
 	ret_spec_stop
 	CFI_ENDPROC();
