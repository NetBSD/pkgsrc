$NetBSD: patch-nix.rs,v 1.1 2025/12/13 17:47:21 vins Exp $

Include definitions for resource operations on SunOS. 

--- nix-0.30.1/src/sys/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ nix-0.30.1/src/sys/mod.rs
@@ -96,7 +96,6 @@ feature! {
 #[cfg(not(any(
     target_os = "redox",
     target_os = "fuchsia",
-    solarish,
     target_os = "haiku"
 )))]
 feature! {

--- nix-0.30.1/src/sys/resource.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ nix-0.30.1/src/sys/resource.rs
@@ -19,6 +19,7 @@ cfg_if! {
         bsd,
         target_os = "android",
         target_os = "aix",
+        target_os = "illumos",
         all(target_os = "linux", not(target_env = "gnu")),
         target_os = "cygwin"
     ))]{
@@ -50,6 +51,7 @@ libc_enum! {
             bsd,
             target_os = "android",
             target_os = "aix",
+            target_os = "illumos",
             all(target_os = "linux", not(any(target_env = "gnu", target_env = "uclibc"))),
             target_os = "cygwin"
         ), repr(i32))]
