$NetBSD: patch-internal_dhcpd_broadcast__bsd.go,v 1.1 2025/12/01 08:54:33 adam Exp $

Support NetBSD.

--- internal/dhcpd/broadcast_bsd.go.orig	2025-10-30 14:08:58.000000000 +0000
+++ internal/dhcpd/broadcast_bsd.go
@@ -1,4 +1,4 @@
-//go:build freebsd || openbsd
+//go:build freebsd || netbsd || openbsd
 
 package dhcpd
 
