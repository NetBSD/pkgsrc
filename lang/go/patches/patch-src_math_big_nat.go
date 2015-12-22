$NetBSD: patch-src_math_big_nat.go,v 1.1 2015/12/22 20:44:40 bsiegert Exp $

From 4306352182bf94f86f0cfc6a8b0ed461cbf1d82c Mon Sep 17 00:00:00 2001
From: Russ Cox <rsc@golang.org>
Date: Wed, 09 Dec 2015 11:49:53 -0500
Subject: [PATCH] math/big: fix carry propagation in Int.Exp Montgomery code

Fixes #13515.

Change-Id: I7dd5fbc816e5ea135f7d81f6735e7601f636fe4f
Reviewed-on: https://go-review.googlesource.com/17672
Reviewed-by: Robert Griesemer <gri@golang.org>
---

diff --git a/src/math/big/nat.go b/src/math/big/nat.go
index f0a8339..e60318d 100644
--- src/math/big/nat.go
+++ src/math/big/nat.go
@@ -196,23 +196,36 @@
 	}
 }
 
-// montgomery computes x*y*2^(-n*_W) mod m,
-// assuming k = -1/m mod 2^_W.
+// montgomery computes z mod m = x*y*2**(-n*_W) mod m,
+// assuming k = -1/m mod 2**_W.
 // z is used for storing the result which is returned;
 // z must not alias x, y or m.
+// See Gueron, "Efficient Software Implementations of Modular Exponentiation".
+// https://eprint.iacr.org/2011/239.pdf
+// In the terminology of that paper, this is an "Almost Montgomery Multiplication":
+// x and y are required to satisfy 0 <= z < 2**(n*_W) and then the result
+// z is guaranteed to satisfy 0 <= z < 2**(n*_W), but it may not be < m.
 func (z nat) montgomery(x, y, m nat, k Word, n int) nat {
-	var c1, c2 Word
+	// This code assumes x, y, m are all the same length, n.
+	// (required by addMulVVW and the for loop).
+	// It also assumes that x, y are already reduced mod m,
+	// or else the result will not be properly reduced.
+	if len(x) != n || len(y) != n || len(m) != n {
+		panic("math/big: mismatched montgomery number lengths")
+	}
+	var c1, c2, c3 Word
 	z = z.make(n)
 	z.clear()
 	for i := 0; i < n; i++ {
 		d := y[i]
-		c1 += addMulVVW(z, x, d)
+		c2 = addMulVVW(z, x, d)
 		t := z[0] * k
-		c2 = addMulVVW(z, m, t)
-
+		c3 = addMulVVW(z, m, t)
 		copy(z, z[1:])
-		z[n-1] = c1 + c2
-		if z[n-1] < c1 {
+		cx := c1 + c2
+		cy := cx + c3
+		z[n-1] = cy
+		if cx < c2 || cy < c3 {
 			c1 = 1
 		} else {
 			c1 = 0
