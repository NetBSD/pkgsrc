$NetBSD: patch-crates_gettext-maps_build.rs,v 1.1 2025/11/02 18:44:07 vins Exp $

Compatibility fix for SunOS msgfmt(1). 

--- crates/gettext-maps/build.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ crates/gettext-maps/build.rs
@@ -34,22 +34,21 @@ fn embed_localizations(cache_dir: &Path)
     // for the respective language.
     let mut catalogs = phf_codegen::Map::new();
 
-    match Command::new("msgfmt").arg("-h").status() {
+    match Command::new("msgfmt").arg("-h").output() {
         Err(e) if e.kind() == std::io::ErrorKind::NotFound => {
             rsconf::warn!(
-                "Cannot find msgfmt to build gettext message catalogs. Localization will not work."
-            );
-            rsconf::warn!(
-                "If you install it now you need to trigger a rebuild to get localization support."
-            );
-            rsconf::warn!(
-                "One way to achieve that is running `touch po` followed by the build command."
+                "Could not find msgfmt required to build message catalogs. \
+                 Localization will not work. \
+                 If you install gettext now, you need to trigger a rebuild to include localization support. \
+                 For example by running `touch po` followed by the build command."
             );
         }
         Err(e) => {
             panic!("Error when trying to run `msgfmt -h`: {e:?}");
         }
-        Ok(_) => {
+        Ok(output) => {
+            let has_check_format =
+                String::from_utf8_lossy(&output.stdout).contains("--check-format");
             for dir_entry_result in po_dir.read_dir().unwrap() {
                 let dir_entry = dir_entry_result.unwrap();
                 let po_file_path = dir_entry.path();
@@ -91,13 +90,32 @@ fn embed_localizations(cache_dir: &Path)
                 // Generate the map file.
 
                 // Try to create new MO data and load it into `mo_data`.
-                let output = Command::new("msgfmt")
-                    .arg("--check-format")
-                    .arg("--output-file=-")
+                let mut tmp_mo_file = None;
+                let output = {
+                    let mut cmd = &mut Command::new("msgfmt");
+                    if has_check_format {
+                        cmd = cmd.arg("--check-format");
+                    } else {
+                        tmp_mo_file = Some(cache_dir.join("messages.mo"));
+                    };
+                    cmd.arg(format!(
+                        "--output-file={}",
+                        tmp_mo_file
+                            .as_ref()
+                            .map_or("-", |path| path.to_str().unwrap())
+                    ))
                     .arg(&po_file_path)
                     .output()
-                    .unwrap();
-                let mo_data = output.stdout;
+                    .unwrap()
+                };
+                if !output.status.success() {
+                    panic!(
+                        "msgfmt failed:\n{}",
+                        String::from_utf8(output.stderr).unwrap()
+                    );
+                }
+                let mo_data =
+                    tmp_mo_file.map_or(output.stdout, |path| std::fs::read(path).unwrap());
 
                 // Extract map from MO data.
                 let language_localizations = parse_mo_file(&mo_data).unwrap();
