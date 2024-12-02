$NetBSD: patch-src_cargo__ops_elaborate__workspace.rs,v 1.1 2024/12/02 20:26:21 adam Exp $

Fix build for Rust 1.80.0 and newer.
https://github.com/kbknapp/cargo-outdated/pull/403

--- src/cargo_ops/elaborate_workspace.rs.orig	2024-12-02 09:51:05.930744940 +0000
+++ src/cargo_ops/elaborate_workspace.rs
@@ -18,7 +18,7 @@ use cargo::{
         Dependency, FeatureValue, Package, PackageId, Workspace,
     },
     ops::{self, Packages},
-    util::{interning::InternedString, CargoResult, Config},
+    util::{context::GlobalContext, interning::InternedString, CargoResult},
 };
 use serde::{Deserialize, Serialize};
 use tabwriter::TabWriter;
@@ -87,7 +87,7 @@ impl<'ela> ElaborateWorkspace<'ela> {
         // The CompileKind, this has no target since it's the temp workspace
         // targets are blank since we don't need to fully build for the targets to get
         // the dependencies
-        let compile_kind = CompileKind::from_requested_targets(workspace.config(), &[])?;
+        let compile_kind = CompileKind::from_requested_targets(workspace.gctx(), &[])?;
         let mut target_data = RustcTargetData::new(workspace, &compile_kind)?;
         let ws_resolve = ops::resolve_ws_with_opts(
             workspace,
@@ -97,8 +97,7 @@ impl<'ela> ElaborateWorkspace<'ela> {
             &specs,
             HasDevUnits::Yes,
             ForceAllTargets::Yes,
-            // TODO: respect MSRV here
-            None,
+            false,
         )?;
         let packages = ws_resolve.pkg_set;
         let resolve = ws_resolve
@@ -215,7 +214,7 @@ impl<'ela> ElaborateWorkspace<'ela> {
         compat: &ElaborateWorkspace<'_>,
         latest: &ElaborateWorkspace<'_>,
         options: &Options,
-        _config: &Config,
+        _context: &GlobalContext,
         root: PackageId,
         skip: &HashSet<String>,
     ) -> CargoResult<()> {
@@ -240,7 +239,7 @@ impl<'ela> ElaborateWorkspace<'ela> {
                 latest: Status::from_versions(pkg.version(), latest_pkg.map(PackageId::version)),
             };
             debug!(
-                _config,
+                _context,
                 "STATUS => PKG: {}; PATH: {:?}; COMPAT: {:?}; LATEST: {:?}; STATUS: {:?}",
                 pkg,
                 path,
