$NetBSD: patch-tools_cpp_lib__cc__configure.bzl,v 1.1 2024/01/01 12:01:00 ryoon Exp $

--- tools/cpp/lib_cc_configure.bzl.orig	2023-11-28 16:25:10.088639234 +0000
+++ tools/cpp/lib_cc_configure.bzl
@@ -192,6 +192,8 @@ def get_cpu_value(repository_ctx):
         return "darwin" + ("_arm64" if arch == "aarch64" else "")
     if os_name.find("freebsd") != -1:
         return "freebsd"
+    if os_name.find("netbsd") != -1:
+        return "netbsd"
     if os_name.find("openbsd") != -1:
         return "openbsd"
     if os_name.find("windows") != -1:
