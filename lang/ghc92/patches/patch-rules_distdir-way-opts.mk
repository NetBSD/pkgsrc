$NetBSD: patch-rules_distdir-way-opts.mk,v 1.1 2022/02/06 05:36:16 pho Exp $

Use correct RPATHs. On ELF we replace "$ORIGIN/../{PACKAGE_ID}" with
the final installation path.

On Darwin library paths work differently. If an executable (or a
library) A depends on a library B, the installation path of B is first
embedded in B, and then the path propagates to A at the time when A is
linked. So we remove -rpath to libraries here, and do the other half
in rules/build-package-way.mk and rts/ghc.mk.

--- rules/distdir-way-opts.mk.orig	2020-07-08 16:43:04.000000000 +0000
+++ rules/distdir-way-opts.mk
@@ -209,11 +209,10 @@ ifneq "$4" "0"
 ifeq "$$(TargetElf)" "YES"
 $1_$2_$3_GHC_LD_OPTS += \
     -fno-use-rpaths \
-    $$(foreach d,$$($1_$2_TRANSITIVE_DEP_COMPONENT_IDS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)'$$$$ORIGIN/../$$d') -optl-Wl,-zorigin
+    $$(foreach d,$$($1_$2_TRANSITIVE_DEP_COMPONENT_IDS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)$$(ghclibdir)/$$d)
 else ifeq "$$(TargetOS_CPP)" "darwin"
 $1_$2_$3_GHC_LD_OPTS += \
-    -fno-use-rpaths \
-    $$(foreach d,$$($1_$2_TRANSITIVE_DEP_COMPONENT_IDS),-optl-Wl$$(comma)-rpath -optl-Wl$$(comma)'@loader_path/../$$d')
+    -fno-use-rpaths
 endif
 endif
 endif
