$NetBSD: patch-internal_arpdb_arpdb__bsd__internal__test.go,v 1.1 2025/12/01 08:54:33 adam Exp $

Support NetBSD.

--- internal/arpdb/arpdb_bsd_internal_test.go.orig	2025-11-30 11:13:27.368670428 +0000
+++ internal/arpdb/arpdb_bsd_internal_test.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd
+//go:build darwin || freebsd || netbsd
 
 package arpdb
 
