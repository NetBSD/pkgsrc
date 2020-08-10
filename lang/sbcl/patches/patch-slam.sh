$NetBSD: patch-slam.sh,v 1.2 2020/08/10 23:18:52 rjs Exp $

--- slam.sh.orig	2020-07-30 19:30:02.000000000 +0000
+++ slam.sh
@@ -65,7 +65,7 @@ set -e
 #######################################################################
 
 warm_option=""
-if [ "$1" == --load -o "$1" == --load-with-sb-devel ]; then
+if [ "$1" = --load -o "$1" = --load-with-sb-devel ]; then
     warm_option="$1"
     shift
 fi
