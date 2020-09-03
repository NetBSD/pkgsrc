$NetBSD: patch-config_makefiles_rust.mk,v 1.1 2020/09/03 20:22:26 ryoon Exp $

NetBSD<10 doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Set -Cembed-bitcode=yes when using LTO to fix build with rust >= 1.45.
Upstream bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1640982

--- config/makefiles/rust.mk.orig	2020-08-24 19:16:54.000000000 +0000
+++ config/makefiles/rust.mk
@@ -60,6 +60,10 @@ ifdef CARGO_INCREMENTAL
 export CARGO_INCREMENTAL
 endif
 
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
+
 rustflags_neon =
 ifeq (neon,$(MOZ_FPU))
 # Enable neon and disable restriction to 16 FPU registers
