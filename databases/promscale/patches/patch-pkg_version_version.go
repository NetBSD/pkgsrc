$NetBSD: patch-pkg_version_version.go,v 1.3 2023/01/11 03:50:06 tnn Exp $

Update accepted versions until 0.17.0 proper is out.

--- pkg/version/version.go.orig	2022-10-20 15:31:32.000000000 +0000
+++ pkg/version/version.go
@@ -44,14 +44,14 @@ var (
 	Branch                     = ""      // Comes from -ldflags settings
 	EarliestUpgradeTestVersion = "0.3.0" // 0.3.0 earliest version an image with correct extension versions exists
 
-	PgVersionNumRange       = ">=12.x <15.x" // Corresponds to range within pg 12.0 to pg 14.99
+	PgVersionNumRange       = ">=12.x <16.x" // Corresponds to range within pg 12.0 to pg 15.99
 	pgAcceptedVersionsRange = semver.MustParseRange(PgVersionNumRange)
 
 	TimescaleVersionRangeString = ">=2.6.1 <2.99.0"
 	TimescaleVersionRange       = semver.MustParseRange(TimescaleVersionRangeString)
 
 	// ExtVersionRangeString is a range of required promscale extension versions
-	ExtVersionRangeString = ">=0.7.0 <0.7.99"
+	ExtVersionRangeString = ">=0.7.0 <0.8.99"
 	ExtVersionRange       = semver.MustParseRange(ExtVersionRangeString)
 
 	// Expose build info through Prometheus metric
