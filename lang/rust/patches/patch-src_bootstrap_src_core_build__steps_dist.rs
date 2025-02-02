$NetBSD: patch-src_bootstrap_src_core_build__steps_dist.rs,v 1.2 2025/02/02 13:34:47 he Exp $

Backport https://github.com/rust-lang/rust/pull/130110/
"make dist vendoring configurable"

--- src/bootstrap/src/core/build_steps/dist.rs.orig	2024-10-27 17:40:23.944923750 +0000
+++ src/bootstrap/src/core/build_steps/dist.rs
@@ -1011,11 +1011,7 @@ impl Step for PlainSourceTarball {
         write_git_info(builder.rust_info().info(), plain_dst_src);
         write_git_info(builder.cargo_info.info(), &plain_dst_src.join("./src/tools/cargo"));
 
-        // If we're building from git or tarball sources, we need to vendor
-        // a complete distribution.
-        if builder.rust_info().is_managed_git_subrepository()
-            || builder.rust_info().is_from_tarball()
-        {
+        if builder.config.dist_vendor {
             builder.require_and_update_all_submodules();
 
             // Vendor all Cargo dependencies
