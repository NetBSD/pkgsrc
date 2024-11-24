$NetBSD: patch-src_bootstrap_src_core_build__steps_dist.rs,v 1.1 2024/11/24 16:13:43 he Exp $

Backport https://github.com/rust-lang/rust/pull/130110/
"make dist vendoring configurable"

--- src/bootstrap/src/core/build_steps/dist.rs.orig	2024-09-22 17:31:33.331112310 +0000
+++ src/bootstrap/src/core/build_steps/dist.rs
@@ -1009,11 +1009,7 @@ impl Step for PlainSourceTarball {
         write_git_info(builder.rust_info().info(), plain_dst_src);
         write_git_info(builder.cargo_info.info(), &plain_dst_src.join("./src/tools/cargo"));
 
-        // If we're building from git or tarball sources, we need to vendor
-        // a complete distribution.
-        if builder.rust_info().is_managed_git_subrepository()
-            || builder.rust_info().is_from_tarball()
-        {
+        if builder.config.dist_vendor {
             // FIXME: This code looks _very_ similar to what we have in `src/core/build_steps/vendor.rs`
             // perhaps it should be removed in favor of making `dist` perform the `vendor` step?
 
