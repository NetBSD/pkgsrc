$NetBSD: patch-rts_ghc.mk,v 1.2 2014/05/21 16:07:59 jperkin Exp $

This is pkgsrc specific: dtrace(1) gets confused when we have gcc
wrappers in the PATH so we have to hide them:

  gcc: installation problem, cannot exec '/usr/pkgsrc/wip/ghc/work/.gcc/bin/p
  owerpc-apple-darwin9-gcc-4.0.1': No such file or directory
  dtrace: failed to compile script rts/RtsProbes.d: Preprocessor failed to pr
  ocess input program

Also install libffi.{a,la} so we can expand to figure out .so extensions.

--- rts/ghc.mk.orig	2013-04-18 21:22:47.000000000 +0000
+++ rts/ghc.mk
@@ -114,6 +114,7 @@ $(rts_ffi_objs_stamp): $(libffi_STATIC_L
 # depend on libffi.so, but copy libffi.so*
 rts/dist/build/libffi$(soext): libffi/build/inst/lib/libffi$(soext)
 	cp libffi/build/inst/lib/libffi$(soext)* rts/dist/build
+	cp libffi/build/inst/lib/libffi.{a,la} rts/dist/build
 
 rts/dist/build/$(LIBFFI_DLL): libffi/build/inst/bin/$(LIBFFI_DLL)
 	cp $< $@
@@ -484,7 +485,7 @@ endif
 
 DTRACEPROBES_SRC = rts/RtsProbes.d
 $(DTRACEPROBES_H): $(DTRACEPROBES_SRC) includes/ghcplatform.h | $$(dir $$@)/.
-	"$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
+	env PATH="/usr/bin" "$(DTRACE)" $(filter -I%,$(rts_CC_OPTS)) -C $(DTRACE_FLAGS) -h -o $@ -s $<
 endif
 
 # -----------------------------------------------------------------------------
@@ -510,6 +511,7 @@ endif
 
 INSTALL_LIBS += $(ALL_RTS_LIBS)
 INSTALL_LIBS += $(wildcard rts/dist/build/libffi$(soext)*)
+INSTALL_LIBS += $(wildcard rts/dist/build/libffi.*a)
 INSTALL_LIBS += $(wildcard rts/dist/build/$(LIBFFI_DLL))
 
 install: install_libffi_headers
