$NetBSD: patch-src_tools_cargo_src_bin_cargo_commands_help.rs,v 1.2 2026/05/07 13:16:15 wiz Exp $

NetBSD's man(1) command only accepts ./*.[0-9] as man pages.
https://github.com/rust-lang/rust/issues/155548

--- src/tools/cargo/src/bin/cargo/commands/help.rs.orig	2026-04-14 19:55:32.000000000 +0000
+++ src/tools/cargo/src/bin/cargo/commands/help.rs
@@ -125,7 +125,11 @@ fn write_and_spawn(name: &str, contents: &[u8], comman
 /// display it.
 fn write_and_spawn(name: &str, contents: &[u8], command: &str) -> CargoResult<()> {
     let prefix = format!("cargo-{}.", name);
-    let mut tmp = tempfile::Builder::new().prefix(&prefix).tempfile()?;
+    let suffix = if command == "man" { ".1" } else { "" };
+    let mut tmp = tempfile::Builder::new()
+        .prefix(&prefix)
+        .suffix(suffix)
+        .tempfile()?;
     let f = tmp.as_file_mut();
     f.write_all(contents)?;
     f.flush()?;
