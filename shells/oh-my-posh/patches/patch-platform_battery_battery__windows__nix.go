$NetBSD: patch-platform_battery_battery__windows__nix.go,v 1.1 2023/04/11 15:22:10 schmonz Exp $

Compile on Solaris.

--- platform/battery/battery_windows_nix.go.orig	2023-04-09 17:14:17.000000000 +0000
+++ platform/battery/battery_windows_nix.go
@@ -1,4 +1,4 @@
-//go:build !darwin && !netbsd
+//go:build !darwin && !netbsd && !solaris
 
 package battery
 
