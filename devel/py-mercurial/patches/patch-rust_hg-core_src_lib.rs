$NetBSD: patch-rust_hg-core_src_lib.rs,v 1.1 2020/08/05 06:24:32 wiz Exp $

Allow building rust extension on non-Linux.

--- rust/hg-core/src/lib.rs.orig	2020-08-03 17:43:51.000000000 +0000
+++ rust/hg-core/src/lib.rs
@@ -26,14 +26,6 @@ pub use revlog::*;
 pub mod operations;
 pub mod utils;
 
-// Remove this to see (potential) non-artificial compile failures. MacOS
-// *should* compile, but fail to compile tests for example as of 2020-03-06
-#[cfg(not(target_os = "linux"))]
-compile_error!(
-    "`hg-core` has only been tested on Linux and will most \
-     likely not behave correctly on other platforms."
-);
-
 use crate::utils::hg_path::{HgPathBuf, HgPathError};
 pub use filepatterns::{
     parse_pattern_syntax, read_pattern_file, IgnorePattern,
