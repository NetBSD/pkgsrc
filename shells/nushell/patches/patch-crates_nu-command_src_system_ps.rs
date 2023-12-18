$NetBSD: patch-crates_nu-command_src_system_ps.rs,v 1.1 2023/12/18 06:44:40 pin Exp $

Don't use procfs on NetBSD.

--- crates/nu-command/src/system/ps.rs.orig	2023-12-17 20:00:37.370631469 +0000
+++ crates/nu-command/src/system/ps.rs
@@ -5,7 +5,8 @@ use itertools::Itertools;
     not(target_os = "macos"),
     not(target_os = "windows"),
     not(target_os = "android"),
-    not(target_os = "ios")
+    not(target_os = "ios"),
+    not(target_os = "netbsd")
 ))]
 use nu_protocol::Span;
 use nu_protocol::{
@@ -19,7 +20,8 @@ use nu_protocol::{
     not(target_os = "macos"),
     not(target_os = "windows"),
     not(target_os = "android"),
-    not(target_os = "ios")
+    not(target_os = "ios"),
+    not(target_os = "netbsd")
 ))]
 use procfs::WithCurrentSystemInfo;
 
@@ -123,7 +125,8 @@ fn run_ps(engine_state: &EngineState, ca
                 not(target_os = "macos"),
                 not(target_os = "windows"),
                 not(target_os = "android"),
-                not(target_os = "ios")
+                not(target_os = "ios"),
+                not(target_os = "netbsd")
             ))]
             {
                 let proc_stat = proc
