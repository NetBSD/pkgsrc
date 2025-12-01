$NetBSD: patch-internal_dhcpd_options__unix__internal__test.go,v 1.1 2025/12/01 08:54:34 adam Exp $

Support NetBSD.

--- internal/dhcpd/options_unix_internal_test.go.orig	2025-10-30 14:08:58.000000000 +0000
+++ internal/dhcpd/options_unix_internal_test.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd || linux || openbsd
+//go:build darwin || freebsd || linux || netbsd || openbsd
 
 package dhcpd
 
