$NetBSD: patch-font_install__unix.go,v 1.1 2023/04/07 00:32:56 schmonz Exp $

Build this file also on other Unixy platforms (besides Darwin).

--- font/install_unix.go.orig	2023-03-17 08:45:01.000000000 +0000
+++ font/install_unix.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build !darwin && !windows
 
 // Derived from https://github.com/Crosse/font-install
 // Copyright 2020 Seth Wright <seth@crosse.org>
