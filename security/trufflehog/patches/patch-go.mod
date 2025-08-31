$NetBSD: patch-go.mod,v 1.2 2025/08/31 19:40:17 leot Exp $

Use go-ps to support NetBSD.

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- go.mod.orig	2025-08-14 20:34:14.000000000 +0000
+++ go.mod
@@ -320,3 +320,5 @@ require (
 	gopkg.in/warnings.v0 v0.1.2 // indirect
 	pault.ag/go/topsort v0.1.1 // indirect
 )
+
+replace github.com/mitchellh/go-ps => github.com/iamleot/go-ps v1.0.1-0.20230107215528-c3e6d0630c23
