$NetBSD: patch-internal_arpdb_arpdb__bsd.go,v 1.1 2025/12/01 08:54:33 adam Exp $

Support NetBSD.

--- internal/arpdb/arpdb_bsd.go.orig	2025-11-30 11:12:35.072018136 +0000
+++ internal/arpdb/arpdb_bsd.go
@@ -1,4 +1,4 @@
-//go:build darwin || freebsd
+//go:build darwin || freebsd || netbsd
 
 package arpdb
 
