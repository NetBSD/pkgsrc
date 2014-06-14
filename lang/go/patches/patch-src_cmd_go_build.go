$NetBSD: patch-src_cmd_go_build.go,v 1.1 2014/06/14 16:22:25 joerg Exp $

libgcc might simply not exist at all, so just ignore it if it is not
an absolute path.

--- src/cmd/go/build.go.orig	2014-05-30 11:43:55.000000000 +0000
+++ src/cmd/go/build.go
@@ -1809,7 +1809,7 @@ func (b *builder) libgcc(p *Package) (st
 
 	// clang might not be able to find libgcc, and in that case,
 	// it will simply return "libgcc.a", which is of no use to us.
-	if strings.Contains(gccCmd[0], "clang") && !filepath.IsAbs(string(f)) {
+	if !filepath.IsAbs(string(f)) {
 		return "", nil
 	}
 
