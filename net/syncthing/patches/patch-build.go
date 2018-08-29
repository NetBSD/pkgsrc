$NetBSD: patch-build.go,v 1.1 2018/08/29 13:27:40 tnn Exp $

Without this I get:

open /usr/pkg/go/pkg/netbsd_amd64/runtime/cgo.a: permission denied

when building as non-root.

--- build.go.orig	2018-07-10 15:40:06.000000000 +0000
+++ build.go
@@ -440,7 +440,7 @@ func build(target target, tags []string)
 
 	rmr(target.BinaryName())
 
-	args := []string{"build", "-i", "-v"}
+	args := []string{"build", "-v"}
 	args = appendParameters(args, tags, target)
 
 	os.Setenv("GOOS", goos)
