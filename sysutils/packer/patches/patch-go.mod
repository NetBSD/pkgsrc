$NetBSD: patch-go.mod,v 1.1 2023/12/24 12:36:18 bsiegert Exp $

Update /x/crypto version to fix a vulnerability

--- go.mod.orig	2023-12-24 10:07:54.035147303 +0000
+++ go.mod
@@ -45,14 +45,14 @@ require (
 	github.com/ulikunitz/xz v0.5.10
 	github.com/zclconf/go-cty v1.10.0
 	github.com/zclconf/go-cty-yaml v1.0.1
-	golang.org/x/crypto v0.14.0 // indirect
+	golang.org/x/crypto v0.17.0 // indirect
 	golang.org/x/mod v0.8.0
 	golang.org/x/net v0.17.0
 	golang.org/x/oauth2 v0.11.0
 	golang.org/x/sync v0.3.0
-	golang.org/x/sys v0.13.0 // indirect
-	golang.org/x/term v0.13.0 // indirect
-	golang.org/x/text v0.13.0 // indirect
+	golang.org/x/sys v0.15.0 // indirect
+	golang.org/x/term v0.15.0 // indirect
+	golang.org/x/text v0.14.0 // indirect
 	golang.org/x/tools v0.6.0
 	google.golang.org/api v0.128.0 // indirect
 	google.golang.org/grpc v1.59.0
