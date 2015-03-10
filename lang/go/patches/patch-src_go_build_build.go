$NetBSD: patch-src_go_build_build.go,v 1.1 2015/03/10 13:11:36 jperkin Exp $

Support cgo on illumos.

--- src/go/build/build.go.orig	2014-12-11 01:18:12.000000000 +0000
+++ src/go/build/build.go
@@ -277,6 +277,7 @@ var cgoEnabled = map[string]bool{
 	"openbsd/amd64":   true,
 	"windows/386":     true,
 	"windows/amd64":   true,
+	"solaris/amd64":   true,
 }
 
 func defaultContext() Context {
