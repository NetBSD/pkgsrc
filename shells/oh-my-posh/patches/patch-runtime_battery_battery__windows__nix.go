$NetBSD: patch-runtime_battery_battery__windows__nix.go,v 1.1 2024/07/17 06:23:56 pin Exp $

Compile on Solaris.

--- runtime/battery/battery_windows_nix.go.orig	2024-07-17 06:03:31.683756345 +0000
+++ runtime/battery/battery_windows_nix.go
@@ -1,4 +1,4 @@
-//go:build !darwin && !netbsd && !openbsd && !freebsd
+//go:build !darwin && !netbsd && !openbsd && !freebsd && !solaris
 
 package battery
 
