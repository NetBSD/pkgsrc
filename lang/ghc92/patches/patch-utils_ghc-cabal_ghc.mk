$NetBSD: patch-utils_ghc-cabal_ghc.mk,v 1.1 2022/02/06 05:36:16 pho Exp $

Fix a bootstrapping issue. Already fixed in the upstream:
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/6882

--- utils/ghc-cabal/ghc.mk.orig	2022-01-30 08:08:36.680388512 +0000
+++ utils/ghc-cabal/ghc.mk
@@ -60,6 +60,7 @@ $(ghc-cabal_DIST_BINARY): $(CABAL_LEXER_
 	       $(addprefix -optc, $(SRC_CC_OPTS) $(CONF_CC_OPTS_STAGE0)) \
 	       $(addprefix -optl, $(SRC_LD_OPTS) $(CONF_GCC_LINKER_OPTS_STAGE0)) \
 				 -O0 \
+				 -XHaskell2010 \
 	       -hide-all-packages \
 	       -package-env - \
 	       $(addprefix -package , $(CABAL_BUILD_DEPS)) \
