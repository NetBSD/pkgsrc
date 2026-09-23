$NetBSD: patch-config_makefiles_rust.mk,v 1.8 2026/09/23 08:48:57 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Use less memory to fix build under NetBSD/i386.
From: https://bugzilla.mozilla.org/show_bug.cgi?id=1644409

--- config/makefiles/rust.mk.orig	2026-08-26 21:11:39.000000000 +0000
+++ config/makefiles/rust.mk
@@ -65,6 +65,9 @@ endif
 endif
 endif
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += @RUST_MAKE_JOBS@
+endif
 
 # Without -j > 1, make will not pass jobserver info down to cargo. Force
 # one job when requested as a special case.
@@ -91,7 +94,8 @@ ifeq (,$(findstring gkrust_gtest,$(RUST_LIBRARY_FILE))
 # Never enable when coverage is enabled to work around https://github.com/rust-lang/rust/issues/90045.
 ifndef MOZ_CODE_COVERAGE
 ifeq (,$(findstring gkrust_gtest,$(RUST_LIBRARY_FILE)))
-cargo_rustc_flags += -Clto$(if $(filter full,$(MOZ_LTO_RUST_CROSS)),=fat)
+cargo_rustc_flags += -Clto=thin
+export CARGO_PROFILE_RELEASE_LTO=thin
 endif
 # We need -Cembed-bitcode=yes for all crates when using -Clto.
 RUSTFLAGS += -Cembed-bitcode=yes
