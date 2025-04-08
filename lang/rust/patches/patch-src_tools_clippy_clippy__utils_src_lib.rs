$NetBSD: patch-src_tools_clippy_clippy__utils_src_lib.rs,v 1.1 2025/04/08 09:31:07 wiz Exp $

Following on from https://github.com/rust-lang/rust/issues/137630
apply patch gracefully supplied in
https://github.com/beetrees/rust/commit/21f8bda79b2904c827b9d8d769a1307acfd855a1
.patch

Fixes cross-build for 32-bit mips on NetBSD which
does not (yet?) support the f16 data type.

--- src/tools/clippy/clippy_utils/src/lib.rs.orig	2025-02-17 18:17:27.000000000 +0000
+++ src/tools/clippy/clippy_utils/src/lib.rs
@@ -1,7 +1,5 @@
 #![feature(array_chunks)]
 #![feature(box_patterns)]
-#![feature(f128)]
-#![feature(f16)]
 #![feature(if_let_guard)]
 #![feature(macro_metavar_expr_concat)]
 #![feature(let_chains)]
