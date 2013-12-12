$NetBSD: patch-rts_ghc.mk,v 1.1 2013/12/12 12:47:17 obache Exp $

This is pkgsrc specific: dtrace(1) gets confused when we have gcc
wrappers in the PATH so we have to hide them:

  gcc: installation problem, cannot exec '/usr/pkgsrc/wip/ghc/work/.gcc/bin/p
  owerpc-apple-darwin9-gcc-4.0.1': No such file or directory
  dtrace: failed to compile script rts/RtsProbes.d: Preprocessor failed to pr
  ocess input program


--- rts/ghc.mk.orig	2013-01-27 13:21:52.000000000 +0000
+++ rts/ghc.mk
@@ -484,7 +484,7 @@ endif
 
 DTRACEPROBES_SRC = rts/RtsProbes.d
 $(DTRACEPROBES_H): $(DTRACEPROBES_SRC) includes/ghcplatform.h | $$(dir $$@)/.
-	"$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
+	env PATH="/usr/bin" "$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
 endif
 
 # -----------------------------------------------------------------------------
