$NetBSD: patch-src_math_big_nat_test.go,v 1.1 2015/12/22 20:44:40 bsiegert Exp $

From 4306352182bf94f86f0cfc6a8b0ed461cbf1d82c Mon Sep 17 00:00:00 2001
From: Russ Cox <rsc@golang.org>
Date: Wed, 09 Dec 2015 11:49:53 -0500
Subject: [PATCH] math/big: fix carry propagation in Int.Exp Montgomery code

Fixes #13515.

Change-Id: I7dd5fbc816e5ea135f7d81f6735e7601f636fe4f
Reviewed-on: https://go-review.googlesource.com/17672
Reviewed-by: Robert Griesemer <gri@golang.org>
---

diff --git a/src/math/big/nat_test.go b/src/math/big/nat_test.go
index 3eefffc..56b62d2 100644
--- src/math/big/nat_test.go.orig	2015-12-03 00:53:01.000000000 +0000
+++ src/math/big/nat_test.go
@@ -341,25 +341,57 @@ var montgomeryTests = []struct {
 		"0xffffffffffffffffffffffffffffffffffffffffffffffffe",
 		"0xffffffffffffffffffffffffffffffffffffffffffffffffe",
 		"0xfffffffffffffffffffffffffffffffffffffffffffffffff",
-		0x0000000000000000,
-		"0xffffffffffffffffffffffffffffffffffffffffff",
-		"0xffffffffffffffffffffffffffffffffff",
+		1,
+		"0x1000000000000000000000000000000000000000000",
+		"0x10000000000000000000000000000000000",
 	},
 	{
-		"0x0000000080000000",
-		"0x00000000ffffffff",
+		"0x000000000ffffff5",
+		"0x000000000ffffff0",
 		"0x0000000010000001",
 		0xff0000000fffffff,
-		"0x0000000088000000",
-		"0x0000000007800001",
+		"0x000000000bfffff4",
+		"0x0000000003400001",
+	},
+	{
+		"0x0000000080000000",
+		"0x00000000ffffffff",
+		"0x1000000000000001",
+		0xfffffffffffffff,
+		"0x0800000008000001",
+		"0x0800000008000001",
+	},
+	{
+		"0x0000000080000000",
+		"0x0000000080000000",
+		"0xffffffff00000001",
+		0xfffffffeffffffff,
+		"0xbfffffff40000001",
+		"0xbfffffff40000001",
+	},
+	{
+		"0x0000000080000000",
+		"0x0000000080000000",
+		"0x00ffffff00000001",
+		0xfffffeffffffff,
+		"0xbfffff40000001",
+		"0xbfffff40000001",
 	},
 	{
-		"0xffffffffffffffffffffffffffffffff00000000000022222223333333333444444444",
-		"0xffffffffffffffffffffffffffffffff999999999999999aaabbbbbbbbcccccccccccc",
+		"0x0000000080000000",
+		"0x0000000080000000",
+		"0x0000ffff00000001",
+		0xfffeffffffff,
+		"0xbfff40000001",
+		"0xbfff40000001",
+	},
+	{
+		"0x3321ffffffffffffffffffffffffffff00000000000022222623333333332bbbb888c0",
+		"0x3321ffffffffffffffffffffffffffff00000000000022222623333333332bbbb888c0",
 		"0x33377fffffffffffffffffffffffffffffffffffffffffffff0000000000022222eee1",
 		0xdecc8f1249812adf,
-		"0x22bb05b6d95eaaeca2bb7c05e51f807bce9064b5fbad177161695e4558f9474e91cd79",
-		"0x14beb58d230f85b6d95eaaeca2bb7c05e51f807bce9064b5fb45669afa695f228e48cd",
+		"0x04eb0e11d72329dc0915f86784820fc403275bf2f6620a20e0dd344c5cd0875e50deb5",
+		"0x0d7144739a7d8e11d72329dc0915f86784820fc403275bf2f61ed96f35dd34dbb3d6a0",
 	},
 	{
 		"0x10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000ffffffffffffffffffffffffffffffff00000000000022222223333333333444444444",
@@ -372,10 +404,27 @@ var montgomeryTests = []struct {
 }
 
 func TestMontgomery(t *testing.T) {
+	one := NewInt(1)
+	_B := new(Int).Lsh(one, _W)
 	for i, test := range montgomeryTests {
 		x := natFromString(test.x)
 		y := natFromString(test.y)
 		m := natFromString(test.m)
+		for len(x) < len(m) {
+			x = append(x, 0)
+		}
+		for len(y) < len(m) {
+			y = append(y, 0)
+		}
+
+		if x.cmp(m) > 0 {
+			_, r := nat(nil).div(nil, x, m)
+			t.Errorf("#%d: x > m (%s > %s; use %s)", i, x.decimalString(), m.decimalString(), r.decimalString())
+		}
+		if y.cmp(m) > 0 {
+			_, r := nat(nil).div(nil, x, m)
+			t.Errorf("#%d: y > m (%s > %s; use %s)", i, y.decimalString(), m.decimalString(), r.decimalString())
+		}
 
 		var out nat
 		if _W == 32 {
@@ -384,7 +433,27 @@ func TestMontgomery(t *testing.T) {
 			out = natFromString(test.out64)
 		}
 
-		k0 := Word(test.k0 & _M) // mask k0 to ensure that it fits for 32-bit systems.
+		// t.Logf("#%d: len=%d\n", i, len(m))
+
+		// check output in table
+		xi := &Int{abs: x}
+		yi := &Int{abs: y}
+		mi := &Int{abs: m}
+		p := new(Int).Mod(new(Int).Mul(xi, new(Int).Mul(yi, new(Int).ModInverse(new(Int).Lsh(one, uint(len(m))*_W), mi))), mi)
+		if out.cmp(p.abs.norm()) != 0 {
+			t.Errorf("#%d: out in table=%s, computed=%s", i, out.decimalString(), p.abs.norm().decimalString())
+		}
+
+		// check k0 in table
+		k := new(Int).Mod(&Int{abs: m}, _B)
+		k = new(Int).Sub(_B, k)
+		k = new(Int).Mod(k, _B)
+		k0 := Word(new(Int).ModInverse(k, _B).Uint64())
+		if k0 != Word(test.k0) {
+			t.Errorf("#%d: k0 in table=%#x, computed=%#x\n", i, test.k0, k0)
+		}
+
+		// check montgomery with correct k0 produces correct output
 		z := nat(nil).montgomery(x, y, m, k0, len(m))
 		z = z.norm()
 		if z.cmp(out) != 0 {
