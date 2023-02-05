$NetBSD: patch-src_cmd_dist_util.go,v 1.1 2023/02/05 13:25:26 bsiegert Exp $

--- src/cmd/dist/util.go.orig	2021-06-10 13:56:34.000000000 +0000
+++ src/cmd/dist/util.go
@@ -394,6 +394,11 @@ func xgetgoarm() string {
 		// windows/arm only works with ARMv7 executables.
 		return "7"
 	}
+	if goos == "netbsd" {
+		// NetBSD go/arm supports only earmv6hf or earmv7hf.
+		// Any armv5 (or before) devices cannot work.
+		return "6"
+	}
 	if gohostarch != "arm" || goos != gohostos {
 		// Conservative default for cross-compilation.
 		return "5"
