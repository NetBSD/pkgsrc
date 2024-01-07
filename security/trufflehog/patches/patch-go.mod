$NetBSD: patch-go.mod,v 1.1 2024/01/07 13:10:55 leot Exp $

Use go-ps to support NetBSD.

Shared upstream via:

 <https://github.com/mitchellh/go-ps/pull/59>

--- go.mod.orig	2024-01-07 11:43:37.541861790 +0000
+++ go.mod
@@ -265,3 +265,5 @@ require (
 	gopkg.in/warnings.v0 v0.1.2 // indirect
 	gopkg.in/yaml.v3 v3.0.1 // indirect
 )
+
+replace github.com/mitchellh/go-ps => github.com/iamleot/go-ps v1.0.1-0.20230107215528-c3e6d0630c23
