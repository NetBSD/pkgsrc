$NetBSD: patch-.._github.com_influxdata_flux@v0.65.1_go.mod,v 1.1 2021/05/12 09:59:22 jperkin Exp $

Replace with newer pkg/term with many fixes.

--- ../github.com/influxdata/flux@v0.65.1/go.mod.orig	1979-12-31 00:00:00.000000000 +0000
+++ ../github.com/influxdata/flux@v0.65.1/go.mod
@@ -49,3 +49,6 @@ require (
 	google.golang.org/api v0.7.0
 	gopkg.in/check.v1 v1.0.0-20180628173108-788fd7840127 // indirect
 )
+
+replace github.com/c-bata/go-prompt => github.com/c-bata/go-prompt v0.2.5
+replace github.com/pkg/term => github.com/pkg/term v1.1.0
