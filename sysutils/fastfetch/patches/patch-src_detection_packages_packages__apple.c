$NetBSD: patch-src_detection_packages_packages__apple.c,v 1.1 2025/02/14 13:26:54 vins Exp $

Enable pkgsrc support on macOS.

--- src/detection/packages/packages_apple.c.orig	2025-02-14 11:53:56.694737100 +0000
+++ src/detection/packages/packages_apple.c
@@ -83,6 +83,8 @@ void ffDetectPackagesImpl(FFPackagesResu
 {
     if (!(options->disabled & FF_PACKAGES_FLAG_BREW_BIT)) getBrewPackages(result);
     if (!(options->disabled & FF_PACKAGES_FLAG_MACPORTS_BIT)) result->macports = getMacPortsPackages();
+    if (!(options->disabled & FF_PACKAGES_FLAG_PKGSRC_BIT))
+        result->pkgsrc = ffPackagesGetNumElements(FASTFETCH_TARGET_DIR_ROOT "/usr/pkg/pkgdb", DT_DIR);
     if (!(options->disabled & FF_PACKAGES_FLAG_NIX_BIT))
     {
         FF_STRBUF_AUTO_DESTROY baseDir = ffStrbufCreateS(FASTFETCH_TARGET_DIR_ROOT);
