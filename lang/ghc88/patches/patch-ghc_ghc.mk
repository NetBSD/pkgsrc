$NetBSD: patch-ghc_ghc.mk,v 1.3 2020/08/24 17:23:12 pho Exp $

Fix building bootkits: the ghc-bin package is threaded by default, but
the build system fails to opt out from it when threaded RTS is
disabled:
https://gitlab.haskell.org/ghc/ghc/issues/17692

--- ghc/ghc.mk.orig	2020-08-24 10:13:02.192874900 +0000
+++ ghc/ghc.mk
@@ -61,6 +61,10 @@ ifeq "$(GhcThreaded)" "YES"
 # Use threaded RTS with GHCi, so threads don't get blocked at the prompt.
 ghc_stage2_MORE_HC_OPTS += -threaded
 ghc_stage3_MORE_HC_OPTS += -threaded
+else
+# Opt out from threaded GHC. See ghc-bin.cabal.in
+ghc_stage2_CONFIGURE_OPTS += -f-threaded
+ghc_stage3_CONFIGURE_OPTS += -f-threaded
 endif
 
 # If stage 0 supplies a threaded RTS, we can use it for stage 1.
