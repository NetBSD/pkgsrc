$NetBSD: patch-rts_ghc.mk,v 1.1 2022/02/06 05:36:16 pho Exp $

This is for Darwin. See the patch to rules/distdir-way-opts.mk.

--- rts/ghc.mk.orig	2021-04-29 03:14:20.000000000 +0000
+++ rts/ghc.mk
@@ -251,6 +251,7 @@ endif
 $$(rts_$1_LIB) : $$(rts_$1_OBJS) $$(rts_$1_DTRACE_OBJS) rts/dist/libs.depend $$(rts_dist_FFI_SO)
 	"$$(RM)" $$(RM_OPTS) $$@
 	"$$(rts_dist_HC)" -this-unit-id rts -shared -dynamic -dynload deploy \
+	  -dylib-install-name $$(ghclibdir)/rts/$$(rts_$1_LIB_FILE) \
 	  -no-auto-link-packages $$(LIBFFI_LIBS) `cat rts/dist/libs.depend` $$(rts_$1_OBJS) \
           $$(rts_dist_$1_GHC_LD_OPTS) \
 	  $$(rts_$1_DTRACE_OBJS) -o $$@
