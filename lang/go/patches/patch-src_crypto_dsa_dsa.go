$NetBSD: patch-src_crypto_dsa_dsa.go,v 1.1 2016/04/08 20:00:02 bsiegert Exp $

Fix for CVE-2016-3959:

crypto/dsa: eliminate invalid PublicKey early

For PublicKey.P == 0, Verify will fail. Don't even try.

Change-Id: I1009f2b3dead8d0041626c946633acb10086d8c8
Reviewed-on: https://go-review.googlesource.com/21533
Reviewed-by: Brad Fitzpatrick <bradfitz@golang.org>

--- src/crypto/dsa/dsa.go.orig	2016-02-17 20:35:21.000000000 +0000
+++ src/crypto/dsa/dsa.go
@@ -249,6 +249,10 @@ func Sign(rand io.Reader, priv *PrivateK
 func Verify(pub *PublicKey, hash []byte, r, s *big.Int) bool {
 	// FIPS 186-3, section 4.7
 
+	if pub.P.Sign() == 0 {
+		return false
+	}
+
 	if r.Sign() < 1 || r.Cmp(pub.Q) >= 0 {
 		return false
 	}
