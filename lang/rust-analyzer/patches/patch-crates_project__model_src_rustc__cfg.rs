$NetBSD: patch-crates_project__model_src_rustc__cfg.rs,v 1.1 2022/02/14 08:27:17 adam Exp $

Use pre-1.58.0 format strings.

--- crates/project_model/src/rustc_cfg.rs.orig	2022-02-14 08:19:52.000000000 +0000
+++ crates/project_model/src/rustc_cfg.rs
@@ -29,7 +29,7 @@ pub(crate) fn get(cargo_toml: Option<&Ma
             );
             res.extend(rustc_cfgs.lines().filter_map(|it| it.parse().ok()));
         }
-        Err(e) => tracing::error!("failed to get rustc cfgs: {e:?}"),
+        Err(e) => tracing::error!("failed to get rustc cfgs: {:?}", e),
     }
 
     res
@@ -47,7 +47,7 @@ fn get_rust_cfgs(cargo_toml: Option<&Man
         }
         match utf8_stdout(cargo_config) {
             Ok(it) => return Ok(it),
-            Err(e) => tracing::debug!("{e:?}: falling back to querying rustc for cfgs"),
+            Err(e) => tracing::debug!("{:?}: falling back to querying rustc for cfgs", e),
         }
     }
     // using unstable cargo features failed, fall back to using plain rustc
