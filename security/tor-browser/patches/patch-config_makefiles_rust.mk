$NetBSD: patch-config_makefiles_rust.mk,v 1.2.2.2 2020/08/28 19:05:42 bsiegert Exp $

NetBSD<10 doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

--- config/makefiles/rust.mk.orig	2020-08-18 09:41:09.000000000 +0000
+++ config/makefiles/rust.mk
@@ -59,6 +59,9 @@ endif
 ifdef CARGO_INCREMENTAL
 export CARGO_INCREMENTAL
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 rustflags_neon =
 ifeq (neon,$(MOZ_FPU))
