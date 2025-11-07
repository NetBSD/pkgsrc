$NetBSD: patch-library_std_src_sys_fs_unix.rs,v 1.1 2025/11/07 09:40:55 jperkin Exp $

Support flock() on illumos.

--- library/std/src/sys/fs/unix.rs.orig	2025-11-06 15:59:46.718564834 +0000
+++ library/std/src/sys/fs/unix.rs
@@ -1261,6 +1261,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1274,6 +1275,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1286,6 +1288,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1299,6 +1302,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1311,6 +1315,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1332,6 +1337,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1347,6 +1353,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1368,6 +1375,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1383,6 +1391,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1396,6 +1405,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
