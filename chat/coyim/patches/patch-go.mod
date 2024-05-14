$NetBSD: patch-go.mod,v 1.1 2024/05/14 22:38:57 wiz Exp $

Use patched copy that supports NetBSD.

--- go.mod.orig	2024-05-14 22:00:14.425839316 +0000
+++ go.mod
@@ -39,3 +39,5 @@ require (
 	golang.org/x/sys v0.0.0-20200523222454-059865788121 // indirect
 	gopkg.in/yaml.v3 v3.0.0-20210107192922-496545a6307b // indirect
 )
+
+replace github.com/awnumar/memcall => ../github.com/awnumar/memcall@v0.1.2
