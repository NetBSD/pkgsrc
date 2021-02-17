$NetBSD: patch-third__party_protobuf_post__process__dist.sh,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* appease pkglint

--- third_party/protobuf/post_process_dist.sh.orig	2017-11-02 13:35:43.000000000 +0000
+++ third_party/protobuf/post_process_dist.sh
@@ -15,7 +15,7 @@
 #    non-testdata .txt files are converted to Windows-style line endings.
 # 5) Cleans up after itself.
 
-if [ "$1" == "" ]; then
+if [ "$1" = "" ]; then
   echo "USAGE:  $0 DISTFILE" >&2
   exit 1
 fi
