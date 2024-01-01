$NetBSD: patch-distdir__deps.bzl,v 1.1 2024/01/01 12:00:58 ryoon Exp $

--- distdir_deps.bzl.orig	1979-12-31 15:00:00.000000000 +0000
+++ distdir_deps.bzl
@@ -123,6 +123,7 @@ DIST_DEPS = {
         "patches": [
             "//third_party/grpc:grpc_1.47.0.patch",
             "//third_party/grpc:grpc_1.47.0.win_arm64.patch",
+            "//third_party/grpc:netbsd-config.patch",
         ],
         "used_in": [
             "additional_distfiles",
@@ -240,6 +241,9 @@ DIST_DEPS = {
             "test_WORKSPACE_files",
         ],
         "strip_prefix": "abseil-cpp-20211102.0",
+        "patches": [
+            "//third_party:abseil-cpp/netbsd-sunos.patch",
+        ],
     },
     "zstd-jni": {
         "archive": "v1.5.2-3.zip",
