$NetBSD: patch-platform_battery_battery__unix.go,v 1.1 2023/04/07 00:32:56 schmonz Exp $

Build this file only on Unixy platforms (besides Darwin).

--- platform/battery/battery_unix.go.orig	2023-03-17 08:45:01.000000000 +0000
+++ platform/battery/battery_unix.go
@@ -1,3 +1,5 @@
+//go:build !darwin && !windows
+
 // battery
 // Copyright (C) 2016-2017 Karol 'Kenji Takahashi' Woźniak
 //
