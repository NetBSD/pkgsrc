$NetBSD: patch-go.mod,v 1.1 2024/12/22 20:12:32 bsiegert Exp $

Update /x/net version to remove a vulnerability.
--- go.mod.orig	2024-12-22 19:58:57.194168637 +0000
+++ go.mod
@@ -6,7 +6,7 @@ require (
 	github.com/google/go-cmp v0.6.0
 	github.com/yuin/goldmark v1.4.13
 	golang.org/x/mod v0.22.0
-	golang.org/x/net v0.32.0
+	golang.org/x/net v0.33.0
 	golang.org/x/sync v0.10.0
 	golang.org/x/telemetry v0.0.0-20240521205824-bda55230c457
 )
