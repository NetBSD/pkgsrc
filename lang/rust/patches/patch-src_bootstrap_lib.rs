$NetBSD: patch-src_bootstrap_lib.rs,v 1.12 2022/02/07 09:16:05 tnn Exp $

Don't filter out optimization flags.
FreeBSD has a particular C++ runtime library name

With rust-1.57.0 as bootstrap we get this:
error: field is never read: `id`
   --> src/bootstrap/lib.rs:280:5
    |
280 |     id: String,
    |     ^^^^^^^^^^
    |
    = note: `-D dead-code` implied by `-D warnings`

--- src/bootstrap/lib.rs.orig	2021-11-29 19:27:11.000000000 +0000
+++ src/bootstrap/lib.rs
@@ -273,6 +273,7 @@ pub struct Build {
         RefCell<HashMap<TargetSelection, HashMap<String, (&'static str, PathBuf, Vec<String>)>>>,
 }
 
+#[allow(dead_code)]
 #[derive(Debug)]
 struct Crate {
     name: Interned<String>,
@@ -954,14 +955,13 @@ impl Build {
             .args()
             .iter()
             .map(|s| s.to_string_lossy().into_owned())
-            .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
             .collect::<Vec<String>>();
 
         // If we're compiling on macOS then we add a few unconditional flags
         // indicating that we want libc++ (more filled out than libstdc++) and
         // we want to compile for 10.7. This way we can ensure that
         // LLVM/etc are all properly compiled.
-        if target.contains("apple-darwin") {
+        if target.contains("apple-darwin") || target.contains("freebsd") {
             base.push("-stdlib=libc++".into());
         }
 
