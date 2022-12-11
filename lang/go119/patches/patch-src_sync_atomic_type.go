# $NetBSD: patch-src_sync_atomic_type.go,v 1.1 2022/12/11 23:11:31 nikita Exp $
fix a regression in 1.19.4, to be included in 1.19.5

From df5d4d3daab7e022335c0f3304d7b750bdd731a0 Mon Sep 17 00:00:00 2001
From: Russ Cox <rsc@golang.org>
Date: Tue, 15 Nov 2022 09:54:39 -0500
Subject: [PATCH] [release-branch.go1.19] sync/atomic: allow linked list of atomic pointers again

For #56603, CL 448275 added a _ [0]T field to atomic.Pointer,
so that different kinds of atomic.Pointer are not convertible.

Unfortunately, that breaks code like:

	type List struct {
		Next atomic.Pointer[List]
	}

which should be valid, just as using Next *List is valid.
Instead, we get:

	./atomic_test.go:2533:6: invalid recursive type List
		./atomic_test.go:2533:6: List refers to
		./atomic_test.go:2534:13: "sync/atomic".Pointer refers to
		./atomic_test.go:2533:6: List

Fix by using _[0]*T instead.

For #56638.
Fixes #57124.

Change-Id: Icc4c83c691d35961d20cb14b824223d6c779ac5e
Reviewed-on: https://go-review.googlesource.com/c/go/+/450655
Run-TryBot: Russ Cox <rsc@golang.org>
TryBot-Result: Gopher Robot <gobot@golang.org>
Reviewed-by: Michael Knyszek <mknyszek@google.com>
(cherry picked from commit b14cf3d93ae5c477dd35f13f6ba41044f01a7f7d)
Reviewed-on: https://go-review.googlesource.com/c/go/+/452438
Reviewed-by: Cherry Mui <cherryyz@google.com>
Run-TryBot: Michael Pratt <mpratt@google.com>
Reviewed-by: Michael Pratt <mpratt@google.com>
---

diff --git a/src/sync/atomic/atomic_test.go b/src/sync/atomic/atomic_test.go
index 02d55fb..3ab5e83 100644
--- src/sync/atomic/atomic_test.go.orig
+++ src/sync/atomic/atomic_test.go
@@ -2605,3 +2605,9 @@
 		}()
 	}
 }
+
+// Test that this compiles.
+// When atomic.Pointer used _ [0]T, it did not.
+type List struct {
+	Next Pointer[List]
+}
diff --git a/src/sync/atomic/type.go b/src/sync/atomic/type.go
index 2d1e621..93058ca 100644
--- src/sync/atomic/type.go.orig
+++ src/sync/atomic/type.go
@@ -37,9 +37,10 @@
 
 // A Pointer is an atomic pointer of type *T. The zero value is a nil *T.
 type Pointer[T any] struct {
-	// Mention T in a field to disallow conversion between Pointer types.
+	// Mention *T in a field to disallow conversion between Pointer types.
 	// See go.dev/issue/56603 for more details.
-	_ [0]T
+	// Use *T, not T, to avoid spurious recursive type definition errors.
+	_ [0]*T
 
 	_ noCopy
 	v unsafe.Pointer
