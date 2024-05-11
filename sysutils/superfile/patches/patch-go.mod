$NetBSD: patch-go.mod,v 1.1 2024/05/11 10:14:14 wiz Exp $

--- go.mod.orig	2024-05-08 14:43:56.000000000 +0000
+++ go.mod
@@ -62,3 +62,4 @@ require (
 	golang.org/x/term v0.19.0 // indirect
 	golang.org/x/text v0.14.0 // indirect
 )
+replace github.com/barasher/go-exiftool => ../../github.com/barasher/go-exiftool@v1.10.0
