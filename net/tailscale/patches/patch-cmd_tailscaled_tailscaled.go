$NetBSD: patch-cmd_tailscaled_tailscaled.go,v 1.1 2026/07/14 20:43:31 schmonz Exp $

Report pkgsrc as the packaging type via Hostinfo.Package.

--- cmd/tailscaled/tailscaled.go.orig	2026-07-02 18:59:26.000000000 +0000
+++ cmd/tailscaled/tailscaled.go
@@ -495,6 +495,8 @@ func run() (err error) {
 		hostinfo.SetApp(app)
 	}
 
+	hostinfo.SetPackage("pkgsrc")
+
 	return startIPNServer(context.Background(), logf, publicLogID, sys)
 }
 
