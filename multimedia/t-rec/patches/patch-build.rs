$NetBSD: patch-build.rs,v 1.1 2022/10/06 07:43:28 pin Exp $

Allow building on NetBSD

--- build.rs.orig	2022-10-04 22:21:07.000000000 +0000
+++ build.rs
@@ -1,7 +1,10 @@
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 fn main() {
     println!("cargo:rustc-link-lib=X11");
 }
 
-#[cfg(not(target_os = "linux"))]
+#[cfg(all(
+    not(target_os = "linux"),
+    not(target_os = "netbsd"),
+))]
 fn main() {}
