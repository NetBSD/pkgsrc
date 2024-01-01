$NetBSD: patch-third__party_zstd-jni_zstd-jni.BUILD,v 1.1 2024/01/01 12:01:00 ryoon Exp $

--- third_party/zstd-jni/zstd-jni.BUILD.orig	2023-11-28 16:52:47.128150508 +0000
+++ third_party/zstd-jni/zstd-jni.BUILD
@@ -3,6 +3,7 @@ genrule(
     srcs = select({
         "@bazel_tools//src/conditions:darwin": ["@bazel_tools//tools/jdk:jni_md_header-darwin"],
         "@bazel_tools//src/conditions:freebsd": ["@bazel_tools//tools/jdk:jni_md_header-freebsd"],
+        "@bazel_tools//src/conditions:netbsd": ["@bazel_tools//tools/jdk:jni_md_header-netbsd"],
         "@bazel_tools//src/conditions:openbsd": ["@bazel_tools//tools/jdk:jni_md_header-openbsd"],
         "@bazel_tools//src/conditions:windows": ["@bazel_tools//tools/jdk:jni_md_header-windows"],
         "//conditions:default": ["@bazel_tools//tools/jdk:jni_md_header-linux"],
