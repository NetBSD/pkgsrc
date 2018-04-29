$NetBSD: patch-js_src_tests_update-test262.sh,v 1.1 2018/04/29 05:11:00 wiz Exp $

Fix unportable test(1) operator.

--- js/src/tests/update-test262.sh.orig	2018-04-28 01:04:04.000000000 +0000
+++ js/src/tests/update-test262.sh
@@ -27,7 +27,7 @@ function usage()
 
 if [ $# -lt 1 ]; then
   usage
-elif [ $# -eq 1 -o "$2" == "clone" ]; then
+elif [ $# -eq 1 -o "$2" = "clone" ]; then
   # Beware!  'copy' support requires that the clone performed here *never* be
   # altered.  If it were altered, those changes wouldn't appear in the final
   # set of changes as determined by the 'copy' path below.
@@ -47,7 +47,7 @@ elif [ $# -eq 1 -o "$2" == "clone" ]; th
 
   echo "Feel free to get some coffee - this could take a few minutes..."
   hg clone $1 ${tmp_dir}
-elif [ "$2" == "copy" ]; then
+elif [ "$2" = "copy" ]; then
   echo "Copying directly from $1; be sure this repository is updated to tip"\!
   tmp_dir="$1"
 else
