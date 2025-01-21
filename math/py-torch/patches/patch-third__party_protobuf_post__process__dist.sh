$NetBSD: patch-third__party_protobuf_post__process__dist.sh,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Fix POSIX shell portability issue.

--- third_party/protobuf/post_process_dist.sh.orig	2025-01-17 09:45:58.965296423 +0000
+++ third_party/protobuf/post_process_dist.sh
@@ -15,7 +15,7 @@
 #    non-testdata .txt files are converted to Windows-style line endings.
 # 5) Cleans up after itself.
 
-if [ "$1" == "" ]; then
+if [ "$1" = "" ]; then
   echo "USAGE:  $0 DISTFILE" >&2
   exit 1
 fi
