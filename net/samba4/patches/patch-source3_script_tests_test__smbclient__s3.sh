$NetBSD: patch-source3_script_tests_test__smbclient__s3.sh,v 1.2.12.1 2017/05/27 19:01:15 bsiegert Exp $

Fix unportable test(1) comparison operator.

--- source3/script/tests/test_smbclient_s3.sh.orig	2017-03-31 06:32:03.000000000 +0000
+++ source3/script/tests/test_smbclient_s3.sh
@@ -889,7 +889,7 @@ EOF
 
     echo "$out" | grep 'NT_STATUS'
     ret=$?
-    if [ $ret == 0 ] ; then
+    if [ $ret = 0 ] ; then
 	echo "$out"
 	echo "failed - NT_STATUS_XXXX listing \\manglenames_share\\FF4GBY~Q"
 	false
@@ -1027,7 +1027,7 @@ EOF
 
     echo "$out" | grep 'NT_STATUS'
     ret=$?
-    if [ $ret == 0 ] ; then
+    if [ $ret = 0 ] ; then
 	echo "$out"
 	echo "failed - NT_STATUS_XXXX listing \\widelinks_share\\dot"
 	false
