$NetBSD: patch-test_checker.sh,v 1.1 2013/02/20 21:37:13 wiz Exp $

Remove Linuxism in cut(1) call.

--- test/checker.sh.orig	2012-12-20 17:22:01.000000000 +0000
+++ test/checker.sh
@@ -67,7 +67,7 @@ echo "              *       Testing CLoo
 echo "              *-----------------------------------------------*/"
 for x in $TEST_FILES; do
     name=`echo $x | sed 's/%/ /g' | cut -d\  -f1`;
-    individual_options=`echo $x | sed 's/%/ /g' | cut -s -d\  -f2-`;
+    individual_options=`echo $x | sed 's/%/ /g' | cut -s -d\  -f2`;
     input="$srcdir/$name.$TEST_INPUT_EXTENSION";
     output="$srcdir/$name.$TEST_OUTPUT_EXTENSION";
     options="$individual_options $TEST_GLOBAL_OPTIONS";
