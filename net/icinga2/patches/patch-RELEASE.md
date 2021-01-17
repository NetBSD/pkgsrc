$NetBSD: patch-RELEASE.md,v 1.1 2021/01/17 13:22:26 wiz Exp $

Rename VERSION to ICINGA2_VERSION to avoid name clashes on case-insensitive file systems.
Upstream Pull Request #8596

--- RELEASE.md.orig	2020-12-15 12:30:19.000000000 +0100
+++ RELEASE.md	2021-01-15 16:08:14.000000000 +0100
@@ -64,7 +64,7 @@
 Update the version:
 
 ```
-sed -i "s/Version: .*/Version: $VERSION/g" VERSION
+sed -i "s/Version: .*/Version: $VERSION/g" ICINGA2_VERSION
 ```
 
 ## Changelog <a id="changelog"></a>
