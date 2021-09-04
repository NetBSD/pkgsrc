$NetBSD: patch-vendor_golang.org_x_crypto_blake2b_blake2bAVX2__amd64.go,v 1.2 2021/09/04 14:10:33 bsiegert Exp $

We get link errors about runtime.support_avx and runtime.support_avx2, so
revert the offending commit from
https://github.com/golang/crypto/commit/b0697eccbea9adec5b7ba8008f4c33d98d733388
I've not been able to track which version of golang.org/x/crypto is
embedded in the beats package, and frankly am befuddled that this sort
of thing makes it into released code, in this day and age with widespread
use of CI etc.  This coupled with the apparent widespread practice of
"vendoring" code (copy a vendor's code and ship it as part of your source
package) makes it difficult to stamp out this sort of bugs.  Sigh!

--- vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.go.orig	2019-03-06 10:13:10.000000000 +0000
+++ vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.go
@@ -6,20 +6,22 @@
 
 package blake2b
 
-func init() {
-	useAVX2 = supportsAVX2()
-	useAVX = supportsAVX()
-	useSSE4 = supportsSSE4()
-}
+import _ "unsafe"
 
-//go:noescape
-func supportsSSE4() bool
+//go:linkname x86_HasAVX internal/cpu.X86.HasAVX
+var x86_HasAVX bool
 
-//go:noescape
-func supportsAVX() bool
+//go:linkname x86_HasAVX2 internal/cpu.X86.HasAVX2
+var x86_HasAVX2 bool
 
-//go:noescape
-func supportsAVX2() bool
+//go:linkname x86_HasSSE4 internal/cpu.X86.HasSSE4
+var x86_HasSSE4 bool
+
+func init() {
+	useAVX2 = x86_HasAVX2
+	useAVX = x86_HasAVX
+	useSSE4 = x86_HasSSE4
+}
 
 //go:noescape
 func hashBlocksAVX2(h *[8]uint64, c *[2]uint64, flag uint64, blocks []byte)
