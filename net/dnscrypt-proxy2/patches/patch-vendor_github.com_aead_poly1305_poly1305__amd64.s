$NetBSD: patch-vendor_github.com_aead_poly1305_poly1305__amd64.s,v 1.2 2018/09/30 20:22:20 maya Exp $

Newer Go has deprecated runtime.support_avx2, assume no avx2 support instead

--- vendor/github.com/aead/poly1305/poly1305_amd64.s.orig	2018-07-09 16:19:45.000000000 +0000
+++ vendor/github.com/aead/poly1305/poly1305_amd64.s
@@ -150,6 +150,6 @@ TEXT ·finalize(SB), $0-16
 
 // func supportsAVX2() bool
 TEXT ·supportsAVX2(SB), 4, $0-1
-	MOVQ runtime·support_avx2(SB), AX
+	MOVQ $0X0, AX
 	MOVB AX, ret+0(FP)
 	RET
