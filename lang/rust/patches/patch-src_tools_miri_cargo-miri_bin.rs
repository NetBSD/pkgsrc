$NetBSD: patch-src_tools_miri_cargo-miri_bin.rs,v 1.1 2021/09/10 15:09:32 jperkin Exp $

https://github.com/rust-lang/miri/commit/e5b340017e39dc90e3f9cf9966244faa585321b5

--- src/tools/miri/cargo-miri/bin.rs.orig	2021-07-26 14:43:20.000000000 +0000
+++ src/tools/miri/cargo-miri/bin.rs
@@ -7,6 +7,7 @@ use std::iter::TakeWhile;
 use std::ops::Not;
 use std::path::{Path, PathBuf};
 use std::process::Command;
+use std::fmt::{Write as _};
 
 use serde::{Deserialize, Serialize};
 
