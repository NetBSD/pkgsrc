$NetBSD: patch-src_cmd_go_pkg.go,v 1.1 2015/07/31 14:46:25 bsiegert Exp $

Do not try to install go-tools into GOROOT. This is done in the
go-tools package instead.

--- src/cmd/go/pkg.go.orig	2014-12-11 01:18:10.000000000 +0000
+++ src/cmd/go/pkg.go
@@ -401,9 +401,6 @@ var goTools = map[string]targetDir{
 	"cmd/pack":                             toTool,
 	"cmd/pprof":                            toTool,
 	"cmd/yacc":                             toTool,
-	"golang.org/x/tools/cmd/cover":         toTool,
-	"golang.org/x/tools/cmd/godoc":         toBin,
-	"golang.org/x/tools/cmd/vet":           toTool,
 	"code.google.com/p/go.tools/cmd/cover": stalePath,
 	"code.google.com/p/go.tools/cmd/godoc": stalePath,
 	"code.google.com/p/go.tools/cmd/vet":   stalePath,
