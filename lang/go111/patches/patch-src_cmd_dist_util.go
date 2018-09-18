$NetBSD: patch-src_cmd_dist_util.go,v 1.1 2018/09/18 16:22:14 bsiegert Exp $

--- src/cmd/dist/util.go.orig	2017-02-16 19:12:22.000000000 +0000
+++ src/cmd/dist/util.go
@@ -531,6 +531,11 @@ func xgetgoarm() string {
 		// sense to auto-detect the setting.
 		return "7"
 	}
+	if goos == "netbsd" {
+		// NetBSD go/arm support only earmv6hf or earmv7hf now.
+		// Any armv5 (or before) devices cannot work.
+		return "6"
+	}
 	if gohostarch != "arm" || goos != gohostos {
 		// Conservative default for cross-compilation.
 		return "5"
