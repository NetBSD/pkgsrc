$NetBSD: patch-ghc_ghc.mk,v 1.1 2020/01/09 12:32:24 pho Exp $

Fix building bootkits: the ghc-bin package is threaded by default, but
the build system fails to opt out from it when threaded RTS is
disabled.

--- ghc/ghc.mk.orig	2019-08-25 12:03:36.000000000 +0000
+++ ghc/ghc.mk
@@ -61,7 +61,13 @@ ifeq "$(GhcThreaded)" "YES"
 # Use threaded RTS with GHCi, so threads don't get blocked at the prompt.
 ghc_stage2_MORE_HC_OPTS += -threaded
 ghc_stage3_MORE_HC_OPTS += -threaded
+else
+# Opt out from threaded GHC. See ghc-bin.cabal.in
+ghc_stage2_CONFIGURE_OPTS += -f-threaded
+ghc_stage3_CONFIGURE_OPTS += -f-threaded
 endif
+# Stage-0 compiler isn't guaranteed to have a threaded RTS.
+ghc_stage1_CONFIGURE_OPTS += -f-threaded
 
 ifeq "$(GhcProfiled)" "YES"
 ghc_stage2_PROGRAM_WAY = p
