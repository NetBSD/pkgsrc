$NetBSD: patch-internal_aghos_os__bsd.go,v 1.1 2025/12/01 08:54:33 adam Exp $

Support NetBSD.

--- internal/aghos/os_bsd.go.orig	2025-10-30 14:08:58.000000000 +0000
+++ internal/aghos/os_bsd.go
@@ -1,4 +1,4 @@
-//go:build darwin || openbsd
+//go:build darwin || netbsd || openbsd
 
 package aghos
 
