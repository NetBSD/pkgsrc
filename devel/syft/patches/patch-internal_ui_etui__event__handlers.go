$NetBSD: patch-internal_ui_etui__event__handlers.go,v 1.1 2022/12/19 19:03:09 wiz Exp $

Support NetBSD.
https://github.com/anchore/syft/pull/1412

--- internal/ui/etui_event_handlers.go.orig	2022-12-12 17:55:12.000000000 +0000
+++ internal/ui/etui_event_handlers.go
@@ -1,5 +1,5 @@
-//go:build linux || darwin
-// +build linux darwin
+//go:build linux || darwin || netbsd
+// +build linux darwin netbsd
 
 package ui
 
