$NetBSD: patch-go.mod,v 1.1 2023/02/03 14:28:58 bsiegert Exp $

Use the patched version of pg_query_go.

--- go.mod.orig	2023-01-17 21:25:19.174290587 +0000
+++ go.mod
@@ -20,6 +20,8 @@ require (
 	gopkg.in/yaml.v3 v3.0.1
 )
 
+replace github.com/pganalyze/pg_query_go/v2 => ../github.com/pganalyze/pg_query_go/v2@v2.2.0/
+
 require (
 	github.com/cznic/mathutil v0.0.0-20181122101859-297441e03548 // indirect
 	github.com/remyoudompheng/bigfft v0.0.0-20200410134404-eec4a21b6bb0 // indirect
