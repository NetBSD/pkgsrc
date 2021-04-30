$NetBSD: patch-rules_build-package-way.mk,v 1.1 2021/04/30 18:52:05 pho Exp $

This is for Darwin. See the patch to rules/distdir-way-opts.mk.

--- rules/build-package-way.mk.orig	2015-07-23 22:06:18.000000000 +0000
+++ rules/build-package-way.mk
@@ -90,6 +90,7 @@ else
 $$($1_$2_$3_LIB) : $$($1_$2_$3_ALL_OBJS) $$(ALL_RTS_LIBS) $$($1_$2_$3_DEPS_LIBS)
 	$$(call cmd,$1_$2_HC) $$($1_$2_$3_ALL_HC_OPTS) $$($1_$2_$3_GHC_LD_OPTS) $$($1_$2_$3_ALL_OBJS) \
          -shared -dynamic -dynload deploy \
+	 -dylib-install-name $$(ghclibdir)/$$($1_$2_PACKAGE_KEY)/$$($1_$2_$3_LIB_NAME) \
 	 $$(addprefix -l,$$($1_$2_EXTRA_LIBRARIES)) $$(addprefix -L,$$($1_$2_EXTRA_LIBDIRS)) \
          -no-auto-link-packages \
          -o $$@
