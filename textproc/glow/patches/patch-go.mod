$NetBSD: patch-go.mod,v 1.1 2023/12/23 20:00:23 bsiegert Exp $

Update go-crypto to non-vulnerable version.

--- go.mod.orig	2023-12-23 19:53:16.634467527 +0000
+++ go.mod
@@ -21,7 +21,8 @@ require (
 	github.com/segmentio/ksuid v1.0.4
 	github.com/spf13/cobra v1.6.1
 	github.com/spf13/viper v1.14.0
-	golang.org/x/sys v0.7.0
-	golang.org/x/term v0.7.0
-	golang.org/x/text v0.9.0
+	golang.org/x/crypto v0.17.0 // indirect
+	golang.org/x/sys v0.15.0
+	golang.org/x/term v0.15.0
+	golang.org/x/text v0.14.0
 )
