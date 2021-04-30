$NetBSD: patch-rts_ghc.mk,v 1.8 2021/04/30 18:52:05 pho Exp $

This is for Darwin. See the patch to rules/distdir-way-opts.mk.

--- rts/ghc.mk.orig	2015-07-23 22:06:18.000000000 +0000
+++ rts/ghc.mk
@@ -189,6 +189,7 @@ ifeq "$$(HostOS_CPP)" "mingw32" 
 $$(rts_$1_LIB) : $$(rts_$1_OBJS) $$(ALL_RTS_DEF_LIBS) rts/dist/libs.depend rts/dist/build/$$(LIBFFI_DLL)
 	"$$(RM)" $$(RM_OPTS) $$@
 	"$$(rts_dist_HC)" -this-package-key rts -shared -dynamic -dynload deploy \
+	  -dylib-install-name $$(ghclibdir)/rts/$$(rts_$1_LIB_NAME) \
 	  -no-auto-link-packages -Lrts/dist/build -l$$(LIBFFI_NAME) \
          `cat rts/dist/libs.depend` $$(rts_$1_OBJS) $$(ALL_RTS_DEF_LIBS) \
          $$(rts_dist_$1_GHC_LD_OPTS) \
