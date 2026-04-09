$NetBSD: patch-src_main.rs,v 1.1 2026/04/09 07:39:47 wiz Exp $

Fix build with rust 1.94.
https://github.com/ulyssa/iamb/pull/599

--- src/main.rs.orig	2026-01-20 00:22:41.000000000 +0000
+++ src/main.rs
@@ -11,6 +11,7 @@
 //!
 //! Most rendering logic lives under the [windows] module, but [Matrix messages][message] have
 //! their own module.
+#![recursion_limit = "256"]
 #![allow(clippy::manual_range_contains)]
 #![allow(clippy::needless_return)]
 #![allow(clippy::result_large_err)]
