$NetBSD: patch-upgrade_cli__other.go,v 1.1 2024/06/05 05:16:45 pin Exp $

Allow to build on NetBSD.

--- upgrade/cli_other.go.orig	2024-06-05 05:00:30.346597191 +0000
+++ upgrade/cli_other.go
@@ -1,4 +1,4 @@
-//go:build linux || freebsd || openbsd
+//go:build linux || freebsd || openbsd || netbsd
 
 package upgrade
 
