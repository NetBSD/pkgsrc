$NetBSD: patch-go.mod,v 1.1 2020/08/22 10:21:14 bsiegert Exp $

--- go.mod.orig	2020-07-28 13:29:13.000000000 +0000
+++ go.mod
@@ -27,4 +27,7 @@ require (
 	gopkg.in/yaml.v3 v3.0.0-20200506231410-2ff61e1afc86
 )
 
-replace github.com/shurcooL/graphql => github.com/cli/shurcooL-graphql v0.0.0-20200707151639-0f7232a2bf7e
+replace (
+	github.com/shurcooL/graphql => github.com/cli/shurcooL-graphql v0.0.0-20200707151639-0f7232a2bf7e
+	github.com/muesli/termenv => github.com/muesli/termenv v0.7.1
+)
