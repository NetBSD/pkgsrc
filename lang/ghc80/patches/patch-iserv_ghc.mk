$NetBSD: patch-iserv_ghc.mk,v 1.1 2020/01/03 15:24:08 pho Exp $

Do not build threaded iserv if threaded RTS isn't being built. That is
impossible to do.

--- iserv/ghc.mk.orig	2020-01-03 10:45:07.879183648 +0000
+++ iserv/ghc.mk
@@ -19,9 +19,9 @@ iserv_stage2_p_MORE_HC_OPTS += -debug
 iserv_stage2_dyn_MORE_HC_OPTS += -debug
 endif
 
-iserv_stage2_MORE_HC_OPTS += -threaded
-iserv_stage2_p_MORE_HC_OPTS += -threaded
-iserv_stage2_dyn_MORE_HC_OPTS += -threaded
+iserv_stage2_MORE_HC_OPTS += $(if $(findstring thr,$(GhcRTSWays)),-threaded)
+iserv_stage2_p_MORE_HC_OPTS += $(if $(findstring thr,$(GhcRTSWays)),-threaded)
+iserv_stage2_dyn_MORE_HC_OPTS += $(if $(findstring thr,$(GhcRTSWays)),-threaded)
 
 # Override the default way, because we want a specific version of this
 # program for each way.  Note that it's important to do this even for
