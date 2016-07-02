$NetBSD: patch-cipher_poly1305-armv7-neon.S,v 1.1 2016/07/02 13:24:17 wiz Exp $

Fix ARM Neon assembler problem.
https://lists.gnupg.org/pipermail/gcrypt-devel/2016-June/003904.html

--- cipher/poly1305-armv7-neon.S.orig	2016-03-23 11:59:34.000000000 +0000
+++ cipher/poly1305-armv7-neon.S
@@ -52,7 +52,7 @@ _gcry_poly1305_armv7_neon_init_ext:
 	and r2, r2, r2
 	moveq r14, #-1
 	ldmia r1!, {r2-r5}
-	ldr r7, =.Lpoly1305_init_constants_neon
+	adr r7, .Lpoly1305_init_constants_neon
 	mov r6, r2
 	mov r8, r2, lsr #26
 	mov r9, r3, lsr #20
