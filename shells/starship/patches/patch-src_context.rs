$NetBSD: patch-src_context.rs,v 1.1 2022/01/14 15:38:07 pin Exp $

Allow compilation without battery feature
See, starship PR 3435

--- src/context.rs.orig	2022-01-14 12:25:45.000000000 +0000
+++ src/context.rs
@@ -15,6 +15,7 @@ use std::env;
 use std::ffi::{OsStr, OsString};
 use std::fmt::Debug;
 use std::fs;
+use std::marker::PhantomData;
 use std::num::ParseIntError;
 use std::path::{Path, PathBuf};
 use std::string::String;
@@ -70,6 +71,9 @@ pub struct Context<'a> {
 
     /// Starship root config
     pub root_config: StarshipRootConfig,
+
+    /// Avoid issues with unused lifetimes when features are disabled
+    _marker: PhantomData<&'a ()>,
 }
 
 impl<'a> Context<'a> {
@@ -149,6 +153,7 @@ impl<'a> Context<'a> {
             #[cfg(feature = "battery")]
             battery_info_provider: &crate::modules::BatteryInfoProviderImpl,
             root_config,
+            _marker: PhantomData,
         }
     }
 
