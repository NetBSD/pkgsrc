$NetBSD: patch-cmd_version.go,v 1.1 2023/03/15 20:22:51 schmonz Exp $

Don't let the program try to update itself.

--- cmd/version.go.orig	2022-10-04 09:26:56.000000000 +0000
+++ cmd/version.go
@@ -61,7 +61,7 @@ func checkForUpdate(c *cli.CLI) (string,
 	}
 
 	// Anything but ok is out of date.
-	msg := fmt.Sprintf("A new CLI version is available. Run `exercism upgrade` to update to %s", c.LatestRelease.Version())
+	msg := fmt.Sprintf("A new CLI version is available. Use pkgsrc tools to update to %s", c.LatestRelease.Version())
 	return msg, nil
 
 }
