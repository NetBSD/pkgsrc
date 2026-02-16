$NetBSD: patch-go.mod,v 1.3 2026/02/16 18:10:13 pin Exp $

Lower the required go version.

--- go.mod.orig	2026-02-16 17:57:17.762648659 +0000
+++ go.mod
@@ -1,6 +1,6 @@ module github.com/jandedobbeleer/oh-my-posh/src
 module github.com/jandedobbeleer/oh-my-posh/src
 
-go 1.26.0
+go 1.25.7
 
 require (
 	github.com/Azure/go-ansiterm v0.0.0-20250102033503-faa5f7b0171c
