$NetBSD: patch-go.mod,v 1.2 2025/06/04 20:29:52 fox Exp $

Use patched copy that supports NetBSD.

--- go.mod.orig	2025-06-04 20:16:13.809430896 +0000
+++ go.mod
@@ -38,3 +38,5 @@ require (
 	golang.org/x/sys v0.21.0 // indirect
 	gopkg.in/yaml.v3 v3.0.0-20210107192922-496545a6307b // indirect
 )
+
+replace github.com/awnumar/memcall => ../github.com/awnumar/memcall@v0.1.2
