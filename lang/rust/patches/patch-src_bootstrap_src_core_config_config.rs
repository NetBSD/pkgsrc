$NetBSD: patch-src_bootstrap_src_core_config_config.rs,v 1.1 2024/11/24 16:13:43 he Exp $

Backport
https://github.com/rust-lang/rust/pull/130110/
"make dist vendoring configurable"

--- src/bootstrap/src/core/config/config.rs.orig	2024-09-22 17:38:21.382609357 +0000
+++ src/bootstrap/src/core/config/config.rs
@@ -300,6 +300,7 @@ pub struct Config {
     pub dist_compression_formats: Option<Vec<String>>,
     pub dist_compression_profile: String,
     pub dist_include_mingw_linker: bool,
+    pub dist_vendor: bool,
 
     // libstd features
     pub backtrace: bool, // support for RUST_BACKTRACE
@@ -904,6 +905,7 @@ define_config! {
         compression_formats: Option<Vec<String>> = "compression-formats",
         compression_profile: Option<String> = "compression-profile",
         include_mingw_linker: Option<bool> = "include-mingw-linker",
+        vendor: Option<bool> = "vendor",
     }
 }
 
@@ -1965,13 +1967,19 @@ impl Config {
                 compression_formats,
                 compression_profile,
                 include_mingw_linker,
+                vendor,
             } = dist;
             config.dist_sign_folder = sign_folder.map(PathBuf::from);
             config.dist_upload_addr = upload_addr;
             config.dist_compression_formats = compression_formats;
             set(&mut config.dist_compression_profile, compression_profile);
             set(&mut config.rust_dist_src, src_tarball);
-            set(&mut config.dist_include_mingw_linker, include_mingw_linker)
+            set(&mut config.dist_include_mingw_linker, include_mingw_linker);
+            config.dist_vendor = vendor.unwrap_or_else(|| {
+                // If we're building from git or tarball sources, enable it by default.
+                 config.rust_info.is_managed_git_subrepository()
+                     || config.rust_info.is_from_tarball()
+             });
         }
 
         if let Some(r) = rustfmt {
