$NetBSD: patch-src_cargo__ops_temp__project.rs,v 1.1 2024/12/02 20:26:21 adam Exp $

Fix build for Rust 1.80.0 and newer.
https://github.com/kbknapp/cargo-outdated/pull/403

--- src/cargo_ops/temp_project.rs.orig	2024-12-02 10:18:36.283587713 +0000
+++ src/cargo_ops/temp_project.rs
@@ -16,7 +16,7 @@ use cargo::{
         config::SourceConfigMap,
         source::{QueryKind, Source},
     },
-    util::{cache_lock::CacheLockMode, network::PollExt, CargoResult, Config},
+    util::{cache_lock::CacheLockMode, context::GlobalContext, network::PollExt, CargoResult},
 };
 use semver::{Version, VersionReq};
 use tempfile::{Builder, TempDir};
@@ -30,7 +30,7 @@ pub struct TempProject<'tmp> {
     pub workspace: Rc<RefCell<Option<Workspace<'tmp>>>>,
     pub temp_dir: TempDir,
     manifest_paths: Vec<PathBuf>,
-    config: Config,
+    context: GlobalContext,
     relative_manifest: String,
     options: &'tmp Options,
     is_workspace_project: bool,
@@ -156,24 +156,24 @@ impl<'tmp> TempProject<'tmp> {
         }
 
         let relative_manifest = String::from(&orig_manifest[workspace_root_str.len() + 1..]);
-        let config = Self::generate_config(temp_dir.path(), &relative_manifest, options)?;
+        let context = Self::generate_context(temp_dir.path(), &relative_manifest, options)?;
 
         Ok(TempProject {
             workspace: Rc::new(RefCell::new(None)),
             temp_dir,
             manifest_paths: tmp_manifest_paths,
-            config,
+            context,
             relative_manifest,
             options,
             is_workspace_project: orig_workspace.workspace_mode,
         })
     }
 
-    fn generate_config(
+    fn generate_context(
         root: &Path,
         relative_manifest: &str,
         options: &Options,
-    ) -> CargoResult<Config> {
+    ) -> CargoResult<GlobalContext> {
         let shell = ::cargo::core::Shell::new();
         let cwd = env::current_dir()
             .with_context(|| "Cargo couldn't get the current directory of the process")?;
@@ -191,8 +191,8 @@ impl<'tmp> TempProject<'tmp> {
         // if it is, set it in the configure options
         let cargo_home_path = std::env::var_os("CARGO_HOME").map(std::path::PathBuf::from);
 
-        let mut config = Config::new(shell, cwd, homedir);
-        config.configure(
+        let mut context = GlobalContext::new(shell, cwd, homedir);
+        context.configure(
             0,
             options.verbose == 0,
             Some(&options.color.to_string().to_ascii_lowercase()),
@@ -203,7 +203,7 @@ impl<'tmp> TempProject<'tmp> {
             &[],
             &[],
         )?;
-        Ok(config)
+        Ok(context)
     }
 
     /// Run `cargo update` against the temporary project
@@ -212,7 +212,7 @@ impl<'tmp> TempProject<'tmp> {
             recursive: false,
             precise: None,
             to_update: Vec::new(),
-            config: &self.config,
+            gctx: &self.context,
             dry_run: false,
             workspace: self.is_workspace_project,
         };
@@ -321,7 +321,7 @@ impl<'tmp> TempProject<'tmp> {
         let root_manifest = self.temp_dir.path().join(&self.relative_manifest);
 
         *self.workspace.borrow_mut() =
-            Some(Workspace::new(Path::new(&root_manifest), &self.config)?);
+            Some(Workspace::new(Path::new(&root_manifest), &self.context)?);
         Ok(())
     }
 
@@ -374,7 +374,7 @@ impl<'tmp> TempProject<'tmp> {
 
         let root_manifest = self.temp_dir.path().join(&self.relative_manifest);
         *self.workspace.borrow_mut() =
-            Some(Workspace::new(Path::new(&root_manifest), &self.config)?);
+            Some(Workspace::new(Path::new(&root_manifest), &self.context)?);
         Ok(())
     }
 
@@ -390,9 +390,9 @@ impl<'tmp> TempProject<'tmp> {
         let version = package_id.version();
         let source_id = package_id.source_id().with_locked_precise();
         let query_result = {
-            let ws_config = workspace.workspace.config();
-            let _lock = ws_config.acquire_package_cache_lock(CacheLockMode::DownloadExclusive)?;
-            let source_config = SourceConfigMap::new(ws_config)?;
+            let ws_context = workspace.workspace.gctx();
+            let _lock = ws_context.acquire_package_cache_lock(CacheLockMode::DownloadExclusive)?;
+            let source_config = SourceConfigMap::new(ws_context)?;
             let mut source = source_config.load(source_id, &HashSet::new())?;
             if !source_id.is_crates_io() {
                 source.invalidate_cache();
@@ -401,7 +401,10 @@ impl<'tmp> TempProject<'tmp> {
             let dependency = Dependency::parse(name, None, source_id)?;
             let mut query_result = source
                 .query_vec(&dependency, QueryKind::Exact)?
-                .expect("Source should be ready");
+                .expect("Source should be ready")
+                .into_iter()
+                .map(|index_summary| index_summary.into_summary())
+                .collect::<Vec<_>>();
             query_result.sort_by(|a, b| b.version().cmp(a.version()));
             query_result
         };
@@ -710,14 +713,14 @@ impl<'tmp> TempProject<'tmp> {
     }
 
     fn warn<T: ::std::fmt::Display>(&self, message: T) -> CargoResult<()> {
-        let original_verbosity = self.config.shell().verbosity();
-        self.config.shell().set_verbosity(if self.options.quiet {
+        let original_verbosity = self.context.shell().verbosity();
+        self.context.shell().set_verbosity(if self.options.quiet {
             Verbosity::Quiet
         } else {
             Verbosity::Normal
         });
-        self.config.shell().warn(message)?;
-        self.config.shell().set_verbosity(original_verbosity);
+        self.context.shell().warn(message)?;
+        self.context.shell().set_verbosity(original_verbosity);
         Ok(())
     }
 }
