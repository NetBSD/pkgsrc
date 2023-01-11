$NetBSD: patch-pgx_pgx-pg-sys_build.rs,v 1.2 2023/01/11 03:33:46 tnn Exp $

Fix include directories for bindgen.

--- ../vendor/pgx-pg-sys-0.6.1/build.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/pgx-pg-sys-0.6.1/build.rs
@@ -562,10 +562,10 @@ struct StructDescriptor<'a> {
 fn run_bindgen(pg_config: &PgConfig, include_h: &PathBuf) -> eyre::Result<syn::File> {
     let major_version = pg_config.major_version()?;
     eprintln!("Generating bindings for pg{}", major_version);
-    let includedir_server = pg_config.includedir_server()?;
     let bindings = bindgen::Builder::default()
         .header(include_h.display().to_string())
-        .clang_arg(&format!("-I{}", includedir_server.display()))
+        .clang_arg("-I@BUILDLINK_DIR@/include/postgresql/server")
+        .clang_arg("-I@BUILDLINK_DIR@/include")
         .clang_args(&extra_bindgen_clang_args(pg_config)?)
         .parse_callbacks(Box::new(PgxOverrides::default()))
         .blocklist_type("(Nullable)?Datum") // manually wrapping datum types for correctness
