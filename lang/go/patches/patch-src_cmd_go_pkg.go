$NetBSD: patch-src_cmd_go_pkg.go,v 1.2 2015/08/22 10:51:20 bsiegert Exp $

Do not try to install go-tools into GOROOT. This is done in the
go-tools package instead.

--- src/cmd/go/pkg.go.orig	2015-07-30 00:03:36.000000000 +0000
+++ src/cmd/go/pkg.go
@@ -651,7 +651,6 @@ var goTools = map[string]targetDir{
 	"cmd/trace":                            toTool,
 	"cmd/vet":                              toTool,
 	"cmd/yacc":                             toTool,
-	"golang.org/x/tools/cmd/godoc":         toBin,
 	"code.google.com/p/go.tools/cmd/cover": stalePath,
 	"code.google.com/p/go.tools/cmd/godoc": stalePath,
 	"code.google.com/p/go.tools/cmd/vet":   stalePath,
