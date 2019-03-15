$NetBSD: patch-vendor_golang.org_x_crypto_blake2b_blake2bAVX2__amd64.s,v 1.1 2019/03/15 15:03:03 he Exp $

We get link errors about runtime.support_avx and runtime.support_avx2, so
revert the offending commit from
https://github.com/golang/crypto/commit/b0697eccbea9adec5b7ba8008f4c33d98d733388
I've not been able to track which version of golang.org/x/crypto is
embedded in the beats package, and frankly am befuddled that this sort
of thing makes it into released code, in this day and age with widespread
use of CI etc.  This coupled with the apparent widespread practice of
"vendoring" code (copy a vendor's code and ship it as part of your source
package) makes it difficult to stamp out this sort of bugs.  Sigh!

--- vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.s.orig	2019-03-06 10:13:10.000000000 +0000
+++ vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.s
@@ -748,15 +748,3 @@ noinc:
 
 	MOVQ BP, SP
 	RET
-
-// func supportsAVX2() bool
-TEXT ·supportsAVX2(SB), 4, $0-1
-	MOVQ runtime·support_avx2(SB), AX
-	MOVB AX, ret+0(FP)
-	RET
-
-// func supportsAVX() bool
-TEXT ·supportsAVX(SB), 4, $0-1
-	MOVQ runtime·support_avx(SB), AX
-	MOVB AX, ret+0(FP)
-	RET
