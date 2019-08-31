$NetBSD: patch-slam.sh,v 1.1 2019/08/31 20:20:42 rjs Exp $

--- slam.sh.orig	2019-08-31 19:24:57.719485821 +0000
+++ slam.sh
@@ -65,7 +65,7 @@ set -e
 #######################################################################
 
 warm_option=""
-if [ "$1" == --load ]; then
+if [ "$1" = "--load" ]; then
     warm_option="--load"
     shift
 fi
