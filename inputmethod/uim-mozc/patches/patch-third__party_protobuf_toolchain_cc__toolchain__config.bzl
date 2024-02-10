$NetBSD: patch-third__party_protobuf_toolchain_cc__toolchain__config.bzl,v 1.1 2024/02/10 02:20:19 ryoon Exp $

--- third_party/protobuf/toolchain/cc_toolchain_config.bzl.orig	2023-12-13 11:45:04.226274104 +0000
+++ third_party/protobuf/toolchain/cc_toolchain_config.bzl
@@ -206,7 +206,7 @@ def _impl(ctx):
         cxx_builtin_include_directories = [
             ctx.attr.sysroot,
             ctx.attr.extra_include,
-            "/usr/local/include",
+            "@PREFIX@/include",
             "/usr/local/lib/clang",
         ],
         features = features,
