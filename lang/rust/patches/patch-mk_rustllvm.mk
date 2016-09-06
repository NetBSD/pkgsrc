$NetBSD: patch-mk_rustllvm.mk,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Ensure we can find generated LLVM includes.

--- mk/rustllvm.mk.orig	2016-07-04 18:04:09.000000000 +0000
+++ mk/rustllvm.mk
@@ -17,11 +17,9 @@ define DEF_RUSTLLVM_TARGETS
 # FIXME: Lately, on windows, llvm-config --includedir is not enough
 # to find the llvm includes (probably because we're not actually installing
 # llvm, but using it straight out of the build directory)
-ifdef CFG_WINDOWSY_$(1)
 LLVM_EXTRA_INCDIRS_$(1)= $$(call CFG_CC_INCLUDE_$(1),$(S)src/llvm/include) \
                          $$(call CFG_CC_INCLUDE_$(1),\
 			   $$(CFG_LLVM_BUILD_DIR_$(1))/include)
-endif
 
 RUSTLLVM_OBJS_CS_$(1) := $$(addprefix rustllvm/, \
 	ExecutionEngineWrapper.cpp RustWrapper.cpp PassWrapper.cpp \
