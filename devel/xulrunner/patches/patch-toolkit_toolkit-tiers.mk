$NetBSD: patch-toolkit_toolkit-tiers.mk,v 1.5 2012/08/28 23:27:10 ryoon Exp $

--- toolkit/toolkit-tiers.mk.orig	2012-08-24 22:56:08.000000000 +0000
+++ toolkit/toolkit-tiers.mk
@@ -47,7 +47,7 @@ ifdef MOZ_UPDATER
 ifndef MOZ_NATIVE_BZ2
 tier_platform_dirs += modules/libbz2
 endif
-tier_platform_dirs += other-licenses/bsdiff
+#tier_platform_dirs += other-licenses/bsdiff
 endif
 
 tier_platform_dirs	+= gfx/qcms
