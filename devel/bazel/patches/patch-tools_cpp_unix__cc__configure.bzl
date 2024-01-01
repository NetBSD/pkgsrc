$NetBSD: patch-tools_cpp_unix__cc__configure.bzl,v 1.1 2024/01/01 12:01:00 ryoon Exp $

--- tools/cpp/unix_cc_configure.bzl.orig	2023-11-28 16:29:01.387093015 +0000
+++ tools/cpp/unix_cc_configure.bzl
@@ -344,7 +344,7 @@ def configure_unix_toolchain(repository_
 
     repository_ctx.file("tools/cpp/empty.cc", "int main() {}")
     darwin = cpu_value.startswith("darwin")
-    bsd = cpu_value == "freebsd" or cpu_value == "openbsd"
+    bsd = cpu_value == "freebsd" or cpu_value == "netbsd" or cpu_value == "openbsd"
 
     cc = find_cc(repository_ctx, overriden_tools)
     is_clang = _is_clang(repository_ctx, cc)
