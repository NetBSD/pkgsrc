$NetBSD: patch-internal_aghnet_dhcp__unix.go,v 1.1 2025/12/01 08:54:33 adam Exp $

Support NetBSD.

--- internal/aghnet/dhcp_unix.go.orig	2025-10-30 14:08:58.000000000 +0000
+++ internal/aghnet/dhcp_unix.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd || linux || openbsd
+//go:build darwin || freebsd || linux || netbsd || openbsd
 
 package aghnet
