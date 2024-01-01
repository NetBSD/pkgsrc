$NetBSD: patch-src_test_shell_bazel_remote_remote__execution__test.sh,v 1.1 2024/01/01 12:00:59 ryoon Exp $

--- src/test/shell/bazel/remote/remote_execution_test.sh.orig	2023-11-28 16:48:56.932298505 +0000
+++ src/test/shell/bazel/remote/remote_execution_test.sh
@@ -197,7 +197,7 @@ EOF
 # TODO(b/211478955): Deflake and re-enable.
 function DISABLED_test_remote_grpc_via_unix_socket_proxy() {
   case "$PLATFORM" in
-  darwin|freebsd|linux|openbsd)
+  darwin|freebsd|linux|openbsd|netbsd)
     ;;
   *)
     return 0
@@ -236,7 +236,7 @@ EOF
 # TODO(b/211478955): Deflake and re-enable.
 function DISABLED_test_remote_grpc_via_unix_socket_direct() {
   case "$PLATFORM" in
-  darwin|freebsd|linux|openbsd)
+  darwin|freebsd|linux|openbsd|netbsd)
     ;;
   *)
     return 0
