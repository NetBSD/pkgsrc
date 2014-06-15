$NetBSD: patch-third__party_protobuf_post__process__dist.sh,v 1.1 2014/06/15 13:08:34 ryoon Exp $

--- third_party/protobuf/post_process_dist.sh.orig	2014-05-21 10:51:38.000000000 +0000
+++ third_party/protobuf/post_process_dist.sh
@@ -15,7 +15,7 @@
 #    non-testdata .txt files are converted to Windows-style line endings.
 # 5) Cleans up after itself.
 
-if [ "$1" == "" ]; then
+if [ "$1" = "" ]; then
   echo "USAGE:  $1 DISTFILE" >&2
   exit 1
 fi
