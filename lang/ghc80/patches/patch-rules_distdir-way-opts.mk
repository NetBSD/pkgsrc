$NetBSD: patch-rules_distdir-way-opts.mk,v 1.1 2020/02/17 17:22:43 jperkin Exp $

https://gitlab.haskell.org/ghc/ghc/issues/17385

--- rules/distdir-way-opts.mk.orig	2017-01-04 04:04:11.000000000 +0000
+++ rules/distdir-way-opts.mk
@@ -196,8 +196,8 @@ $1_$2_$3_ALL_LD_OPTS = \
  $$($1_$2_$3_LD_OPTS) \
  $$($1_$2_EXTRA_LD_OPTS) \
  $$(EXTRA_LD_OPTS) \
- $$(foreach o,$$(EXTRA_LD_LINKER_OPTS),-optl-Wl$$(comma)$$o) \
- $$(foreach o,$$(CONF_LD_LINKER_OPTS_STAGE$4),-optl-Wl$$(comma)$$o)
+ $$(foreach o,$$(EXTRA_LD_LINKER_OPTS),-Wl$$(comma)$$o) \
+ $$(foreach o,$$(CONF_LD_LINKER_OPTS_STAGE$4),-Wl$$(comma)$$o)
 
 # Options for passing to GHC when we use it for linking
 $1_$2_$3_GHC_LD_OPTS = \
