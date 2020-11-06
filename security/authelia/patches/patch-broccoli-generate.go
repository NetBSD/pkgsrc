$NetBSD: patch-broccoli-generate.go,v 1.1 2020/11/06 18:07:54 tnn Exp $

Hangs on NetBSD/aarch64 for unknown reasons. Bug in go toolchain?

--- ../broccoli-1.0.3/generate.go.orig	2020-04-20 19:39:06.000000000 +0000
+++ ../broccoli-1.0.3/generate.go
@@ -239,7 +239,7 @@ func (g *Generator) parsePackage() {
 	g.pkg.dir = "."
 
 	// Type check the package.
-	g.pkg.check(set, astFiles)
+	// g.pkg.check(set, astFiles)
 }
 
 // check type-checks the package.
