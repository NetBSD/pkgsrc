$NetBSD: patch-src_librustc__llvm_build.rs,v 1.2 2019/03/03 09:16:21 he Exp $

fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

--- src/librustc_llvm/build.rs.orig	2018-12-18 23:11:17.000000000 +0000
+++ src/librustc_llvm/build.rs
@@ -244,8 +244,14 @@ fn main() {
     } else if target.contains("freebsd") {
         "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
-        // NetBSD uses a separate library when relocation is required
-        "stdc++_pic"
+	// NetBSD uses a separate library when relocation is required
+	if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+	    "c++_pic"
+	} else {
+	    "stdc++_pic"
+	}
+    } else if env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+	"c++"
     } else if llvm_use_libcxx.is_some() {
         "c++"
     } else {
