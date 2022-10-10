$NetBSD: patch-src_bootstrap_builder.rs,v 1.23 2022/10/10 20:34:15 he Exp $

Do not install 'src'.
Use @PREFIX@, not $ORIGIN in rpath.
Fix RPATH for pkgsrc.
Pull in upstream commit 5122bb55 to fix install on illumos.

--- src/bootstrap/builder.rs.orig	2022-06-27 13:37:07.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -735,7 +735,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
             Kind::Run => describe!(run::ExpandYamlAnchors, run::BuildManifest, run::BumpStage0),
@@ -1699,7 +1698,7 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
@@ -1760,7 +1759,8 @@ impl<'a> Builder<'a> {
             let needs_unstable_opts = target.contains("linux")
                 || target.contains("windows")
                 || target.contains("bsd")
-                || target.contains("dragonfly");
+                || target.contains("dragonfly")
+                || target.contains("illumos");
 
             if needs_unstable_opts {
                 rustflags.arg("-Zunstable-options");
