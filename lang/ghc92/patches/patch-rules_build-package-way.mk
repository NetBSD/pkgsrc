$NetBSD: patch-rules_build-package-way.mk,v 1.1 2022/02/06 05:36:16 pho Exp $

This is for Darwin. See the patch to rules/distdir-way-opts.mk.

--- rules/build-package-way.mk.orig	2021-04-28 17:51:42.000000000 +0000
+++ rules/build-package-way.mk
@@ -64,6 +64,7 @@ else # ifneq "$$(TargetOS_CPP)" "mingw32
 $$($1_$2_$3_LIB) : $$($1_$2_$3_ALL_OBJS) $$(ALL_RTS_LIBS) $$($1_$2_$3_DEPS_LIBS)
 	$$(call cmd,$1_$2_HC) $$($1_$2_$3_ALL_HC_OPTS) $$($1_$2_$3_GHC_LD_OPTS) $$($1_$2_$3_ALL_OBJS) \
          -shared -dynamic -dynload deploy \
+	 -dylib-install-name $$(ghclibdir)/$$($1_$2_COMPONENT_ID)/$$($1_$2_$3_LIB_FILE) \
 	 $$(addprefix -l,$$($1_$2_EXTRA_LIBRARIES)) $$(addprefix -L,$$($1_$2_EXTRA_LIBDIRS)) \
          -no-auto-link-packages \
          -o $$@
