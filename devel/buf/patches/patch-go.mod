$NetBSD: patch-go.mod,v 1.1 2025/09/07 18:29:25 maya Exp $

Use the copy of docker/docker we extracted with GO_MODULE_EXTRACT
and patched.

--- go.mod.orig	2024-10-08 19:19:09.000000000 +0000
+++ go.mod
@@ -125,3 +125,5 @@ require (
 	google.golang.org/genproto/googleapis/rpc v0.0.0-20240930140551-af27646dc61f // indirect
 	google.golang.org/grpc v1.67.1 // indirect
 )
+
+replace github.com/docker/docker => ../github.com/docker/docker@v27.3.1+incompatible
