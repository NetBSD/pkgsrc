$NetBSD: patch-tools_cpp_cc__configure.bzl,v 1.1 2024/01/01 12:01:00 ryoon Exp $

--- tools/cpp/cc_configure.bzl.orig	2023-11-28 16:35:29.548083456 +0000
+++ tools/cpp/cc_configure.bzl
@@ -102,7 +102,7 @@ def cc_autoconf_impl(repository_ctx, ove
         repository_ctx.template("BUILD", paths["@bazel_tools//tools/cpp:BUILD.empty.tpl"], {
             "%{cpu}": get_cpu_value(repository_ctx),
         })
-    elif cpu_value == "freebsd" or cpu_value == "openbsd":
+    elif cpu_value == "freebsd" or cpu_value == "netbsd" or cpu_value == "openbsd":
         paths = resolve_labels(repository_ctx, [
             "@bazel_tools//tools/cpp:BUILD.static.bsd",
             "@bazel_tools//tools/cpp:bsd_cc_toolchain_config.bzl",
