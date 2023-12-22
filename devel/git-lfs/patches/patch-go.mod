$NetBSD: patch-go.mod,v 1.1 2023/12/22 19:14:43 bsiegert Exp $

--- go.mod.orig	2023-12-13 18:56:25.000000000 +0000
+++ go.mod
@@ -18,9 +18,9 @@ require (
 	github.com/ssgelm/cookiejarparser v1.0.1
 	github.com/stretchr/testify v1.6.1
 	github.com/xeipuuv/gojsonschema v0.0.0-20170210233622-6b67b3fab74d
-	golang.org/x/net v0.7.0
+	golang.org/x/net v0.19.0
 	golang.org/x/sync v0.1.0
-	golang.org/x/sys v0.5.0
+	golang.org/x/sys v0.15.0
 )
 
 require (
@@ -38,8 +38,8 @@ require (
 	github.com/spf13/pflag v1.0.5 // indirect
 	github.com/xeipuuv/gojsonpointer v0.0.0-20180127040702-4e3ac2762d5f // indirect
 	github.com/xeipuuv/gojsonreference v0.0.0-20180127040603-bd5ef7bd5415 // indirect
-	golang.org/x/crypto v0.0.0-20220411220226-7b82a4e95df4 // indirect
-	golang.org/x/text v0.7.0 // indirect
+	golang.org/x/crypto v0.17.0 // indirect
+	golang.org/x/text v0.14.0 // indirect
 	gopkg.in/yaml.v3 v3.0.1 // indirect
 )
 
