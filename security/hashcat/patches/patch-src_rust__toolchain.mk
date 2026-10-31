$NetBSD: patch-src_rust__toolchain.mk,v 1.1 2026/10/31 17:12:20 adam Exp $

Assume cargo version is supported as "sort -V" is not portable.

--- src/rust_toolchain.mk.orig	2026-10-31 16:47:41.743318717 +0000
+++ src/rust_toolchain.mk
@@ -38,7 +38,7 @@ endif
 # when a version was read, because an empty second line sorts fine and would answer true.
 
 ifeq ($(CARGO_PRESENT),true)
-CARGO_RECENT     := $(shell printf '%s\n%s\n' '$(RUST_MIN_VERSION)' '$(CARGO_VERSION)' | sort -V -C && echo true || echo false)
+CARGO_RECENT     := true
 endif
 
 # One reason, so every target that has to be skipped says the same thing and says the right thing.
