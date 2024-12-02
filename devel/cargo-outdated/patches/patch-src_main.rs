$NetBSD: patch-src_main.rs,v 1.1 2024/12/02 20:26:21 adam Exp $

Fix build for Rust 1.80.0 and newer.
https://github.com/kbknapp/cargo-outdated/pull/403

--- src/main.rs.orig	2024-02-26 16:23:06.000000000 +0000
+++ src/main.rs
@@ -14,9 +14,10 @@ use std::collections::HashSet;
 use cargo::{
     core::{shell::Verbosity, Workspace},
     util::{
+        context::GlobalContext,
         important_paths::find_root_manifest_for_wd,
         network::http::{http_handle, needs_custom_http_transport},
-        CargoResult, CliError, Config,
+        CargoResult, CliError,
     },
 };
 
@@ -30,7 +31,7 @@ fn main() {
     env_logger::init();
     let options = cli::parse();
 
-    let mut config = match Config::default() {
+    let mut context = match GlobalContext::default() {
         Ok(cfg) => cfg,
         Err(e) => {
             let mut shell = cargo::core::Shell::new();
@@ -44,8 +45,8 @@ fn main() {
     // See cargo-outdated issue #197 and
     // https://github.com/rust-lang/cargo/blob/master/src/bin/cargo/main.rs#L181
     // fn init_git_transports()
-    if let Ok(true) = needs_custom_http_transport(&config) {
-        if let Ok(handle) = http_handle(&config) {
+    if let Ok(true) = needs_custom_http_transport(&context) {
+        if let Ok(handle) = http_handle(&context) {
             unsafe {
                 git2_curl::register(handle);
             }
@@ -53,12 +54,12 @@ fn main() {
     }
 
     let exit_code = options.exit_code;
-    let result = execute(options, &mut config);
+    let result = execute(options, &mut context);
     match result {
         Err(e) => {
-            config.shell().set_verbosity(Verbosity::Normal);
+            context.shell().set_verbosity(Verbosity::Normal);
             let cli_error = CliError::new(e, 1);
-            cargo::exit_with_error(cli_error, &mut config.shell())
+            cargo::exit_with_error(cli_error, &mut context.shell())
         }
         Ok(i) => {
             if i > 0 {
@@ -71,15 +72,15 @@ fn main() {
 }
 
 /// executes the cargo-outdate command with the cargo configuration and options
-pub fn execute(options: Options, config: &mut Config) -> CargoResult<i32> {
+pub fn execute(options: Options, context: &mut GlobalContext) -> CargoResult<i32> {
     // Check if $CARGO_HOME is set before capturing the config environment
     // if it is, set it in the configure options
     let cargo_home_path = std::env::var_os("CARGO_HOME").map(std::path::PathBuf::from);
 
     // enabling nightly features
-    config.nightly_features_allowed = true;
+    context.nightly_features_allowed = true;
 
-    config.configure(
+    context.configure(
         options.verbose.into(),
         options.quiet,
         Some(&options.color.to_string().to_ascii_lowercase()),
@@ -90,34 +91,34 @@ pub fn execute(options: Options, config:
         &[],
         &[],
     )?;
-    debug!(config, format!("options: {options:?}"));
+    debug!(context, format!("options: {options:?}"));
 
-    verbose!(config, "Parsing...", "current workspace");
+    verbose!(context, "Parsing...", "current workspace");
     // the Cargo.toml that we are actually working on
     let mut manifest_abspath: std::path::PathBuf;
     let curr_manifest = if let Some(ref manifest_path) = options.manifest_path {
         manifest_abspath = manifest_path.into();
         if manifest_abspath.is_relative() {
-            verbose!(config, "Resolving...", "absolute path of manifest");
+            verbose!(context, "Resolving...", "absolute path of manifest");
             manifest_abspath = std::env::current_dir()?.join(manifest_path);
         }
         manifest_abspath
     } else {
-        find_root_manifest_for_wd(config.cwd())?
+        find_root_manifest_for_wd(context.cwd())?
     };
-    let curr_workspace = Workspace::new(&curr_manifest, config)?;
-    verbose!(config, "Resolving...", "current workspace");
+    let curr_workspace = Workspace::new(&curr_manifest, context)?;
+    verbose!(context, "Resolving...", "current workspace");
     if options.verbose == 0 {
-        config.shell().set_verbosity(Verbosity::Quiet);
+        context.shell().set_verbosity(Verbosity::Quiet);
     }
     let ela_curr = ElaborateWorkspace::from_workspace(&curr_workspace, &options)?;
     if options.verbose > 0 {
-        config.shell().set_verbosity(Verbosity::Verbose);
+        context.shell().set_verbosity(Verbosity::Verbose);
     } else {
-        config.shell().set_verbosity(Verbosity::Normal);
+        context.shell().set_verbosity(Verbosity::Normal);
     }
 
-    verbose!(config, "Parsing...", "compat workspace");
+    verbose!(context, "Parsing...", "compat workspace");
     let mut skipped = HashSet::new();
     let compat_proj =
         TempProject::from_workspace(&ela_curr, &curr_manifest.to_string_lossy(), &options)?;
@@ -127,9 +128,9 @@ pub fn execute(options: Options, config:
         &ela_curr,
         &mut skipped,
     )?;
-    verbose!(config, "Updating...", "compat workspace");
+    verbose!(context, "Updating...", "compat workspace");
     compat_proj.cargo_update()?;
-    verbose!(config, "Resolving...", "compat workspace");
+    verbose!(context, "Resolving...", "compat workspace");
     let compat_workspace = compat_proj.workspace.borrow();
     let ela_compat = ElaborateWorkspace::from_workspace(
         compat_workspace
@@ -138,7 +139,7 @@ pub fn execute(options: Options, config:
         &options,
     )?;
 
-    verbose!(config, "Parsing...", "latest workspace");
+    verbose!(context, "Parsing...", "latest workspace");
     let latest_proj =
         TempProject::from_workspace(&ela_curr, &curr_manifest.to_string_lossy(), &options)?;
     latest_proj.write_manifest_latest(
@@ -147,9 +148,9 @@ pub fn execute(options: Options, config:
         &ela_curr,
         &mut skipped,
     )?;
-    verbose!(config, "Updating...", "latest workspace");
+    verbose!(context, "Updating...", "latest workspace");
     latest_proj.cargo_update()?;
-    verbose!(config, "Resolving...", "latest workspace");
+    verbose!(context, "Resolving...", "latest workspace");
     let latest_workspace = latest_proj.workspace.borrow();
     let ela_latest = ElaborateWorkspace::from_workspace(
         latest_workspace
@@ -161,8 +162,8 @@ pub fn execute(options: Options, config:
     if ela_curr.workspace_mode {
         let mut sum = 0;
         match options.format {
-            Format::List => verbose!(config, "Printing...", "Package status in list format"),
-            Format::Json => verbose!(config, "Printing...", "Package status in json format"),
+            Format::List => verbose!(context, "Printing...", "Package status in list format"),
+            Format::Json => verbose!(context, "Printing...", "Package status in json format"),
         }
 
         for member in ela_curr.workspace.members() {
@@ -170,7 +171,7 @@ pub fn execute(options: Options, config:
                 &ela_compat,
                 &ela_latest,
                 &options,
-                config,
+                context,
                 member.package_id(),
                 &skipped,
             )?;
@@ -188,10 +189,10 @@ pub fn execute(options: Options, config:
         }
         Ok(sum)
     } else {
-        verbose!(config, "Resolving...", "package status");
+        verbose!(context, "Resolving...", "package status");
         let root = ela_curr.determine_root(&options)?;
-        ela_curr.resolve_status(&ela_compat, &ela_latest, &options, config, root, &skipped)?;
-        verbose!(config, "Printing...", "list format");
+        ela_curr.resolve_status(&ela_compat, &ela_latest, &options, context, root, &skipped)?;
+        verbose!(context, "Printing...", "list format");
         let mut count = 0;
 
         match options.format {
