$NetBSD: patch-toolkit_toolkit-tiers.mk,v 1.3 2012/04/28 16:56:59 ryoon Exp $

--- mozilla/toolkit/toolkit-tiers.mk.orig	2012-04-20 22:40:26.000000000 +0000
+++ mozilla/toolkit/toolkit-tiers.mk
@@ -80,7 +80,7 @@ ifdef MOZ_UPDATER
 ifndef MOZ_NATIVE_BZ2
 tier_platform_dirs += modules/libbz2
 endif
-tier_platform_dirs += other-licenses/bsdiff
+#tier_platform_dirs += other-licenses/bsdiff
 endif
 
 tier_platform_dirs	+= gfx/qcms
