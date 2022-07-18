$NetBSD: patch-pgx_pgx-pg-sys_build.rs,v 1.1 2022/07/18 22:14:25 tnn Exp $

Fix include directories for bindgen.

--- ../pgx/pgx-pg-sys/build.rs.orig	2022-02-14 07:10:25.000000000 +0000
+++ ../pgx/pgx-pg-sys/build.rs
@@ -468,10 +468,10 @@ struct StructDescriptor<'a> {
 fn run_bindgen(pg_config: &PgConfig, include_h: &PathBuf) -> eyre::Result<syn::File> {
     let major_version = pg_config.major_version()?;
     eprintln!("Generating bindings for pg{}", major_version);
-    let includedir_server = pg_config.includedir_server()?;
     let bindings = bindgen::Builder::default()
         .header(include_h.display().to_string())
-        .clang_arg(&format!("-I{}", includedir_server.display()))
+        .clang_arg("-I@BUILDLINK_DIR@/include/postgresql/server")
+        .clang_arg("-I@BUILDLINK_DIR@/include")
         .parse_callbacks(Box::new(IgnoredMacros::default()))
         .blocklist_function("varsize_any") // pgx converts the VARSIZE_ANY macro, so we don't want to also have this function, which is in heaptuple.c
         .blocklist_function("query_tree_walker")
