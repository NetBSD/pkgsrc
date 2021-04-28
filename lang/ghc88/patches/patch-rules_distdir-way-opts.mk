$NetBSD: patch-rules_distdir-way-opts.mk,v 1.3 2021/04/28 15:39:23 pho Exp $

Use correct RPATHs.

--- rules/distdir-way-opts.mk.orig	2020-07-08 16:43:04.000000000 +0000
+++ rules/distdir-way-opts.mk
@@ -209,7 +209,7 @@ ifneq "$4" "0"
 ifeq "$$(TargetElf)" "YES"
 $1_$2_$3_GHC_LD_OPTS += \
     -fno-use-rpaths \
-    $$(foreach d,$$($1_$2_TRANSITIVE_DEP_COMPONENT_IDS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)'$$$$ORIGIN/../$$d') -optl-Wl,-zorigin
+    $$(foreach d,$$($1_$2_TRANSITIVE_DEP_COMPONENT_IDS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)$$(ghclibdir)/$$d)
 else ifeq "$$(TargetOS_CPP)" "darwin"
 $1_$2_$3_GHC_LD_OPTS += \
     -fno-use-rpaths \
