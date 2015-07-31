$NetBSD: patch-src_cmd_go_build.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Support cgo on illumos.

--- src/cmd/go/build.go.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/cmd/go/build.go
@@ -2330,6 +2330,10 @@ func (b *builder) cgo(p *Package, cgoExe
 	if pie { // we need to use -pie for Linux/ARM to get accurate imported sym
 		cgoLDFLAGS = append(cgoLDFLAGS, "-pie")
 	}
+	lgcc_s := goos == "solaris"
+	if lgcc_s {
+		cgoLDFLAGS = append(cgoLDFLAGS, "-lgcc_s");
+	}
 	if err := b.gccld(p, dynobj, cgoLDFLAGS, linkobj); err != nil {
 		return nil, nil, err
 	}
