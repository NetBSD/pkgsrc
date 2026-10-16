$NetBSD: patch-config_makefiles_rust.mk,v 1.9 2026/10/16 16:36:07 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Use less memory to fix build under NetBSD/i386.
From: https://bugzilla.mozilla.org/show_bug.cgi?id=1644409

--- config/makefiles/rust.mk.orig	2026-10-08 02:23:59.000000000 +0000
+++ config/makefiles/rust.mk
@@ -45,6 +45,9 @@ endif
 endif
 endif
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += @RUST_MAKE_JOBS@
+endif
 
 # Without -j > 1, make will not pass jobserver info down to cargo. Force
 # one job when requested as a special case.
@@ -56,7 +59,8 @@ ifdef RUST_LIBRARY_LTO
 cargo_rustc_flags = $(CARGO_RUSTCFLAGS)
 # Enable link-time optimization for release builds.
 ifdef RUST_LIBRARY_LTO
-cargo_rustc_flags += -Clto
+cargo_rustc_flags += -Clto=thin
+export CARGO_PROFILE_RELEASE_LTO=thin
 endif
 
 ifdef CARGO_INCREMENTAL
