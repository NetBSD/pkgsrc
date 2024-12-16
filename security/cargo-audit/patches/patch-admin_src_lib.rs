$NetBSD: patch-admin_src_lib.rs,v 1.1 2024/12/16 19:12:17 adam Exp $

Fix building with Rust 1.83.0.
https://github.com/rustsec/rustsec/issues/1297

--- admin/src/lib.rs.orig	2024-12-16 19:08:56.303656276 +0000
+++ admin/src/lib.rs
@@ -2,7 +2,7 @@
 //!
 //! Administrative tool for the RustSec Advisory Database
 
-#![deny(warnings, missing_docs, trivial_casts, unused_qualifications)]
+#![deny(missing_docs, trivial_casts, unused_qualifications)]
 #![forbid(unsafe_code)]
 
 pub mod application;
