$NetBSD: patch-internal_aghnet_net__freebsd.go,v 1.1 2025/12/01 08:54:33 adam Exp $

Support NetBSD.

--- internal/aghnet/net_freebsd.go.orig	2025-11-30 11:04:19.320569820 +0000
+++ internal/aghnet/net_freebsd.go
@@ -1,4 +1,4 @@
-//go:build freebsd
+//go:build freebsd || netbsd
 
 package aghnet
