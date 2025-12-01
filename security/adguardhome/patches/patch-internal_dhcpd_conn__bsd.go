$NetBSD: patch-internal_dhcpd_conn__bsd.go,v 1.1 2025/12/01 08:54:33 adam Exp $

Support NetBSD.

--- internal/dhcpd/conn_bsd.go.orig	2025-10-30 14:08:58.000000000 +0000
+++ internal/dhcpd/conn_bsd.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd || openbsd
+//go:build darwin || freebsd || netbsd || openbsd
 
 package dhcpd
 
