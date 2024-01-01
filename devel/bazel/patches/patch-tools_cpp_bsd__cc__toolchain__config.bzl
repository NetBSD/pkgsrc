$NetBSD: patch-tools_cpp_bsd__cc__toolchain__config.bzl,v 1.1 2024/01/01 12:01:00 ryoon Exp $

* GCC 10.5.0 with -isystem, absolute path and symlink generates unexpected
  .d file when -MD is specified. Bazel would not accept such .d files.

--- tools/cpp/bsd_cc_toolchain_config.bzl.orig	2023-12-05 16:43:07.613565028 +0000
+++ tools/cpp/bsd_cc_toolchain_config.bzl
@@ -56,7 +56,7 @@ all_link_actions = [
 
 def _impl(ctx):
     cpu = ctx.attr.cpu
-    is_bsd = cpu == "freebsd" or cpu == "openbsd"
+    is_bsd = cpu == "freebsd" or cpu == "netbsd" or cpu == "openbsd"
     compiler = "compiler"
     toolchain_identifier = "local_{}".format(cpu) if is_bsd else "stub_armeabi-v7a"
     host_system_name = "local" if is_bsd else "armeabi-v7a"
@@ -241,17 +241,19 @@ def _impl(ctx):
     else:
         features = [supports_dynamic_linker_feature, supports_pic_feature]
 
-    if (is_bsd):
+    if is_bsd and not (cpu == "netbsd"):
         cxx_builtin_include_directories = ["/usr/lib/clang", "/usr/local/include", "/usr/include"]
+    elif (cpu == "netbsd"):
+        cxx_builtin_include_directories = ["@PREFIX@/lib/clang", "@PREFIX@/include", "/usr/include"]
     else:
         cxx_builtin_include_directories = []
 
-    if is_bsd:
+    if is_bsd and not (cpu == "netbsd"):
         tool_paths = [
             tool_path(name = "ar", path = "/usr/bin/ar"),
             tool_path(name = "cpp", path = "/usr/bin/cpp"),
             tool_path(name = "dwp", path = "/usr/bin/dwp"),
-            tool_path(name = "gcc", path = "/usr/bin/clang"),
+            tool_path(name = "gcc", path = "/usr/bin/clang"),
             tool_path(name = "gcov", path = "/usr/bin/gcov"),
             tool_path(name = "ld", path = "/usr/bin/ld"),
             tool_path(name = "nm", path = "/usr/bin/nm"),
@@ -259,6 +261,19 @@ def _impl(ctx):
             tool_path(name = "objdump", path = "/usr/bin/objdump"),
             tool_path(name = "strip", path = "/usr/bin/strip"),
         ]
+    elif (cpu == "netbsd"):
+        tool_paths = [
+            tool_path(name = "ar", path = "/usr/bin/ar"),
+            tool_path(name = "cpp", path = "/usr/bin/cpp"),
+            tool_path(name = "dwp", path = "/usr/bin/dwp"),
+            tool_path(name = "gcc", path = "@PREFIX@/bin/clang"),
+            tool_path(name = "gcov", path = "/usr/bin/gcov"),
+            tool_path(name = "ld", path = "/usr/bin/ld"),
+            tool_path(name = "nm", path = "/usr/bin/nm"),
+            tool_path(name = "objcopy", path = "/usr/bin/objcopy"),
+            tool_path(name = "objdump", path = "/usr/bin/objdump"),
+            tool_path(name = "strip", path = "/usr/bin/strip"),
+        ]
     else:
         tool_paths = [
             tool_path(name = "ar", path = "/bin/false"),
