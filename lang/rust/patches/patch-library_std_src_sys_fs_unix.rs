$NetBSD: patch-library_std_src_sys_fs_unix.rs,v 1.2 2026/01/13 20:48:23 wiz Exp $

Support flock() on illumos.

--- library/std/src/sys/fs/unix.rs.orig	2025-11-06 19:54:02.066156844 +0000
+++ library/std/src/sys/fs/unix.rs
@@ -1282,6 +1282,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1305,6 +1306,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1319,6 +1321,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1342,6 +1345,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1356,6 +1360,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1395,6 +1400,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1412,6 +1418,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1451,6 +1458,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1468,6 +1476,7 @@ impl File {
     #[cfg(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
@@ -1491,6 +1500,7 @@ impl File {
     #[cfg(not(any(
         target_os = "freebsd",
         target_os = "fuchsia",
+        target_os = "illumos",
         target_os = "linux",
         target_os = "netbsd",
         target_os = "openbsd",
