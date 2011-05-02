$NetBSD: patch-x86_camellia-crypt-internal.asm,v 1.1 2011/05/02 21:27:15 adam Exp $

Avoid ambiguous instruction.

--- x86/camellia-crypt-internal.asm.orig	2011-05-02 18:31:15.000000000 +0000
+++ x86/camellia-crypt-internal.asm
@@ -185,7 +185,7 @@ PROLOGUE(_nettle_camellia_crypt)
 	FL(L0, H0, -16)
 	FLINV(L1, H1, -8)
 	ROUND6
-	sub 	$8, FRAME_CNT	
+	subl 	$8, FRAME_CNT	
 	ja	.Lround_loop
 
 	movl	FRAME_DST, TMP
