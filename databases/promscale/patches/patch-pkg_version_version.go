$NetBSD: patch-pkg_version_version.go,v 1.1 2021/04/04 09:58:39 tnn Exp $

Support PostgreSQL 13.
https://github.com/timescale/promscale/commit/954d02e1b92f70c84e69359a1de7431178854108.patch

--- pkg/version/version.go.orig	2021-03-11 02:39:06.000000000 +0000
+++ pkg/version/version.go
@@ -42,7 +42,7 @@ var (
 	EarliestUpgradeTestVersion          = "0.1.0"
 	EarliestUpgradeTestVersionMultinode = "0.1.4" //0.1.4 earliest version that supports tsdb 2.0
 
-	PgVersionNumRange       = "=12.x" // Corresponds to range within pg 12.0 to pg 12.99
+	PgVersionNumRange       = ">=12.x <14.x" // Corresponds to range within pg 12.0 to pg 13.99
 	pgAcceptedVersionsRange = semver.MustParseRange(PgVersionNumRange)
 
 	TimescaleVersionRangeString = struct {
