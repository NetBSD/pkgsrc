$NetBSD: patch-go.mod,v 1.1 2025/01/22 22:39:42 leot Exp $

Rerun go mod tidy and get rid of toolchain.

Without that build fails with:

 go: updates to go.mod needed; to update it:
         go mod tidy

--- go.mod.orig	2024-12-31 12:27:00.000000000 +0000
+++ go.mod
@@ -1,8 +1,6 @@
 module github.com/getsops/sops/v3
 
-go 1.22
-
-toolchain go1.22.9
+go 1.22.7
 
 require (
 	cloud.google.com/go/kms v1.20.3
