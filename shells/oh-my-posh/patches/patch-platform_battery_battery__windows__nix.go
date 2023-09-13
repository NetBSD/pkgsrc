$NetBSD: patch-platform_battery_battery__windows__nix.go,v 1.2 2023/09/13 08:08:38 pin Exp $

Compile on Solaris.

--- platform/battery/battery_windows_nix.go.orig	2023-09-12 18:50:00.000000000 +0000
+++ platform/battery/battery_windows_nix.go
@@ -1,4 +1,4 @@
-//go:build !darwin && !netbsd && !openbsd
+//go:build !darwin && !netbsd && !openbsd && !solaris
 
 package battery
 
