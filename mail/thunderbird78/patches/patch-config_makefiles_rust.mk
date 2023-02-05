$NetBSD: patch-config_makefiles_rust.mk,v 1.1 2023/02/05 08:32:24 he Exp $

--- config/makefiles/rust.mk.orig	2020-08-28 21:32:29.000000000 +0000
+++ config/makefiles/rust.mk
@@ -52,6 +52,9 @@ endif
 ifeq (1,$(MOZ_PARALLEL_BUILD))
 cargo_build_flags += -j1
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 # These flags are passed via `cargo rustc` and only apply to the final rustc
 # invocation (i.e., only the top-level crate, not its dependencies).
