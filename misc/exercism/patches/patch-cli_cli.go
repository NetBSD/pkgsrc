$NetBSD: patch-cli_cli.go,v 1.1 2023/03/15 20:22:51 schmonz Exp $

Don't let the program try to update itself.

--- cli/cli.go.orig	2022-10-04 09:26:56.000000000 +0000
+++ cli/cli.go
@@ -95,6 +95,8 @@ func (c *CLI) IsUpToDate() (bool, error)
 
 // Upgrade allows the user to upgrade to the latest version of the CLI.
 func (c *CLI) Upgrade() error {
+	return fmt.Errorf("use pkgsrc tools to upgrade")
+
 	var (
 		OS   = osMap[runtime.GOOS]
 		ARCH = archMap[runtime.GOARCH]
