$NetBSD: patch-go.mod,v 1.1 2025/03/06 19:15:17 pin Exp $

Soften version requirements.

--- go.mod.orig	2025-03-06 18:54:01.150811974 +0000
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/jandedobbeleer/oh-my-posh/src
 
-go 1.24.1
+go 1.24.0
 
 require (
 	github.com/Azure/go-ansiterm v0.0.0-20250102033503-faa5f7b0171c
