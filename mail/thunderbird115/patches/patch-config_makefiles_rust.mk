$NetBSD: patch-config_makefiles_rust.mk,v 1.1 2024/10/01 14:21:36 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Expand -Clto=thin for all to avoid out-of-memory errors.

--- config/makefiles/rust.mk.orig	2024-08-01 19:52:10.000000000 +0000
+++ config/makefiles/rust.mk
@@ -60,6 +60,9 @@ ifdef MOZ_TSAN
 cargo_build_flags += -Zbuild-std=std,panic_abort
 RUSTFLAGS += -Zsanitizer=thread
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += @RUST_MAKE_JOBS@
+endif
 
 rustflags_sancov =
 ifdef LIBFUZZER
@@ -91,9 +94,7 @@ ifndef MOZ_LTO_RUST_CROSS
 ifndef rustflags_sancov
 # Never enable when coverage is enabled to work around https://github.com/rust-lang/rust/issues/90045.
 ifndef MOZ_CODE_COVERAGE
-ifeq (,$(findstring gkrust_gtest,$(RUST_LIBRARY_FILE)))
-cargo_rustc_flags += -Clto$(if $(filter full,$(MOZ_LTO_RUST_CROSS)),=fat)
-endif
+cargo_rustc_flags += -Clto=thin
 # We need -Cembed-bitcode=yes for all crates when using -Clto.
 RUSTFLAGS += -Cembed-bitcode=yes
 endif
