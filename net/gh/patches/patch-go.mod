$NetBSD: patch-go.mod,v 1.4 2020/11/08 21:59:28 bsiegert Exp $

Bump termenv version to supports more platforms.

github.com/muesli/termenv version 0.7.1 or higher is required on NetBSD,
older versions do not contain platform support.

--- go.mod.orig	2020-09-16 16:53:21.000000000 +0000
+++ go.mod
@@ -29,4 +29,7 @@ require (
 	gopkg.in/yaml.v3 v3.0.0-20200615113413-eeeca48fe776
 )
 
-replace github.com/shurcooL/graphql => github.com/cli/shurcooL-graphql v0.0.0-20200707151639-0f7232a2bf7e
+replace (
+	github.com/shurcooL/graphql => github.com/cli/shurcooL-graphql v0.0.0-20200707151639-0f7232a2bf7e
+	github.com/muesli/termenv => github.com/muesli/termenv v0.7.1
+)
