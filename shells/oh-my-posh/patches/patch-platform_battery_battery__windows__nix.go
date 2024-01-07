$NetBSD: patch-platform_battery_battery__windows__nix.go,v 1.3 2024/01/07 19:46:12 pin Exp $

Compile on Solaris.

--- platform/battery/battery_windows_nix.go.orig	2024-01-07 18:06:12.905252542 +0000
+++ platform/battery/battery_windows_nix.go
@@ -1,4 +1,4 @@
-//go:build !darwin && !netbsd && !openbsd && !freebsd
+//go:build !darwin && !netbsd && !openbsd && !freebsd && !solaris
 
 package battery
 
